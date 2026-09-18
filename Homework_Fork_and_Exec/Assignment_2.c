#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    if (fork() == 0) {
        execl("/bin/ls", "ls", NULL);
    }

    wait(NULL);

    if (fork() == 0) {
        execl("/bin/date", "date", NULL);
    }

    wait(NULL);
    printf("Parent process done\n");

    return 0;
}
