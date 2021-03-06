#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define Maxitems 10 // Maximum itemss a producer can produce or a consumer can consume
#define bufsize 10 // Size of the buf

int in = 0, out = 0, items=0;
int buf[bufsize];
pthread_mutex_t mutex;
void *producer(void *pnumber){   
    if(in==bufsize-1)
        printf("Producer Stack has reached capacity \n");
    else{
        for(int i = 0; i < Maxitems; i++) {
        items = rand(); 
        pthread_mutex_lock(&mutex);
        buf[in] = items;
        printf("Producer Number %d: Insert item number %d at posotion %d\n", *((int *)pnumber),buf[in],in);
        in = (in + 1) % bufsize;     
        pthread_mutex_unlock(&mutex);
        }
    }
}
void *consumer(void *cnumber){   
    if(out==bufsize-1)
        printf("Consumer Stack is full\n");
    else{
        int items=0;
        for(int i = 0; i < Maxitems; i++) {
            pthread_mutex_lock(&mutex);
            items = buf[out];
            printf("Consumer Number %d: Remove item number %d at position %d\n",*((int *)cnumber),items, out); 
            out = (out + 1) % bufsize;     
            pthread_mutex_unlock(&mutex);
        }
    }
}
int main(){   
    pthread_t producer[10],consumer[10];
    pthread_mutex_init(&mutex, NULL);
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
    pthread_mutex_destroy(&mutex);
    return 0;
}