// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "Filesystem.hpp"
TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Programm, WorkTest) {
    std::cout<<boost::filesystem::current_path()<<std::endl;
    Filesystem test("../misc/ftp");
    std::cout<<test;
    EXPECT_TRUE(true);
}