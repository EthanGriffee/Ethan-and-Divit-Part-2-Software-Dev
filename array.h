#pragma once

#include "object.h"
#include "string.h"


// Represents a dynamically sized array
class Array : public Object{
    public:

        // initializes an empty array with a size of 0 and a max size of 2
        Array(){

        }

        // initializes an empty array with a size of 0 and a max size of max_size
        Array(size_t max_size){

        }

        // return the object at the index, throws an error if the index > size
        virtual Object* get(size_t index){

        }

        //  sets the element at index i to the new object, throws an error if  
        // i >= size
        virtual void set(size_t i, Object* obj) {

        }

        // deletes the contents of the array
        virtual void clear() {

        }

        // adds obj to the end of the Array, increases the size of the array, 
        // and increases the max size if necessary
        virtual void push(Object* obj) {

        }

        // returns the first index of a given object, or -1 if the array does not contrain the object
        virtual size_t indexOf(Object* obj) {

        }

        // returns the first index of a given object starting at index i, or -1 if the array does not 
        // contrain the object after index i
        virtual size_t indexOf(Object* obj, size_t i) {

        }

        // returns an array with elements of this array combined with elements of other
        virtual Array* concat(Array* other) {
            
        }

        // returns if this array has the same values at the other array
        virtual bool equals(Object* other) {

        }

        // returns the hash of the array
        virtual size_t hash() {

        }

        // returns the size of the array
        virtual size_t size() {

        }


        // deletes the array
        virtual ~Array() {

        }
};

/**
 * Incomplete implementation of StringArray. The push and set
 * methods would be overridden to include checks for Strings.
 **/
class StringArray : public Array {

    public:


        StringArray() : Array() {

        }

};

/**
 * Incomplete implementation of BoolArray. The push and set
 * methods would be overridden to include checks for BoolObjs. 
 **/
class BoolArray : public Array {
    public:

        BoolArray() : Array() {

        }

};

/**
 * Incomplete implementation of IntArray. The push and set
 * methods would be overridden to include checks for IntObj. 
 **/
class IntArray : public Array {

};


/**
 * Incomplete implementation of FloatArray. The push and set
 * methods would be overridden to include checks for FloatObj. 
 **/
class FloatArray : public Array {

};