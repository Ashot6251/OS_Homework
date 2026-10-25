FCFS:
First, the processes are sorted by arrival time. We keep a clock called current_time. If there are no processes yet, then move the clock to the closest arrival time. The waiting time is the difference between the current time and the arrival time. The turnaround time is the sum of the waiting time and the burst time. Because FCFS is a non-preemptive algorithm, the response time is the same as the waiting time. After finishing calculating those values for a process, we add the burst time of our process to the current time, so with the next iteration we can start with the next process.

SJF:
If no process has arrived, we move the clock to the earliest arrival. Then we set next = -1, to indicate that no process is picked yet. We go through the processes that have not run yet. If a process arrives after the current clock time, we use continue to skip it, because it can’t run yet. For the processes that have arrived, the first one we see becomes next, since nothing has been picked before it. After that, a process replaces next only if it has a shorter burst time. If two have the same burst time, we pick the one that arrived first. We place the chosen process into position i, ensuring right execution order. After that, the waiting, turnaround, and response times are calculated the same way as in FCFS, and the clock moves forward by the burst time.

process.h:
We create this header so that we don’t declare the same struct in each file. It also declares the FCFS and SJF functions, so main.c can call them even though they are defined in other files.

main:
Inside main, print_results function is declared for printing Gantt Chart, process table and averages. Used for code reusability.

Instructions:
Run the program schedulers.

Acknowledgments:
AI was used to assist with terminal output.