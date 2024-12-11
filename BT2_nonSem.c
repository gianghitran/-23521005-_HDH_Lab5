#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>

#define MAX_SIZE 100

int a[MAX_SIZE];  
int count = 0;    
// sem_t sem;      // Semaphore để đồng bộ hóa việc truy cập vào mảng

// Hàm sinh số ngẫu nhiên và thêm vào mảng
void *A(void *param)
{
    while (1)
    {
        int num = rand() ;  // Sinh số ngẫu nhiên 
        
        // sem_wait(&sem); 
        if (count < MAX_SIZE)  // Kiểm tra mảng chưa đầy
        {
            a[count] = num;  
            count++;           
            printf("A | Them vao mang: %d, Kich thuoc mang: %d\n", num, count);
        }
        // sem_post(&sem);  
        // sleep(2);
    }
    return NULL;
}

// Hàm lấy phần tử ra khỏi mảng
void *B(void *param)
{
    while (1)
    {
        // sem_wait(&sem);  // Đảm bảo chỉ một thread truy cập vào mảng tại một thời điểm
        if (count > 0)  
        {
            int num = a[count - 1];  
            count--;  
            printf("B | Xoa khoi mang: %d, Kich thuoc mang: %d\n", num, count);
        }
        else
        {
            printf("B | “Nothing in array a”\n");
        }
        // sem_post(&sem);  
        // sleep(2);
        
    }
    return NULL;
}

int main()
{
    pthread_t AThread, BThread;
    
    srand(time(NULL));  // Sinh số ngẫu nhiên
    
    // sem_init(&sem, 0, 1);
    
    // Tạo hai thread: A và B
    pthread_create(&AThread, NULL, &A, NULL);
    pthread_create(&BThread, NULL, &B, NULL);
    
    // Chờ các thread hoàn thành
    pthread_join(AThread, NULL);
    pthread_join(BThread, NULL);
    

    return 0;
}
