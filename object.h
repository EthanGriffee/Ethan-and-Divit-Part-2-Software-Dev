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