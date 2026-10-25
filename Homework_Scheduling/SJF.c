#include "process.h"

void SJF(struct PProp arr[], int size) {
    int current_time = 0;

    for (int i = 0; i < size; i++) {
        // Skip idle time if nothing has arrived yet
        int earliest = arr[i].arrival_time;
        for (int j = i + 1; j < size; j++)
            if (arr[j].arrival_time < earliest)
                earliest = arr[j].arrival_time;

        if (current_time < earliest)
            current_time = earliest;

        // Shortest burst among arrived processes
        int next = -1;
        for (int j = i; j < size; j++) {
            if (arr[j].arrival_time > current_time)
                continue;
            if (next == -1 ||
                arr[j].burst_time < arr[next].burst_time ||
                (arr[j].burst_time == arr[next].burst_time &&
                 arr[j].arrival_time < arr[next].arrival_time))
                next = j;
        }

        struct PProp temp = arr[i];
        arr[i] = arr[next];
        arr[next] = temp;

        arr[i].waiting_time = current_time - arr[i].arrival_time;
        arr[i].turnaround_time = arr[i].waiting_time + arr[i].burst_time;
        arr[i].response_time = arr[i].waiting_time;

        current_time += arr[i].burst_time;
    }
}