Array.h is a Object that represents an arraylist. The max size of the Array can be passed through
the constructor, or it can be initiallized with a default max_size.

The push method increases the size of the arrray, and if necessary increases the max_size of the
array and adds the element to the end of the array.

You can get the contents of a specific index with the "get" method.

The clear method sets the contents to be a pointer of null pointers.

Index of returns the next index after the input size_t where the given object equals the input object,
or the first index if a size_t is not input.

Concat returns a new array with elements of this array followed by elements of another array.

Equals returns true if this array has the same values at the other array.

Returns the addition of every Object hashed in the array.

Size returns the size of the array.
