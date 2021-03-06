#include<stdio.h>
#include<string.h>
#include"mystring.h"
int strlen(char* str1){
    if (*str1 == '\0') // Base condition
        return 0;
    return (1 + string_length(++str1));
}

char* mystrcpy(char* str1){
    char* str2=*str1;
    return *str2;
}

char* mystrcat(char* str1,char* str2){
    char* str3= *str1+ *str2;
    return *str3;
}

int mystrcmp(char* str1, char* str2){
    if(*str1==*str2)
        return 1;
    return 0;
} 
