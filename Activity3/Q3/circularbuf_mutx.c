#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MaxItemNo 10 
#define bufsize 10 

int in = 0;
int out = 0;
int buffer[bufsize];
pthread_mutex_t mutex;
void *producer(void *pnumber){   
    int items;
    for(int i = 0; i < MaxItemNo; i++) {
        items = rand(); 
        pthread_mutex_lock(&mutex);
        while (((in + 1) % bufsize) == out){
           buffer[in] = items;
           printf("Producer Number %d: Insert Item Number %d at position %d\n", *((int *)pnumber),buffer[in],in);
           in = (in + 1) % bufsize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cnumber)
{   
    int items=0;
    for(int i = 0; i < MaxItemNo; i++) {
        pthread_mutex_lock(&mutex);
        while (in == out){
           items = buffer[out];
           printf("Consumer Number %d: Remove Item Number %d at position %d\n",*((int *)cnumber),items, out); 
           out = (out + 1) % bufsize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main(){   
    pthread_t pro[10],con[10];
    pthread_mutex_init(&mutex, NULL);
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
    for(int i = 0; i < 10; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}