#include <stdio.h>

int main(void) {
    int i;
    char c;
    double d;
    short s;

    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(i), (void*)&i);
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(c), (void*)&c);
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(d), (void*)&d);
    printf("short  | Size: %zu bytes  | Address: %p\n", sizeof(s), (void*)&s);

    return 0;
}