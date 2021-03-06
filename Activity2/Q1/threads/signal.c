#include "signal.h"

void childprocess()
{ 
    int pid; 
  
    //create child process
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; 
    } 
  
    else
    { 
        printf("\nPARENT: SIGHUP printed\n\n"); 
        kill(pid, SIGHUP); // kill the respective process
  
        sleep(3); // process sleeps for 3 seconds
        printf("\nPARENT: SIGINT sent\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); // process sleeps for 3 seconds
        printf("\nPARENT: SIGQUIT sent\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 

void sighup()   
{ 
    signal(SIGHUP, sighup); 
    printf("CHILD: SIGHUP received\n"); 
} 

void sigint() 
  
{ 
    signal(SIGINT, sigint); 
    printf("CHILD: SIGINT received\n"); 
} 
  
void sigquit() 
{ 
    printf("Child process killed by parent\n"); 
    exit(0); 
} 