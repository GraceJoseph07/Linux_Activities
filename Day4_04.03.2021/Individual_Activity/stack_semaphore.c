#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define max_items 10 
#define buf_size 10

sem_t empty;
sem_t full;
int in = 0,out = 0, items=0;
int buf[buf_size];

void *producer(void *pnumber)
{   
    if(in==buf_size-1)
        printf("Producer Stack is full \n");
    else{
        for(int i = 0; i < max_items; i++) {
            items = rand(); 
            sem_wait(&empty);
            buf[in] = items;
            printf("Producer Number %d: Insert Item Number %d at position %d\n", *((int *)pnumber),buf[in],in);
            in = (in + 1) % buf_size;     
            sem_post(&full);
        }
    }
}
void *consumer(void *cnumber){   
    if(out==buf_size-1)
        printf("Consumer stack has reached capacity\n");
    else{
        int item=0;
        for(int i = 0; i < max_items; i++) {
            sem_wait(&full);
            item = buf[out];
            printf("Consumer Number %d: Remove Item Number %d at position %d\n",*((int *)cnumber),item, out); 
            out = (out + 1) % buf_size;     
            sem_post(&empty);
        }
    }
}
int main(){   
    pthread_t producer[10],consumer[10];
    sem_init(&empty,0,buf_size);
    sem_init(&full,0,0);
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
    for(int i = 0; i < 10; i++) {
        pthread_create(&producer[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_create(&consumer[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(producer[i], NULL);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(consumer[i], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
