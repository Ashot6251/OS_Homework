#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_num (void* arg) {
    printf("ThreadID %lu: ", (unsigned long)pthread_self());
    for (int i = 1; i <= 5; i++)
        printf("%d ", i);

    printf("\n");
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++)
        if (pthread_create(&threads[i], NULL, print_num, NULL) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return 1;
        }

    for (int i = 0; i < 3; i++)
        if(pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            return 1;
        }

    
    return 0;
}