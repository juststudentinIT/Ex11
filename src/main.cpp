// Copyright 2021 FOM
#include "train.h"

int main() {
    Train test_train;
    test_train.set_lenght(23);
    test_train.Add_cage();
    test_train.print();
    std::cout << test_train.search_for_train_length() << std::endl;
    return 0;
}
