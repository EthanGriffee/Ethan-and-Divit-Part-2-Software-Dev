#pragma once

#include <string.h> //also called cstring
#include "object.h"

// String class
class String : public Object {
    public:
        char *str_;
        size_t size_;

        String() : Object() {
        }

        String(const char* str) : Object() {
        }

        // returns the length of the string
        size_t size() {
        }

        // hashes the string
        size_t hash() {
        }

        // returns a new string combining this string with s
        String* concat(String* s) {
        }

        // returns positive number if the ascii values > ascii values of s
        int compare(String* s) {
        }

        // returns true if other is a string * and the characters in str_ are the 
        // same as the characters in other->str_
        bool equals(Object *other){

        }

        virtual ~String() {
        }
};