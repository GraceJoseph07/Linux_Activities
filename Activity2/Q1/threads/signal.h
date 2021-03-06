#ifndef __SIGNAL_H
#define __SIGNAL_H

#include <signal.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 

  
void childprocess();
void sighup(); 
void sigint(); 
void sigquit(); 
#endif