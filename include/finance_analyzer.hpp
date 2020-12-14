//
// Created by nickmint on 12/11/20.
//

#ifndef TEMPLATE_FINANCE_ANALYZER_HPP
#define TEMPLATE_FINANCE_ANALYZER_HPP
#include <vector>

#include "account.hpp"
#include "boost/filesystem.hpp"

using namespace boost;
class finance_analyzer {
 public:
  explicit finance_analyzer();
  void analyze(const filesystem::path& path);
  std::ostream& print_info(std::ostream& out);
  std::string filename_number(const std::string& filename) const;
  void parse_component(const filesystem::path& p,
                       const std::string& current_broker);
  bool filename_is_valid(const filesystem::path& path_to_file);
  friend std::ostream& operator<<(std::ostream &out, finance_analyzer& fin);
  ~finance_analyzer();

 private:
  filesystem::path path_to_ftp;
  std::vector<account*> accounts;
};
#endif  // TEMPLATE_FINANCE_ANALYZER_HPP
