#include <boost/filesystem.hpp>
#include <finance_analyzer.hpp>
#include <iostream>

using namespace boost;
int main()
{
  filesystem::path path = filesystem::current_path();
  finance_analyzer analyse(path);
  std::cout << std::endl << analyse << std::endl;
  return 0;
}