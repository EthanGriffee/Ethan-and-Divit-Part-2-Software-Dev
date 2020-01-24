#pragma once

#include "object.h"

class Array : public Object{
    public:
        Object** contents;
        size_t length;

        Array(size_t length){

        }

        // return the object at the index
        Object* get(size_t index){

        }

        //  sets the element at index i to the new object
        void set(size_t i, Object* obj) {

        }

        // deletes the contents of the array
        void clear() {

        }

        // returns the first index of a given object, or -1 if the array does not contrain the object
        size_t indexOf(Object* obj) {

        }

        // returns the first index of a given object starting at index i, or -1 if the array does not 
        // contrain the object after index i
        size_t indexOf(Object* obj, size_t i) {

        }

        // returns an array with elements of this array combined with elements of other
        Array* concat(Array* other) {
            
        }

        // returns if this array has the same values at the other array
        Array* equals(Object* other) {

        }

        // returns the hash of the array
        size_t hash() {

        }

        // returns the size of the array
        size_t size() {

        }


        // deletes the array
        virtual ~Array() {

        }
};