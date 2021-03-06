#include "bitmask.h"
int set(int x, int y) { 
    return (x | (1 << (y - 1))); 
} 
  

int clear(int x, int y) { 
    return (x & (~(1 << (y - 1)))); 
} 
  
 
int flip(int x, int y){ 
    return (x ^ (1 << (y - 1))); 
} 