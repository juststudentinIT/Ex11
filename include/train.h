//Copyright 2021 FOM
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Cage {
 private:
    bool light;
 public:
    Cage* next;
    Cage* prev;
    Cage() : light(false), next(nullptr), prev(nullptr) {}
    void on();
    void off();
    bool get() const;
};
class Train {
 private:
    Cage* first;
    Cage* last;
    int lenght;
 public:
    Train();
    void Add_cage();
    void print();
    int search_for_train_length();
    void set_lenght(int lenght);
    int get_lenght();
};
#endif // INCLUDE_TRAIN_H_
