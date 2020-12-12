//
// Created by nickmint on 12/13/20.
//

#ifndef TEMPLATE_ACCOUNT_HPP
#define TEMPLATE_ACCOUNT_HPP
#include <iostream>
#include <vector>

class account
{
 public:
  const std::vector<std::string>& get_filenames() const;
  void add_filename(const std::string& f);
  const std::string& get_broker() const;
  void set_broker(const std::string& broker);
  std::ostream& print_info(std::ostream& out);
  friend std::ostream& operator<<(std::ostream &out, account& acc);

 private:
  std::string broker;
  std::vector<std::string> filenames;
};

#endif  // TEMPLATE_ACCOUNT_HPP
