#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces: item %d\n", x);

    ++mutex;
}

void consumer(){
    --mutex;
    ++empty;
    --full;
    
    printf("Consumer consumes: item %d\n", x);
    x--;
    ++mutex;
}

int main(){
    int n;

    printf("1. Producer\n2. Consumer\n3. Exit\n");
    
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch(n){
            case 1:
                if(mutex == 1 && empty != 0){
                    producer();
                }
                else{
                    printf("Buffer is full\n");
                }
                break;

            case 2:
                if(mutex == 1 && full != 0){
                    consumer();
                }
                else{
                    printf("Buffer is empty\n");
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    }        
    return 0;
}