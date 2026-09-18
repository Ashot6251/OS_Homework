#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
    if (fork() == 0)
        printf("Child: %d (PPID: %d)\n", getpid(), getppid());
    else
        printf("Parent: %d\n", getpid());

    if (fork() == 0)
        printf("Child: %d (PPID: %d)\n", getpid(), getppid());
    else
        printf("Parent: %d\n", getpid());

    if (fork() == 0)
        printf("Child: %d (PPID: %d)\n", getpid(), getppid());
    else
        printf("Parent: %d\n", getpid());

    return 0;
}
