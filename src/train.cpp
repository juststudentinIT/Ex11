//Copyright 2021 FOM
#include "train.h"
#include <iostream>
#include <cstdlib>

void Cage::on() {
	light = true;
}
void Cage::off() {
	light = false;
}
bool Cage::get() const {
	return light;
}
Train::Train() {
	this->first = nullptr;
	this->last = nullptr;
}
void Train::Add_cage() {
    int i = 0;
    while (i < lenght) {
        Cage* cage_ = new Cage;
        unsigned int seed = std::time(NULL);
        int state = rand_r(&seed) % 100;
        if ((state / 2) == 0) {
            cage_->on();
        } else {
            cage_->off();
        }
        if ((this->first == nullptr) && (this->last == nullptr)) {
            this->first = cage_;
            this->last = cage_;
        }
        if (this->first != this->last) {
            cage_->prev = this->last;
            this->last->next = cage_;
            this->last = cage_;
            this->first->prev = this->last;
            this->last->next = this->first;
        } else {
            this->last = cage_;
            this->first->next = cage_;
            this->first->prev = cage_;
            this->last->next = this->first;
            this->last->prev = this->first;
        }
        i++;
    }
}
void Train::print() {
    Cage* ptr = this->first;
    int i = 1;
    while (ptr != this->last) {
        if (ptr->get()) {
            std::cout << "- Cage - " << i << " - state - true "
                << std::endl;
        }
        else {
            std::cout << "- Cage - " << i << " - state - false"
                << std::endl;
        }
        i++;
        ptr = ptr->next;
    }
    if (ptr->get()) {
        std::cout << "- Cage - " << i << " - state - true "
            << std::endl;
    }
    else {
        std::cout << "- Cage - " << i << " - state - false"
            << std::endl;
    }
}
int Train::search_for_train_length() {
    Cage* ptr_cage = this->first;
    ptr_cage->on();
    int count = 1;
    while (true) {
        for (int i = 0; i < count; i++) {
            ptr_cage = ptr_cage->next;
            ptr_cage->off();
        }
        for (int i = 0; i < count; i++) {
            ptr_cage = ptr_cage->prev;
        }
        if (ptr_cage->get() == false) break;
        count++;
    }
    return count;
}
void Train::set_lenght(int lenght) {
	this->lenght = lenght;
}
int Train::get_lenght() {
	return lenght;
}
