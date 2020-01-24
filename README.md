

Array is an Object, that has a pointer of pointers called contents, that is initialized 
with the size input upon creation by the user. The length field is also set to this size.

The array is initialized with nullpointers, and indexes of the array can be set using the
"set" method.

You can get the contents of a specific index with the "get" method.

The clear method sets the contents to be a pointer of null pointers.

Index of returns the next index after the input size_t where the given object equals the input object,
or the first index if a size_t is not input.

Concat returns a new array with elements of this array followed by elements of another array.

Equals returns true if this array has the same values at the other array.

Returns the addition of every Object hashed in the array.

Size returns the size of the array.
