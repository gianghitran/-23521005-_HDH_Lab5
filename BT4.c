#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x = 0; 
pthread_mutex_t lock; 

void *A(void *message)
{
    while(1)
    {
        pthread_mutex_lock(&lock); 
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("A | x = %d\n", x);
        pthread_mutex_unlock(&lock); 
        // sleep(10);
    }
}

void *B(void *message)
{
    while(1)
    {
        pthread_mutex_lock(&lock); 
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("B | x = %d\n", x);
        pthread_mutex_unlock(&lock); 
        // sleep(10);
    }
}

int main()
{
    pthread_t AThread, BThread;
    pthread_mutex_init(&lock, NULL); 

    pthread_create(&AThread, NULL, &A, NULL);
    pthread_create(&BThread, NULL, &B, NULL);

    while(1){}

    return 0;
}