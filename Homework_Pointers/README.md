Assignment 1:

The program declares an integer variable a initialized to 10, and a pointer ptr initialized with &a. It prints the memory address using both &a and ptr, modifies a by * ptr = 20, and prints the updated value.

* ptr changes a because both refer to the same physical memory location.

Assignment 2:

An integer array arr of 5 elements is declared alongside the pointer ptr = arr. The program iterates through the array using * (ptr + i) to print the elements. It also doubles each value and prints the result using both pointer notation (in the same loop as updating the values) and array indexing arr[i].

Adding i to ptr advances the address by 4 bytes (because of the size of int), resulting in the next value's memory address.

Assignment 3:

A function swap(int * a, int * b) takes two integer pointers as parameters and swaps their referenced values by XORing with each other. In the main function, the swap() function is called with &a and &b as arguments.

To modify the values, addresses must be passed instead of value copies for it to work.

Assignment 4:

An integer a is declared alongside * b pointer and * * c double pointer. Then the program prints the value of a by both * b and * * c.

Pointers also have their addresses in memory, and a double pointer works by first dereferencing the double pointer and then dereferencing the pointer, yielding the value stored in a.

Assignment 5:

The program declares a character array str and pointer ptr to the first address of str. Moreover, a counter for the length of the string is initialized to 0. while (* ptr) evaluates the character at the address ptr is pointing to. Any non-zero value counts as true, so the loop keeps running until the characters end. For each character, the program prints it and increments the counter for the length. Finally, it prints the length.

ptr++ advances the memory address by exactly 1 byte (because of the size of char).
