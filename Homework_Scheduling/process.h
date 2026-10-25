#ifndef PROCESS_H
#define PROCESS_H

struct PProp {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void FCFS (struct PProp arr[], int size);
void SJF (struct PProp arr[], int size);

#endif