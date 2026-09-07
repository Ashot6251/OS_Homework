#include <stdio.h>

int main() {

    char str[] = "Hello";
    char *ptr = &str[0];
    int count = 0;
    
    printf("str:");
    while (*ptr) {
        printf("%c", *ptr);
        count++;
        ptr++;
    }

    printf("\nThe length of the string: %d\n", count);

    return 0;
}
