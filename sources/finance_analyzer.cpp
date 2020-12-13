// Copyright 2020 Your Name <your_email>

#include <finance_analyzer.hpp>
#include <sstream>

finance_analyzer::finance_analyzer(){}

std::ostream& finance_analyzer::print_info(std::ostream& out)
{
  /*
  for (auto const &component: filesystem::directory_iterator(path_to_ftp))
  {
    if (filesystem::is_directory(component)) out << "folder: ";
    if (filesystem::is_symlink(component)) out << "symlink: ";
    if (filesystem::is_regular_file(component)) out << "file: ";
    out << component.path().filename().string() << std::endl;
  }*/
  return out;
}

void finance_analyzer::analyze(const filesystem::path& path)
{
  path_to_ftp = path;
  for (const auto &broker_directory : filesystem::directory_iterator(path_to_ftp))
  {
    if (!filesystem::is_directory(broker_directory)) continue;
    std::string current_broker = broker_directory.path().filename().string();
    for (const auto &component : filesystem::directory_iterator(broker_directory))
    {
      // let all components be regular files with correct names
      std::string current_filename = component.path().filename().string();
      account* current_account = nullptr;
      for (auto acc : accounts )
      {
        if (acc->get_number() == filename_number(current_filename))
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
        //current_account->set_number("pls");
        current_account->add_filename(current_filename);
        accounts.push_back(current_account);
      }
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
std::string finance_analyzer::filename_number(const std::string& filename) const {
  std::string number_str = filename.substr(filename.find('_') + 1, filename.size() - 1);
  number_str = number_str.substr(0, number_str.find('_'));
  return number_str;
}
