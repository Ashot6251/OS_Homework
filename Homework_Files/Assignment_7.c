#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define N 4096

int main(void) {
    char p1[256];
    char p2[256];
    char b1[N];
    char b2[N];
    long offset = 0;

    printf("First file path: ");
    scanf("%255s", p1);
    printf("Second file path: ");
    scanf("%255s", p2);

    int f1 = open(p1, O_RDONLY);
    if (f1 < 0) {
        perror("open first");
        return 1;
    }

    int f2 = open(p2, O_RDONLY);
    if (f2 < 0) {
        perror("open second");
        return 1;
    }

    while (1) {
        ssize_t n1 = read(f1, b1, N);
        ssize_t n2 = read(f2, b2, N);
        ssize_t m = n1 < n2 ? n1 : n2;

        for (ssize_t i = 0; i < m; i++)
            if (b1[i] != b2[i]) {
                printf("Files differ at byte %ld\n", offset + i);
                return 1;
            }

        if (n1 != n2) {
            printf("Files differ at byte %ld\n", offset + m);
            return 1;
        }

        if (n1 == 0)
            break;

        offset += n1;
    }

    printf("Files are identical\n");

    close(f1);
    close(f2);
    return 0;
}