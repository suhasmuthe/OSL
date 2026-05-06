/* SSTF (Shortest Seek Time First) Disk Scheduling Algorithm */ 
#include <stdio.h> 
#include <stdlib.h> 
 
int main() { 
    int request[50], visited[50]; 
    int n, head, i, j, min, index; 
    int total_seek = 0; 
     
    printf("Enter number of disk requests: "); 
    scanf("%d", &n); 
     
    printf("Enter disk request queue:\n"); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &request[i]); 
        visited[i] = 0;  // Mark as not visited 
    } 
     
    printf("Enter initial head position: "); 
    scanf("%d", &head); 
     
    printf("\n===== SSTF Disk Scheduling =====\n"); 
    printf("Initial head position: %d\n\n", head); 
     
    // Process all requests 
    for(i = 0; i < n; i++) { 
        min = 9999; 
         
        // Find closest request (shortest seek time) 
        for(j = 0; j < n; j++) { 
            if(visited[j] == 0) { 
                int distance = abs(request[j] - head); 
                 
                if(distance < min) { 
                    min = distance; 
                    index = j; 
                } 
            } 
        } 
         
        // Mark request as visited 
        visited[index] = 1; 
        total_seek += min; 
         
        printf("Move from %d to %d (Distance: %d)\n", head, request[index], min); 
        head = request[index]; 
    } 
     
    printf("\n================================\n"); 
    printf("Total Seek Time: %d\n", total_seek); 
    printf("Average Seek Time: %.2f\n", (float)total_seek / n); 
     
    return 0; 
}