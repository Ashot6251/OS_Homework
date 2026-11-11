#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char line[1024];
    char out[1100];

    int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    ssize_t n = read(0, line, sizeof line);
    if (n < 0) {
        perror("read");
        return 1;
    }

    int len = snprintf(out, sizeof out, "PID=%d: ", getpid());
    memcpy(out + len, line, n);
    len += n;

    if (out[len - 1] != '\n')
        out[len++] = '\n';

    write(fd, out, len);

    /* O_APPEND moves the offset to the end of the file before each write.
       After the write, the offset is at the new end of the file.
       SEEK_CUR returns this offset, which is the file size.
       The file gets bigger with every run, so the offset keeps growing. */
    printf("Final offset: %ld\n", (long)lseek(fd, 0, SEEK_CUR));

    close(fd);
    return 0;
}