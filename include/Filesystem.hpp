//
// Created by hacker on 12.12.2020.
//

#ifndef TEMPLATE_FILESYSTEM_HPP
#define TEMPLATE_FILESYSTEM_HPP
#include <boost/filesystem.hpp>
#include <vector>
class Filesystem {
public:
    //Filesystem();
    Filesystem(std::string path_to_file);
    void all_path(boost::filesystem::path p, std::ostream &out);
    bool handler(boost::filesystem::path p, std::ostream &out);
    bool check_fiilename(boost::filesystem::path p);
    std::string what_account(std::string p);
    std::string what_data(std::string p);
    std::string what_broker(boost::filesystem::path p);
    void show_account(std::ostream &out);
    void insert_element(std::string account, std::string data, std::string broker);
    friend std::ostream& operator<<(std::ostream &out, Filesystem& file_system);
private:
    boost::filesystem::path _path_to_ftp;
    std::vector<std::string> _broker;
    std::vector<std::string> _account;
    std::vector<long int> _files;
    std::vector<long int> _lastdate;

    const size_t len_namefile = 29;
};

#endif  // TEMPLATE_FILESYSTEM_HPP
