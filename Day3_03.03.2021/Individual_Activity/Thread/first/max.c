#include "maxandmin.h"

int Array[1000] = {0}, maxarr[10] = {0};
void *task_body_max(void *pv)
{
  int i, thread_num = (__intptr_t)pv, tempmax = 0;  
  for(i=0; i<100; ++i)
  {
    
    if(Array[thread_num * 100 + i] > tempmax)
    {
      tempmax = Array[i];
    }
  }
  maxarr[thread_num] = tempmax;
}

int findmaxno()
{
  int n=10, i, tempmax = 0;
  pthread_t ptrarr[n];
  srand(time(0));
  for(i=0; i<1000; i++){
    Array[i] = random()%100;
  }
  for(i=0; i<n ; ++i){
    pthread_create(&ptrarr[i], NULL, task_body_max, (void*)(__intptr_t) i);
  }
  for(i=0; i<n ; ++i){
    pthread_join(ptrarr[i], NULL);
  }
  for(i=0; i < n; ++i)
  {
    if(maxarr[i] > tempmax)
    {
      tempmax = maxarr[i];
    }
  }
  return tempmax;
}