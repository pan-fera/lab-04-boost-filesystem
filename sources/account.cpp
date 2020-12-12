//
// Created by nickmint on 12/13/20.
//

#include "account.hpp"
const std::string& account::get_broker() const { return broker; }
void account::set_broker(const std::string& b) { broker = b; }
const std::vector<std::string>& account::get_filenames() const {
  return filenames;
}
void account::add_filename(const std::string& f) {
  filenames.push_back(f);
}
std::ostream& operator<<(std::ostream& out, account& acc) {
  acc.print_info(out);
  return out;
}
std::ostream& account::print_info(std::ostream& out) {
  for (const auto &filename : filenames)
  {
    out << broker << ":  " << filename << std::endl;
  }
  out << "End of account" << std::endl;
  return out;
}
