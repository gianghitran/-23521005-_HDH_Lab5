#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int products = 0, sells = 0;
sem_t A;              
sem_t B;              

void *Produce(void *message)
{
    while (1)
    {
        sem_wait(&B); // Đợi nếu sản phẩm đã đạt ngưỡng sells + 1005
        products++;        // Tăng số lượng sản phẩm
        printf("Produce | products = %d, sells = %d\n", products, sells);
        sem_post(&A); // Tăng sản phẩm sẵn sàng tiêu thụ
    }
    return NULL;
}

void *Consume(void *message)
{
    while (1)
    {
        sem_wait(&A); // Đợi nếu không có sản phẩm để tiêu thụ
        sells++;  // Tăng số sản phẩm đã bán
        printf("Consume | products = %d, sells = %d\n", products, sells);
        sem_post(&B); // Tăng khả năng sản xuất thêm sản phẩm
    }
    return NULL;
}

int main()
{
    pthread_t producerThread, consumerThread;

  
    sem_init(&A, 0, 0);          
    sem_init(&B, 0, 1005); 
    pthread_create(&producerThread, NULL, &Produce, NULL);
    pthread_create(&consumerThread, NULL, &Consume, NULL);

    while(1){} // Giữ cho tiểu trình main tồn tại để quan sát idthreadA và idthreadB
    
    return 0;
}
