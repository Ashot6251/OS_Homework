#include "process.h"

static void insertion_sort(struct PProp arr[], int size) {
    for (int i = 1; i < size; i++) {
        struct PProp process = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].arrival_time > process.arrival_time) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = process;
    }
}

void FCFS(struct PProp arr[], int size) {
    insertion_sort(arr, size);

    int current_time = 0;

    for (int i = 0; i < size; i++) {
        if (current_time < arr[i].arrival_time)
            current_time = arr[i].arrival_time;

        arr[i].waiting_time = current_time - arr[i].arrival_time;
        arr[i].turnaround_time = arr[i].waiting_time + arr[i].burst_time;
        arr[i].response_time = arr[i].waiting_time;

        current_time += arr[i].burst_time;
    }
}