/* Deadlock Demonstration using Multithreading with pthreads */ 
#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 
 
// Two resources (mutexes) 
pthread_mutex_t resource1; 
pthread_mutex_t resource2; 
 
// Thread 1 function - locks resource1 then resource2 
void* thread1_function(void* arg) { 
    printf("Thread 1: Trying to lock Resource 1...\n"); 
    pthread_mutex_lock(&resource1); 
    printf("Thread 1: Locked Resource 1 successfully!\n"); 
     
    sleep(1);  // Simulate some work 
     
    printf("Thread 1: Now trying to lock Resource 2...\n"); 
    pthread_mutex_lock(&resource2);  // Deadlock occurs here 
    printf("Thread 1: Locked Resource 2 successfully!\n"); 
     
    // Release locks 
    pthread_mutex_unlock(&resource2); 
    pthread_mutex_unlock(&resource1); 
     
    printf("Thread 1: Released both resources\n"); 
    return NULL; 
} 
 
// Thread 2 function - locks resource2 then resource1 
void* thread2_function(void* arg) { 
    printf("Thread 2: Trying to lock Resource 2...\n"); 
    pthread_mutex_lock(&resource2); 
    printf("Thread 2: Locked Resource 2 successfully!\n"); 
     
    sleep(1);  // Simulate some work 
     
    printf("Thread 2: Now trying to lock Resource 1...\n"); 
    pthread_mutex_lock(&resource1);  // Deadlock occurs here 
    printf("Thread 2: Locked Resource 1 successfully!\n"); 
     
    // Release locks 
    pthread_mutex_unlock(&resource1); 
    pthread_mutex_unlock(&resource2); 
     
    printf("Thread 2: Released both resources\n"); 
    return NULL; 
} 
 
int main() { 
    pthread_t thread1, thread2; 
     
    // Initialize mutexes 
    pthread_mutex_init(&resource1, NULL); 
    pthread_mutex_init(&resource2, NULL); 
     
    printf("===== Deadlock Demonstration =====\n"); 
    printf("Creating two threads...\n\n"); 
     
    // Create threads 
    pthread_create(&thread1, NULL, thread1_function, NULL); 
    pthread_create(&thread2, NULL, thread2_function, NULL); 
     
    // Wait for threads (will wait forever due to deadlock) 
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL); 
     
    // Cleanup (never reached due to deadlock) 
    pthread_mutex_destroy(&resource1); 
    pthread_mutex_destroy(&resource2); 
     
    printf("\nBoth threads completed (this won't print due to deadlock)\n"); 
     
    return 0; 
} 