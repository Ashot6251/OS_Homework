#include <stdio.h>

int main() {

    int a = 10;
    int *b = &a;
    int **c = &b;

    printf("Value using the pointer: %d\n", *b);
    printf("Value using the double-pointer: %d\n", **c);

    return 0;
}
