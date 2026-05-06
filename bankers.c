/* Banker's Algorithm for Deadlock Avoidance */ 
#include <stdio.h> 
 
int main() { 
    int n, m, i, j, k; 
     
    // Input number of processes and resources 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
     
    printf("Enter number of resources: "); 
    scanf("%d", &m); 
     
    int alloc[n][m], max[n][m], need[n][m]; 
    int avail[m]; 
     
    // Input Allocation Matrix 
    printf("\nEnter Allocation Matrix:\n"); 
    for(i = 0; i < n; i++) { 
        printf("Process P%d: ", i); 
        for(j = 0; j < m; j++) { 
            scanf("%d", &alloc[i][j]); 
        } 
    } 
     
    // Input Maximum Matrix 
    printf("\nEnter Maximum Matrix:\n"); 
    for(i = 0; i < n; i++) { 
        printf("Process P%d: ", i); 
        for(j = 0; j < m; j++) { 
            scanf("%d", &max[i][j]); 
        } 
    } 
     
    // Input Available Resources 
    printf("\nEnter Available Resources:\n"); 
    for(i = 0; i < m; i++) { 
        scanf("%d", &avail[i]); 
    } 
     
    // Calculate Need Matrix (Need = Max - Allocation) 
    for(i = 0; i < n; i++) { 
        for(j = 0; j < m; j++) { 
            need[i][j] = max[i][j] - alloc[i][j]; 
        } 
    } 
     
    // Display Need Matrix 
    printf("\nNeed Matrix:\n"); 
    for(i = 0; i < n; i++) { 
        printf("P%d: ", i); 
        for(j = 0; j < m; j++) { 
            printf("%d ", need[i][j]); 
        } 
        printf("\n"); 
    } 
     
    // Banker's Algorithm for Safe State Check 
    int finish[n], safeSeq[n], work[m]; 
     
    // Initialize finish array 
    for(i = 0; i < n; i++) { 
        finish[i] = 0; 
    } 
     
    // Initialize work array with available resources 
    for(i = 0; i < m; i++) { 
        work[i] = avail[i]; 
    } 
     
    int count = 0; 
     
    // Find safe sequence 
    while(count < n) { 
        int found = 0; 
         
        for(i = 0; i < n; i++) { 
            if(finish[i] == 0) {  // If process not finished 
                 
                // Check if need <= work 
                for(j = 0; j < m; j++) { 
                    if(need[i][j] > work[j]) 
                        break; 
                } 
                 
                // If all resources can be allocated 
                if(j == m) { 
                    // Add allocated resources back to work 
                    for(k = 0; k < m; k++) { 
                        work[k] += alloc[i][k]; 
                    } 
                     
                    safeSeq[count++] = i; 
                    finish[i] = 1; 
                    found = 1; 
                } 
            } 
        } 
         
        // If no process found in this iteration 
        if(found == 0) { 
            printf("\nSystem is NOT in SAFE state!\n"); 
            printf("Deadlock may occur.\n"); 
            return 0; 
        } 
    } 
     
    // System is in safe state 
    printf("\nSystem is in SAFE state!\n"); 
    printf("Safe sequence is: "); 
    for(i = 0; i < n; i++) { 
        printf("P%d ", safeSeq[i]); 
        if(i < n-1) printf("-> "); 
    } 
    printf("\n"); 
     
    return 0; 
}