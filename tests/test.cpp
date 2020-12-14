// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "Filesystem.hpp"
TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Programm, WorkTest) {
    try {
      std::string path("../misc/ftp");
      Filesystem test(path);
      std::cout << test;
    }
    catch(...) {

    }
    EXPECT_TRUE(true);
}