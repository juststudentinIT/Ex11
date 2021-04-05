// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include <ctime>
#include "train.h"

TEST(Train_Test, test1) {
    Train train_1;
    train_1.set_lenght(20);
    EXPECT_EQ(20, train_1.get_lenght());
}

TEST(Train_Test, test2) {
    Train train_2;
    train_2.set_lenght(120);
    train_2.Add_cage();
    EXPECT_EQ(120, train_2.search_for_train_length());
}

TEST(Train_Test, test3) {
    Train train_3;
    int size = rand() % 100 + 3;
    train_3.set_lenght(size);
    train_3.Add_cage();
    EXPECT_EQ(size, train_3.search_for_train_length());
}
