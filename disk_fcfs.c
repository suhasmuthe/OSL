/* FCFS (First Come First Serve) Disk Scheduling Algorithm */ 
#include <stdio.h> 
#include <stdlib.h> 
 
int main() { 
    int request[50], n, head, i; 
    int total_seek = 0; 
     
    printf("Enter number of disk requests: "); 
    scanf("%d", &n); 
     
    printf("Enter disk request queue:\n"); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &request[i]); 
    } 
     
    printf("Enter initial head position: "); 
    scanf("%d", &head); 
     
    printf("\n===== FCFS Disk Scheduling =====\n"); 
    printf("Initial head position: %d\n\n", head); 
     
    int initial_head = head;  // Save initial position 
     
    // Process requests in FCFS order 
    for(i = 0; i < n; i++) { 
        int distance = abs(request[i] - head); 
        total_seek += distance; 
         
        printf("Move from %d to %d (Distance: %d)\n", head, request[i], distance); 
        head = request[i]; 
    } 
     
    printf("\n================================\n"); 
    printf("Total Seek Time: %d\n", total_seek); 
    printf("Average Seek Time: %.2f\n", (float)total_seek / n); 
     
return 0; 
}