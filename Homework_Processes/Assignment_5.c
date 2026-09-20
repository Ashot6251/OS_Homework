#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: %d\n", getpid());
        exit(0);
    } else {
        printf("Parent: %d\n", getpid());
        // wait(NULL); // To prevent zombie process.
        sleep(20);
    }

    return 0;
}
