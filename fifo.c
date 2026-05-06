/* FIFO (First In First Out) Page Replacement Algorithm */ 
#include <stdio.h> 
 
int main() { 
    int n, f, i, j, flag, faults = 0; 
     
    printf("Enter number of pages: "); 
    scanf("%d", &n); 
     
    int pages[n]; 
    printf("Enter page reference string:\n"); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &pages[i]); 
    } 
     
    printf("Enter number of frames: "); 
    scanf("%d", &f); 
     
    int frames[f]; 
     
    // Initialize frames with -1 (empty) 
    for(i = 0; i < f; i++) { 
        frames[i] = -1; 
    } 
     
    int index = 0;  // FIFO queue index 
     
    printf("\nFIFO Page Replacement:\n"); 
    printf("------------------------------------------------------------\n"); 
     
    for(i = 0; i < n; i++) { 
        flag = 0; 
         
        // Check if page already in frame (Page Hit) 
        for(j = 0; j < f; j++) { 
            if(frames[j] == pages[i]) { 
                flag = 1;  // Page hit 
                break; 
            } 
        } 
         
        // If page not found (Page Fault) 
        if(flag == 0) { 
            frames[index] = pages[i]; 
            index = (index + 1) % f;  // Circular queue 
            faults++; 
            printf("Page %d -> ", pages[i]); 
        } 
        else { 
            printf("Page %d -> ", pages[i]); 
        } 
         
        // Display current frame status 
        for(j = 0; j < f; j++) { 
            if(frames[j] != -1) 
                printf("%d ", frames[j]); 
            else 
                printf("- "); 
        } 
         
        if(flag == 0) 
            printf(" (Page Fault)"); 
        else 
            printf(" (Page Hit)"); 
         
        printf("\n"); 
    } 
     
    printf("------------------------------------------------------------\n"); 
    printf("Total Page Faults: %d\n", faults); 
    printf("Page Fault Ratio: %.2f\n", (float)faults/n); 
    printf("Page Hit Ratio: %.2f\n", (float)(n-faults)/n); 
     
    return 0; 
}