#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char buf[64];

    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    write(fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
    close(fd);

    fd = open("data.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Size before: %ld\n", (long)lseek(fd, 0, SEEK_END));

    ftruncate(fd, 10);
    printf("Size after: %ld\n", (long)lseek(fd, 0, SEEK_END));

    lseek(fd, 0, SEEK_SET);
    ssize_t n = read(fd, buf, sizeof buf);
    write(1, buf, n);
    write(1, "\n", 1);

    close(fd);
    return 0;
}