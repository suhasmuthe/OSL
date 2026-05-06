/* Round Robin CPU Scheduling Algorithm */ 
#include <stdio.h> 
 
int main() { 
    int n, i, quantum, time = 0; 
    float avg_wt = 0, avg_tat = 0; 
     
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
     
    int pid[n], bt[n], rem_bt[n], wt[n], tat[n]; 
     
    // Input process details 
    printf("\nEnter Burst Time for each process:\n"); 
    for(i = 0; i < n; i++) { 
        pid[i] = i + 1; 
        printf("Process P%d: ", i + 1); 
        scanf("%d", &bt[i]); 
        rem_bt[i] = bt[i];  // Remaining burst time 
    } 
     
    printf("\nEnter Time Quantum: "); 
    scanf("%d", &quantum); 
     
    // Round Robin scheduling 
    int complete = 0; 
    while(complete < n) { 
        for(i = 0; i < n; i++) { 
            if(rem_bt[i] > 0) { 
                if(rem_bt[i] > quantum) { 
                    time += quantum; 
                    rem_bt[i] -= quantum; 
                } 
                else { 
                    time += rem_bt[i]; 
                    wt[i] = time - bt[i]; 
                    rem_bt[i] = 0; 
                    complete++; 
                } 
            } 
        } 
    } 
     
    // Calculate Turnaround Time 
    for(i = 0; i < n; i++) { 
        tat[i] = wt[i] + bt[i]; 
    } 
     
    // Display results 
    printf("\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
    printf("----------------------------------------------------------------\n"); 
     
    for(i = 0; i < n; i++) { 
        printf("P%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]); 
        avg_wt += wt[i]; 
        avg_tat += tat[i]; 
    } 
     
    // Calculate averages 
    avg_wt /= n; 
    avg_tat /= n; 
     
    printf("\nAverage Waiting Time: %.2f", avg_wt); 
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat); 
     
    return 0; 
} 