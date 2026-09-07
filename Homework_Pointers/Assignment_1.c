#include <stdio.h>

int main() {

    int a = 10;
    int *ptr = &a;
    
    printf("Adress of a: %p \nAdress of a: %p\n", &a, ptr);
    
     
    printf("Value of a: %d\n", a); 
    *ptr = 20;
    printf("Modified value of a: %d\n", a); 

    return 0;
}
