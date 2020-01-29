#pragma once

#include <stdlib.h>

class Object {
    public:
        size_t  hash_;

        Object() { 
        }

        // returns true if it refers to the same memory address
        bool equals(Object *other){
            
        }

        // returns a hash of the object
        size_t hash() {

        }

        virtual ~Object() {

        }
};

// Wrapper for a Float
class FloatObj : public Object {
    public:

        // sets the value of f to input_f
        FloatObj(float input_f) {

        }

        // returns if other is a float that has the same f
        bool equals(Object *other){
            
        }

        // returns f
        float getFloat() {

        }
};

// Wrapper for a Boolean
class BoolObj : public Object {
    public:

        // sets the value of b to input_b
        BoolObj(bool input_b) {

        }

        // returns if other is a boolean that has the same b
        bool equals(Object *other){
            
        }

        // returns b
        bool getBool() {

        }
};

// Wrapper for a Integer
class IntObj : public Object{
    public:

        // sets the value of i to input_i
        IntObj(int input_i) {

        }

        // returns if other is a integer that has the same i
        bool equals(Object *other){
            
        }

        // returns i
        int getInt() {

        }
};