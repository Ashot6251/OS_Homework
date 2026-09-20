Assignment 1:

Source code:
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

Explanations and Observations:
The program creates a child process using fork(). Then the child and parent processes’ id are printed. The order is not guaranteed, as the parent process’ ID might get printed first and vise versa. The reason is because the parent process doesn’t wait until the child process is finished, so it can continue.

Assignment 2:

Source code:
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

Explanations and Observations:
The program creates two child processes using two fork() calls. The printing part of the process is not deterministic, so the order may vary. The important thing is that the exit status of child 2 is always printed first, as the parent explicitly waits for it before continuing onward. Explicit waiting is done by waitpid() by mentioning the pid and status of the second child. The wait() keeps the parent waiting until the rest of the child processes are finished. Finally, the wait functions return the PIDs of processes. The exit status is then assigned to &status, which can then be printed by WEXISTSTATUS() function. 

Assignment 3:

Source code:
#include <stdio.h>
#include <stdlib.h>

void bye1(void) { printf("bye1\n"); }
void bye2(void) { printf("bye2\n"); }

int main() {

    atexit(bye1);
    atexit(bye2);

    exit(0);

    return 0;
}

Explanations and Observations:
atexit() function executes when the program terminates normally, and in this case it does so via the exit(0) function. The atexit() function works with the LIFO principle, meaning the last function registered is executed first; hence, in this version of the code, bye2 is printed before bye1, even though the bye1 function was registered first. Another observation can be made that even without an exit(0) call, the program would still produce the exact same result via the return 0 call. Printing exit(0) in between the function calls would only print bye1, and exiting before the functions are even called would result in nothing being printed. Adding the exit calls inside the bye1 and bye2 functions results in both bye2 and bye1 being printed, although I found that it might result in undefined behaviour.

Assignment 4:

Source code:
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

Explanations and Observations:
Similar to the second assignment, two forks are called, creating two child processes. Then, the child and parent process IDs are printed, after which the parent process waits via the waitpid() function for the first child to finish. Then the status 1 is checked to determine whether the process exited normally or not. In the case of the first child, exit(0) was called, so it exited normally, resulting in it being printed as such. The same thing happens with the second child process, but in this case the process exitted via exit(1), so after the check it is printed that child process 2 exited with error. There are a few things worth mentioning, like the return value of WEXITSTATUS() is 0 when the process exited normally, and is any integer value between 1 and 255 if it exited with an error. Finally, WEFEXITED() returns true (any non-zero value) if the process was terminated normally and false if the process was terminated abnormally (e.g killed or crashed).

Assignment 5:

Source code:
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

Explanations and Observations:
Firstly, fork() is called, creating a child process. The child process finishes executing, but its status is not reaped by the parent (as it is sleeping), resulting in a zombie process during those 20 seconds. When the parent process finishes sleeping and terminates, the operating system automatically cleans up the zombie child. To prevent the zombie process, wait(NULL) is called, meaning the parent process waits until the child process finishes and is reaped before the parent goes to sleep.

