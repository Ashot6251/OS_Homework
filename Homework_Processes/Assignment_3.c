#include <stdio.h>
#include <stdlib.h>

void bye1(void) { printf("bye1\n"); exit(0); }
void bye2(void) { printf("bye2\n"); }

int main() {
    
    atexit(bye1);
    atexit(bye2);

    //exit(0);

    //return 0;
}

