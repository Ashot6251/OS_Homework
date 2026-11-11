#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char line[16];
    char buf[256];
    char c;
    int newlines = 0;
    off_t pos = 0;
    off_t start = 0;

    int fd = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    for (int i = 1; i <= 10; i++) {
        int len = snprintf(line, sizeof line, "%d\n", i);
        write(fd, line, len);
    }
    close(fd);

    fd = open("numbers.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    while (read(fd, &c, 1) == 1) {
        pos++;

        if (c == '\n') {
            newlines++;

            if (newlines == 3)
                start = pos;
            if (newlines == 4)
                break;
        }
    }

    ssize_t n = read(fd, buf, sizeof buf);

    lseek(fd, start, SEEK_SET);
    write(fd, "100\n", 4);
    if (n > 0)
        write(fd, buf, n);

    lseek(fd, 0, SEEK_SET);
    n = read(fd, buf, sizeof buf);
    write(1, buf, n);

    close(fd);
    return 0;
}  