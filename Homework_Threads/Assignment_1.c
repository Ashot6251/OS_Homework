#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_threadID (void* arg) {
    pthread_t my_id = pthread_self();
    printf("Thread %lu is running\n", (unsigned long)my_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    if(pthread_create(&thread1, NULL, print_threadID, NULL) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    if(pthread_create(&thread2, NULL, print_threadID, NULL) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    if(pthread_create(&thread3, NULL, print_threadID, NULL) != 0) {
        perror("Failed to create thread 3");
        return 1;
    }

    if(pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
    }

    if(pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread 2");
        return 1;
    }

    if(pthread_join(thread3, NULL) != 0) {
        perror("Failed to join thread 3");
        return 1;
    }

    return 0;
}