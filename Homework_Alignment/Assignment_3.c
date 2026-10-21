#include <stdio.h>

struct UnpackedStruct {
    char a;
    int b;
    double c;
};

#pragma pack(push, 1)
struct PackedStruct1 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct PackedStruct2 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

int main(void) {
    struct UnpackedStruct s_unpacked;
    struct PackedStruct1 s_pack1;
    struct PackedStruct2 s_pack2;

    printf("Without #pragma pack:\n");
    printf("Total Struct Size: %zu bytes\n", sizeof(s_unpacked));
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(s_unpacked.a), (void*)&s_unpacked.a);
    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(s_unpacked.b), (void*)&s_unpacked.b);
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(s_unpacked.c), (void*)&s_unpacked.c);

    printf("\nWith #pragma pack(1)\n");
    printf("Total Struct Size: %zu bytes\n", sizeof(s_pack1));
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(s_pack1.a), (void*)&s_pack1.a);
    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(s_pack1.b), (void*)&s_pack1.b);
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(s_pack1.c), (void*)&s_pack1.c);

    printf("\nWith #pragma pack(2)\n");
    printf("Total Struct Size: %zu bytes\n", sizeof(s_pack2));
    printf("char   | Size: %zu byte   | Address: %p\n", sizeof(s_pack2.a), (void*)&s_pack2.a);
    printf("int    | Size: %zu bytes  | Address: %p\n", sizeof(s_pack2.b), (void*)&s_pack2.b);
    printf("double | Size: %zu bytes  | Address: %p\n", sizeof(s_pack2.c), (void*)&s_pack2.c);

    return 0;
}