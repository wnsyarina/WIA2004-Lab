#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int jobVal;

    printf("Enter number of jobs: ");
    scanf("%d", &jobVal);

    int jobBurstTime[jobVal];
    int turnAroundTime[jobVal];
    int waitingTime[jobVal];

    printf("Enter the burst time for each job:\n");
    for (int i = 0; i < jobVal; i++) {
        scanf("%d", &jobBurstTime[i]);
    }

    // Sort the jobs based on burst time (Shortest Job First)
    for (int i = 0; i < jobVal - 1; i++) {
        for (int j = 0; j < jobVal - i - 1; j++) {
            if (jobBurstTime[j] > jobBurstTime[j + 1]) {
                swap(&jobBurstTime[j], &jobBurstTime[j + 1]);
            }
        }
    }

    turnAroundTime[0] = jobBurstTime[0];

    for (int k = 1; k < jobVal; k++) {
        turnAroundTime[k] = turnAroundTime[k - 1] + jobBurstTime[k];
    }

    double avgTurnAroundTime = 0;
    double avgWaitingTime = 0;

    for (int j = 0; j < jobVal; j++) {
        avgTurnAroundTime += turnAroundTime[j];
        waitingTime[j] = turnAroundTime[j] - jobBurstTime[j];
        avgWaitingTime += waitingTime[j];
    }

    avgTurnAroundTime /= jobVal;
    avgWaitingTime /= jobVal;

    printf("Job \t Burst Time \t Waiting Time \t Turnaround Time\n");

    for (int z = 0; z < jobVal; z++) {
        printf("%d \t\t %d \t\t %d \t\t %d\n", z, jobBurstTime[z], waitingTime[z], turnAroundTime[z]);
    }

    printf("Average Turnaround time: %.2lf\n", avgTurnAroundTime);
    printf("Average Waiting time: %.2lf\n", avgWaitingTime);

    return 0;
}
