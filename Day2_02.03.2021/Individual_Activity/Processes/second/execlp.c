#include "execlp.h"

void compile()
{
    pid_t pid=fork();
    int k;
    if (pid==0){ 
    	k=execlp("gcc","gcc",",hi.c","-o", "hi.out",NULL);
        exit(127); 
    }
    else{
    	waitpid(pid,0,0); 
    	printf("Parent Process: \n");
    }
}