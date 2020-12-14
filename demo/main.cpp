//
// Created by hacker on 12.12.2020.
//
#include "Filesystem.hpp"
#include <iostream>
//int argc, char** argv
int main(int argc, char** argv) {
    std::string path = "";
    if (argc == 1)
        path = ".";
    else if (argc == 2) {
        path = argv[1];
    } else {
        std::cout << "Error! Incorrect argument count" << std::endl;
        return 0;
    }
    Filesystem test(path);
    std::cout<<test;
    return 0;
}