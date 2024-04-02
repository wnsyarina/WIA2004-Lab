#include <stdio.h>

int main() {
    
    int jobVal;
    //asume arival time is same =0;
    printf("Enter number of jobs: ");
    scanf("%d", &jobVal);
    printf("Total Number of jobs: %d\n", jobVal);
    
    int jobBurstTime[jobVal];
    int turnAroundTime[jobVal];
    
    printf("Enter the burst time accordingly:\n");
    for(int i = 0; i < jobVal; i++) {
        scanf("%d", &jobBurstTime[i]);
    }
    
    turnAroundTime[0]=jobBurstTime[0];
    
    for(int k = 1;k < jobVal; k++) {
         turnAroundTime[k] = turnAroundTime[k - 1] + jobBurstTime[k];
    }
    
    double avgTurnAroundTime = 0;
    int waitingTime [jobVal];
    double avgWaitingTime = 0;
    
    for(int j = 0;j < jobVal; j++) {
        avgTurnAroundTime+=turnAroundTime[j];
        waitingTime [j]= turnAroundTime[j]-jobBurstTime[j];
        avgWaitingTime+=waitingTime[j];
        
    }
    
    avgTurnAroundTime=avgTurnAroundTime/jobVal;
    avgWaitingTime = avgWaitingTime/jobVal;

    printf(" Job \tBurst Time \t Waiting Time\t Turnaround Time\n");
    
    for(int z=0;z<jobVal;z++){
         printf("\n %d \t\t %d \t\t %d \t\t %d", z, jobBurstTime[z], waitingTime[z], turnAroundTime[z]);
    }

    printf("\n");
    printf("Average TurnAround time : %.2lf\n", avgTurnAroundTime);
    printf("Average Waiting time : %.2lf\n", avgWaitingTime);
    
    return 0;
}
