Assignment 0:

Source code:
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

The program calls fork() three times sequentially. At each fork(), it checks if the return value is 0 to separate the child process execution from the parent, printing each process's PID and its parent's PID.

Each fork() duplicates every process running at that moment, doubling the number of processes each time and resulting in 8 total running processes from 3 calls.

Assignment 1:

Source code:
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    if (fork() == 0) {
        execl("/bin/ls", "ls", NULL);
    }else {
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}

The program creates a single child process using fork(). The child calls execl() to run /bin/ls and list the directory contents, while the parent calls wait(NULL) to pause until the child finishes before printing "Parent process done".

execl() completely replaces the child's program code with the ls program, and wait(NULL) guarantees that the parent output always prints after the child finishes.

Assignment 2:

Source code:
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

The program uses fork() to create a child process that runs ls via execl(), and the parent calls wait(NULL) for it to finish. Then, the parent uses fork() again to create a second child process that runs date, waits for it to finish, and finally prints "Parent process done". Calling wait(NULL) after each child creation forces the operations to execute one after another.

Assignment 3:

Source code:
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    if (fork() == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", NULL);
    }else {
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}

The program creates a child process using fork(), which calls execl() to execute /bin/echo with the string argument "Hello from the child process". The parent process waits for the child to execute before printing its own completion message. Arguments are passed into execl() as comma-separated string parameters, ending with a NULL pointer to signal the end of the argument list.

Assignment 4:
	
Source code:
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

The program forks a child process that uses execl() to run /usr/bin/grep, searching for the term "main" inside the test.txt file. The parent process waits for grep to output the results to the screen before printing "Parent process completed".
