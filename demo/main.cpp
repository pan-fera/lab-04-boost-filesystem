#include <boost/filesystem.hpp>
#include <finance_analyzer.hpp>
#include <iostream>

using namespace boost;
int main()
{
  //filesystem::path path = filesystem::current_path();
  filesystem::path path = "../misc/ftp";
  finance_analyzer example;
  try {
    example.analyze(path);
    std::cout << example << std::endl;
  } catch (const std::string& error) {
    std::cout << error;
  }
  return 0;
}