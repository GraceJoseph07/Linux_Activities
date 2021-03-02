#include<stdio.h>
// #include"myutils.h"
// #include"mystring.h"
// #include"bitmask.h"
int main(){
    int num1=27,num2= 17,num3=737,result=0, prime=0, x=7, y=1;
    char str1[];
    result=factorial(num1);
    if(result==-1)
        printf("Negative Input\n");
    else
        printf("Factorial of %d is: %d",num1,result);
    
    
    prime=isPrime(num2);
    if(prime==1)
        printf("%d is a prime number", num2);
    else if(prime==-1)
        printf("%d is a negative number\n", num2);
    else if(prime==0)
        printf("%d is not a prime number", num2);

    prime=isPalindrome(num3);
    if(prime==1)
        printf("%d is a palindrome");

    printf("Length of the string is %lu\n ",mystrlen(str1));

    printf("setting the value of %d in %d to %d \n",x,y,set(x,y));
    printf("setting the value of %d in %d to %d \n",x,y,clear(x,y));
    printf("flipping the value of %d in %d to %d \n",x,y,flip(x,y));

}