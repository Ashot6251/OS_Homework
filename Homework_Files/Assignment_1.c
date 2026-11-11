#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char src[256];
    char dst[256];
    char buf[4096];
    ssize_t n;
    long total = 0;

    printf("Source file path: ");
    scanf("%255s", src);
    printf("Destination file path: ");
    scanf("%255s", dst);

    int in = open(src, O_RDONLY);
    if (in < 0) {
        perror("open source");
        return 1;
    }

    int out = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror("open destination");
        return 1;
    }

    while ((n = read(in, buf, sizeof buf)) > 0) {
        if (write(out, buf, n) != n) {
            perror("write");
            return 1;
        }
        total += n;
    }

    if (n < 0) {
        perror("read");
        return 1;
    }

    printf("Total bytes copied: %ld\n", total);

    close(in);
    close(out);
    return 0;
}