#pragma once

#include<iostream>
#include "string.h"


void print(const char *str) {
    std::cout << str;
}

void print(int i) {
    std::cout << i;
}

void print(size_t s) {
    std::cout << s;
}

void print(double d) {
    std::cout << d;
}

void println(int i) {
    std::cout << i << "\n";
}
void println(size_t i) {
    std::cout << i << "\n";
}

void println(const char *str) {
    std::cout << str << "\n";
}

void println(String *str) {
    print(str->str_);
    print("\n");
}

/** 
void print(Hashmap h) {
    ...
}
*/