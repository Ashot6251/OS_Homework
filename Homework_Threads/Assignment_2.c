#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10
#define THREADS 2

int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

typedef struct {
    int start;
    int end;
    int sum;
} Task;

void* adder(void* arg) {
    Task *t = arg;
    t -> sum = 0;

    for (int i = t -> start; i < t -> end; i++) {
        t -> sum += arr[i];
    }

    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    Task tasks[THREADS];
    int chunk = N / THREADS;

    for (int i = 0; i < THREADS; i++) {
        tasks[i].start = i * chunk;
        tasks[i].end = (i == THREADS - 1) ? N : ((i + 1) * chunk);
        if (pthread_create(&threads[i], NULL, adder, &tasks[i]) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return 1;
        }
    }

    int total = 0;
    for (int i = 0; i < THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            return 1;
        }

        printf("The sum of the thread %d's portion: %d\n", i, tasks[i].sum);
        total += tasks[i].sum;
    }

    printf("Total sum: %d\n", total);

    return 0;
}