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

        // private method that increases the maximum size of the array by copying the contents
        virtual void _resize() {

        }

        // return the object at the index, exits with code 1 if the index > size
        virtual Object* get(size_t index){

        }

        //  sets the element at index i to the new object, exits with code 1  
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
        virtual int indexOf(Object* obj) {

        }

        // returns the first index of a given object starting at index i, or -1 if the array does not 
        // contrain the object after index i
        virtual int indexOf(Object* obj, size_t i) {

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
 * An Array whose contents will only be Strings
 **/
class StringArray : public Array {

    public:
        StringArray() : Array() {

        }

        // Checks if the given object is a String, and exits with code 1 if it is not.
        // Then pushes the obj to the end of the array
        virtual void push(Object* obj) {

        }


        //  Chceks if the given object is a String, and exits with code 1 if it is not.
        // Then sets index i in the array to obj
        virtual void set(size_t i, Object* obj) {

        }

};

/**
 * An Array whose contents will only be BoolObjs
 **/
class BoolArray : public Array {
    
    public:
        BoolArray() : Array() {

        }

        // Checks if the given object is a BoolObj, and exits with code 1 if it is not.
        // Then pushes the obj to the end of the array
        virtual void push(Object* obj) {

        }


        //  Chceks if the given object is a BoolObj, and exits with code 1  if it is not.
        // Then sets index i in the array to obj
        virtual void set(size_t i, Object* obj) {

        }

};

/**
 * An Array whose contents will only be IntObjs
 **/
class IntArray : public Array {

    public:
        IntArray() : Array() {

        }

        // Checks if the given object is a IntObj, and exits with code 1 if it is not.
        // Then pushes the obj to the end of the array
        virtual void push(Object* obj) {

        }


        //  Chceks if the given object is a IntObj, and exits with code 1 if it is not.
        // Then sets index i in the array to obj
        virtual void set(size_t i, Object* obj) {

        }

};


/**
 * An Array whose contents will only be FloatObjs
 **/
class FloatArray : public Array {

    public:
        FloatArray() : Array() {

        }

        // Checks if the given object is a FloatObj, and exits with code 1 if it is not.
        // Then pushes the obj to the end of the array
        virtual void push(Object* obj) {

        }


        //  Chceks if the given object is a FloatObj, and exits with code 1 if it is not.
        // Then sets index i in the array to obj
        virtual void set(size_t i, Object* obj) {

        }

};