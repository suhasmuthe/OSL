/* Zombie Process Demonstration using fork() */ 
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
        printf("Parent sleeping for 10 seconds...\n"); 
        printf("Child will become zombie during this time.\n"); 
        printf("Use 'ps aux | grep Z' in another terminal to see zombie process\n\n"); 
        sleep(10);  // Parent sleeps, child becomes zombie 
        printf("Parent exiting now.\n"); 
    } 
    else if(pid == 0) { 
        // Child process 
        printf("Child Process ID: %d\n", getpid()); 
        printf("Child Parent ID: %d\n", getppid()); 
        printf("Child exiting immediately...\n\n"); 
        exit(0);  // Child terminates, becomes zombie 
    } 
    else { 
        // Fork failed 
        printf("Fork failed!\n"); 
        return 1; 
    } 
     
    return 0; 
}