/* Orphan Process Demonstration using fork() */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
 
int main() { 
    pid_t pid = fork();  // Create a child process 
     
    if(pid > 0) { 
        // Parent process 
        printf("Parent Process ID: %d\n", getpid()); 
        printf("Child Process ID: %d\n", pid); 
        printf("Parent exiting immediately...\n\n"); 
        exit(0);  // Parent terminates, child becomes orphan 
    } 
    else if(pid == 0) { 
        // Child process 
        printf("Child Process ID: %d\n", getpid()); 
        printf("Original Parent ID: %d\n", getppid()); 
        printf("Child sleeping for 5 seconds...\n"); 
        sleep(5);  // Sleep to allow parent to terminate 
        printf("Child woke up. New Parent ID (init/systemd): %d\n", getppid()); 
        printf("Child is now an orphan process.\n"); 
    } 
    else { 
        // Fork failed 
        printf("Fork failed!\n"); 
        return 1; 
    } 
     
    return 0; 
}