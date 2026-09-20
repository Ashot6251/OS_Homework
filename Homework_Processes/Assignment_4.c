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
        exit(1);
    }

    printf("Parent: %d\n", getpid());

    waitpid(pid1, &status1, 0);
    if (WIFEXITED(status1)) {
        printf("Exit status of Child_1: %d\n", WEXITSTATUS(status1));

        if (WEXITSTATUS(status1) == 0)
            printf("Child_1 exited normally.\n");
        else 
            printf("Child_1 exited with error.\n");
    }

    waitpid(pid2, &status2, 0);
    if (WIFEXITED(status2)) {
        printf("Exit status of Child_2: %d\n", WEXITSTATUS(status2));

        if (WEXITSTATUS(status2) == 0)
            printf("Child_2 exited normally.\n");
        else
            printf("Child_2 exited with error.\n");
    }

    return 0;
}
