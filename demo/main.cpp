#include <boost/filesystem.hpp>
#include <finance_analyzer.hpp>
#include <iostream>

using namespace boost;
int main()
{
  //filesystem::path path = filesystem::current_path();
  filesystem::path path = "../FTP";
  finance_analyzer example;
  example.analyze(path);
  std::cout << example << std::endl;
  return 0;
}