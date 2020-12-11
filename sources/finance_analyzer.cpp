// Copyright 2020 Your Name <your_email>

//#include <header.hpp>

#include <finance_analyzer.hpp>
#include <sstream>

finance_analyzer::finance_analyzer(const filesystem::path& path)
    : path_to_dir(path)
{}
std::ostream& finance_analyzer::print_info(std::ostream& out)
{
  for (auto const &component: filesystem::directory_iterator(path_to_dir))
  {
    if (filesystem::is_directory(component)) out << "folder: ";
    if (filesystem::is_symlink(component)) out << "symlink: ";
    if (filesystem::is_regular_file(component)) out << "file: ";
    out << component.path().filename().string() << std::endl;
  }
  return out;
}
std::ostream& operator<<(std::ostream& out, finance_analyzer& fin)
{
  return fin.print_info(out);
}
