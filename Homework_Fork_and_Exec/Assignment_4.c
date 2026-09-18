#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    if (fork() == 0) {
        execl("/usr/bin/grep", "grep", "main", "test.txt", NULL);
    }else {
        wait(NULL);
        printf("Parent process completed\n");
    }

    return 0;
}
