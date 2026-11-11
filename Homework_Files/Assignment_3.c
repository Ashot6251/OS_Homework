#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char path[256];
    char c;

    printf("File path: ");
    scanf("%255s", path);

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);

    for (off_t i = size - 1; i >= 0; i--) {
        lseek(fd, i, SEEK_SET);
        read(fd, &c, 1);
        write(1, &c, 1);
    }

    write(1, "\n", 1);

    close(fd);
    return 0;
}