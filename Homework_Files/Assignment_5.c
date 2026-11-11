#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, "START", 5);
    lseek(fd, 1024 * 1024, SEEK_CUR);
    write(fd, "END", 3);
    close(fd);

    fd = open("sparse.bin", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Apparent size: %ld\n", (long)lseek(fd, 0, SEEK_END));
    close(fd);

    /* The 1 MiB gap between START and END is never written.
       The filesystem stores it as a hole and allocates no disk blocks for it.
       The apparent size counts the hole, but du counts only allocated blocks.
       So du shows a much smaller number than the apparent size. */

    return 0;
}