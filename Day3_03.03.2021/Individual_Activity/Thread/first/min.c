#include "maxandmin.h"

int MinArray[1000] = {0}, minarr[10] = {0};
void *task_body_min(void *pv)
{
  int i, thread_num = (__intptr_t)pv, tempmin = 0;  
  for(i=0; i<100; ++i)
  {
    if(MinArray[thread_num * 100 + i] < tempmin)
    {
      tempmin = MinArray[i];
    }
  }
  minarr[thread_num] = tempmin;
}

int findminno()
{
  int n=10, i, tempmin = 0;
  pthread_t ptrarr[n];
  srand(time(0));
  for(i=0; i<1000; i++)
  {
    
    MinArray[i] = random()%100;
  }
  for(i=0; i<n ; ++i)
  {
    pthread_create(&ptrarr[i], NULL, task_body_min, (void*)(__intptr_t) i);
  }
  for(i=0; i<n ; ++i)
  {
    pthread_join(ptrarr[i], NULL);
  }
  for(i=0; i < n; ++i)
  {
    if(minarr[i] < tempmin)
    {
      tempmin = minarr[i];
    }
  }
  return tempmin;
}