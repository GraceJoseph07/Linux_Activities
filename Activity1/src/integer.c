#include<stdio.h>
#include"myutils.h"
#include<stdarg.h>
int factorial(int num1){
    int i,factorial=1;
    if(num1<0)
        factorial=-1;
    else if(num1==0 || num1==1)
        factorial=1;
    else {
        for(i=1;i<=num1;i++){
            factorial=factorial*i;
        }
        
    }
        return factorial;
}
int isPrime(int num1){
    int count=0,i, result=0;
    if(num1<=0)
        result= -1;
    else{
        for(i=1;i<=num1;i++){
            if(num1%i==0)
                count++;
        }
        if(count==2)
            result= 1;
        else
            result= 0;
    }
    return result;

}
int isPalindrome(int num1){
    int r,sum=0,temp;   
    temp=num1;    
    while(num1>0)    
    {    
    r=num1%10;    
    sum=(sum*10)+r;    
    num1=num1/10;    
    }    
    if(temp==sum)    
        return 1;    
    else   
        return 0;
}
int vsum(int num1,...) {
   va_list valist;
     int sum = 0;
     int i;
 
     va_start(valist, num1);
     for (i = 0; i < num1; i++)
     {
         sum += va_arg(valist, int);
     }
     va_end(valist);
     return sum;
}
