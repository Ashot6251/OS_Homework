#include <stdio.h>

struct struct1 {
    char a;
    int b;
    double c;
};

struct struct2 {
    char a;
    double c;
    int b;
};

struct struct3 {
    double c;
    int b;
    char a;
};

int main() {
    struct struct1 s1;
    struct struct2 s2;
    struct struct3 s3;

    printf("Original struct size: %zu bytes\n", sizeof(s1));
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(s1.a), (void*)&s1.a);
    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(s1.b), (void*)&s1.b);
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(s1.c), (void*)&s1.c);

    printf("\nReordered struct 1 size: %zu bytes\n", sizeof(s2));
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(s2.a), (void*)&s2.a);
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(s2.c), (void*)&s2.c);
    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(s2.b), (void*)&s2.b);

    printf("\nReordered struct 2 size: %zu bytes\n", sizeof(s3));
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(s3.c), (void*)&s3.c);
    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(s3.b), (void*)&s3.b);
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(s3.a), (void*)&s3.a);

    return 0;
}