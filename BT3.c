#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int x = 0; 
void *A(void *message)
{
    while(1){
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("A | x = %d\n", x);
    }
}

void *B(void *message)
{
    while(1){
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("B | x = %d\n", x);
    }
}

int main()
{
    pthread_t AThread, BThread;
    pthread_create(&AThread, NULL, &A, NULL);
    pthread_create(&BThread, NULL, &B, NULL);

    while(1){}
    return 0;
}