/* SJF (Shortest Job First) Non-Preemptive CPU Scheduling Algorithm */ 
#include <stdio.h> 
 
int main() { 
    int n, i, j, temp; 
    float avg_wt = 0, avg_tat = 0; 
     
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
     
    int pid[n], bt[n], wt[n], tat[n]; 
     
    // Input process details 
    printf("\nEnter Burst Time for each process:\n"); 
    for(i = 0; i < n; i++) { 
        pid[i] = i + 1; 
        printf("Process P%d: ", i + 1); 
        scanf("%d", &bt[i]); 
    } 
     
    // Sort processes by burst time (SJF sorting) 
    for(i = 0; i < n-1; i++) { 
        for(j = i+1; j < n; j++) { 
            if(bt[i] > bt[j]) { 
                // Swap burst times 
                temp = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = temp; 
                 
                // Swap process IDs 
                temp = pid[i]; 
                pid[i] = pid[j]; 
                pid[j] = temp; 
            } 
        } 
    } 
     
    // Calculate Waiting Time 
    wt[0] = 0; 
    for(i = 1; i < n; i++) { 
        wt[i] = wt[i-1] + bt[i-1]; 
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