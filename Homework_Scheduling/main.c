#include <stdio.h>
#include "process.h"

void print_results(const char *title, struct PProp arr[], int size) {
    float total_wt = 0, total_tat = 0, total_rt = 0;

    printf("\n=== %s ===\n", title);

    printf("Gantt Chart: ");
    for (int i = 0; i < size; i++)
        printf("| P%d ", arr[i].pid);
    printf("|\n");

    printf("%-6s%-6s%-6s%-6s%-6s%-6s\n", "PID", "AT", "BT", "WT", "TAT", "RT");
    for (int i = 0; i < size; i++) {
        printf("%-6d%-6d%-6d%-6d%-6d%-6d\n",
               arr[i].pid, arr[i].arrival_time, arr[i].burst_time,
               arr[i].waiting_time, arr[i].turnaround_time, arr[i].response_time);

        total_wt += arr[i].waiting_time;
        total_tat += arr[i].turnaround_time;
        total_rt += arr[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / size);
    printf("Average Turnaround Time: %.2f\n", total_tat / size);
    printf("Average Response Time: %.2f\n", total_rt / size);
}

int main(void) {
    int n;

    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    struct PProp original[n], fcfs[n], sjf[n];

    for (int i = 0; i < n; i++) {
        original[i].pid = i + 1;
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &original[i].arrival_time, &original[i].burst_time);
    }

    for (int i = 0; i < n; i++) {
        fcfs[i] = original[i];
        sjf[i] = original[i];
    }

    FCFS(fcfs, n);
    print_results("First Come First Served (FCFS)", fcfs, n);

    SJF(sjf, n);
    print_results("Shortest Job First (SJF)", sjf, n);

    return 0;
}