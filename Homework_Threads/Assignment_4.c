#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 5

int arr[N] = {1, 2, 3, 4, 5};

void* squareAndPrint (void* arg) {
    int val = *(int*)arg;
    printf("Square of %d is %d\n", val, val * val);
    return NULL;
}

int main() {
    pthread_t threads[N];

    for (int i = 0; i < N; i++)
        if(pthread_create(&threads[i], NULL, squareAndPrint, &arr[i]) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return 1;
        }

    for (int i = 0; i < N; i++)
        if(pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            return 1;
        }

    return 0;
}