#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define maxitem_no 10
#define buf_size 10

sem_t empty, full;
int in = 0, out = 0;
int buf[buf_size];
void *producer(void *pnumber){   
    int item;
    for(int i = 0; i < maxitem_no; i++) {
        item = rand(); 
        sem_wait(&empty);
        while (((in + 1) % buf_size) == out){
           buf[in] = item;
           printf("Producer Number %d: Insert Item Number %d at position %d\n", *((int *)pnumber),buf[in],in);
           in = (in + 1) % buf_size;     
        }
        sem_post(&full);
    }
}
void *consumer(void *cnumber){   
    int item=0;
    for(int i = 0; i < maxitem_no; i++) {
        sem_wait(&full);
        while (in == out) {
           item = buf[out];
           printf("Consumer Number %d: Remove Item Number %d at position %d\n",*((int *)cnumber),item, out); 
           out = (out + 1) % buf_size;     
        }
        sem_post(&empty);
    }
}

int main()
{   
    pthread_t producer[10],consumer[10];
    sem_init(&empty,0,buf_size);
    sem_init(&full,0,0);
    int a[10] = {1,2,3,4,10}; 
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