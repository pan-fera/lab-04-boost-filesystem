// Copyright 2020 Your Name <your_email>

#include <finance_analyzer.hpp>
#include <sstream>

finance_analyzer::finance_analyzer(){}

std::ostream& finance_analyzer::print_info(std::ostream& out)
{
  /*
  for (auto const &component: filesystem::directory_iterator(path_to_dir))
  {
    if (filesystem::is_directory(component)) out << "folder: ";
    if (filesystem::is_symlink(component)) out << "symlink: ";
    if (filesystem::is_regular_file(component)) out << "file: ";
    out << component.path().filename().string() << std::endl;
  }
  return out;
   */
  for (const auto &acc : accounts)
  {
    out << *acc;
  }
  return out << std::endl << "This will be updated soon" << std::endl;
}
std::ostream& operator<<(std::ostream& out, finance_analyzer& fin)
{
  return fin.print_info(out);
}
void finance_analyzer::analyze(const filesystem::path& path)
{
  path_to_dir = path;
  for (const auto &component: filesystem::directory_iterator(path_to_dir))
  {
    auto new_account = new account;
    new_account->set_broker("ib");
    new_account->add_filename(component.path().filename().string());
    accounts.push_back(new_account);
  }
}
finance_analyzer::~finance_analyzer(){
  for (auto & acc : accounts){
    delete acc;
  }
}
