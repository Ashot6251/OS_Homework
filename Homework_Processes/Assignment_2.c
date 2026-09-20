#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    pid_t pid1, pid2;
    int status1, status2;

    pid1 = fork();

    if(pid1 == 0) {
        printf("Child_1: %d\n", getpid());
        exit(0);
    }

    pid2 = fork();

    if(pid2 == 0) {
        printf("Child_2: %d\n", getpid());
        exit(0);
    }

    printf("Parent: %d\n", getpid());
    
    printf("Exist status of Child_2: %d\n", waitpid(pid2, &status2, 0));
    
    printf("Exist status of Child_1: %d\n", wait(&status1));
    
    return 0;
}
