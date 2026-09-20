#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    if(fork() == 0) {
        printf("Child: %d\n", getpid());
        exit(0);
    }else
        printf("Parent: %d\n", getpid());

    return 0;
}
