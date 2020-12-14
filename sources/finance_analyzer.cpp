// Copyright 2020 Your Name <your_email>

#include <finance_analyzer.hpp>
#include <sstream>

finance_analyzer::finance_analyzer(){}

std::ostream& finance_analyzer::print_info(std::ostream& out)
{
  return out;
}

void finance_analyzer::analyze(const fs::path& path)
{
  path_to_ftp = path;
  if (!fs::exists(path_to_ftp))
    throw std::string ("Error: no such directory");
  if (!fs::is_directory(path_to_ftp))
    throw std::string ("Error: given argument is not a directory");
  for (const auto &broker_directory : fs::directory_iterator(path_to_ftp))
  {
    if (!fs::is_directory(broker_directory)) continue;
    std::string current_broker = broker_directory.path().filename().string();
    if (current_broker == "docs") continue;
    for (const auto &iter : fs::directory_iterator(broker_directory))
    {
      parse_component(iter.path(), current_broker);
    }
  }
  for (auto acc : accounts ) acc->find_last_date();
}

finance_analyzer::~finance_analyzer(){
  for (auto & acc : accounts){
    delete acc;
  }
}

std::ostream& operator<<(std::ostream& out, finance_analyzer& fin)
{
  out << "All files data" << std::endl;
  for (const auto &acc : fin.accounts)
  {
    const auto& filenames = acc->get_filenames();
    for (const auto& filename : filenames)
    {
      out << acc->get_broker() << " " << filename << std::endl;
    }
  }
  out << std::endl << "All accounts data" << std::endl;
  for (const auto &acc : fin.accounts) out << *acc;
  return out;
  //return fin.print_info(out);
}

std::string finance_analyzer::filename_number(const std::string& filename) const
{
  std::string number_str = filename.substr(filename.find('_') + 1,
                                           filename.size() - 1);
  number_str = number_str.substr(0, number_str.find('_'));
  return number_str;
}

void finance_analyzer::parse_component(
    const fs::path& p,
    const std::string& current_broker)
{
  // let all files have correct names
  fs::path component_path = p;
  if (fs::is_symlink(p)) component_path = fs::read_symlink(p);
  if (!fs::exists(component_path)) return;
  if (fs::is_regular_file(component_path))
  {
    if (!filename_is_valid(component_path)) return;
    std::string current_filename = component_path.filename().string();
    account* current_account = nullptr;
    for (auto acc : accounts )
    {
      if ((acc->get_number() == filename_number(current_filename))&&
          (acc->get_broker() == current_broker))
      {
        current_account = acc;
        current_account->add_filename(current_filename);
        break;
      }
    }
    if (!current_account)
    {
      current_account = new account;
      current_account->set_broker(current_broker);
      current_account->set_number(filename_number(current_filename));
      current_account->add_filename(current_filename);
      accounts.push_back(current_account);
    }
  } else if (fs::is_directory(component_path)) {
    for (const auto& sub_component : fs::directory_iterator(component_path))
      parse_component(sub_component.path(), current_broker);
  }
}

bool finance_analyzer::filename_is_valid(const fs::path& path_to_file) {
  if (path_to_file.extension() != ".txt") return false;
  else if (path_to_file.stem().has_extension())
    return false;
  std::string filename = path_to_file.stem().filename().string();
  size_t underscore_pos = filename.find('_');
  std::string tmp;
  if (underscore_pos) tmp = filename.substr(0, underscore_pos);
  else return false;
  if (tmp != "balance") return false;
  filename = filename.substr(underscore_pos + 1, filename.size());
  underscore_pos = filename.find('_');
  if (!underscore_pos) return false;
  else {
    tmp = filename.substr(0, underscore_pos);
    //std::cout << tmp << "///" ;
    if (tmp.size() != 8) return false;
    if (tmp.find_first_not_of("0123456789") != std::string::npos) return false;
    tmp = filename.substr( underscore_pos + 1, filename.size());
    if (tmp.size() != 8) return false;
    //std::cout << tmp << std::endl;
    if (tmp.find_first_not_of("0123456789") != std::string::npos) return false;
  }
  return true;
}
