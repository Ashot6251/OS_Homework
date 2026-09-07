#include <stdio.h>

int main() {
    
    int arr[5] = {2, 5, 7, 10, 11};
    int *ptr = &arr[0];
    
    // Traversing the array and printing the elements
 
    printf("Initial values of the array\n");
    for (int i = 1; i < 5; i++) {
        printf("Value at index %d: %d\n", i, *(ptr + i));
    }
    
    // Modifying the values of the array elements

    printf("\nModified values of the array\n");
    for (int i = 1; i < 5; i++) {
        *(ptr + i) *= 2;
 
        printf("Value at index %d: %d\n", i, *(ptr + i));
    }   
    
    return 0;
}
