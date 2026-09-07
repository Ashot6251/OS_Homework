#include <stdio.h>

void swap(int *a, int *b) {

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    
    int a = 10;
    int b = 20;
    

    printf("Before swap:\na: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("After swap:\na: %d, b: %d\n", a, b);

    return 0;
}
