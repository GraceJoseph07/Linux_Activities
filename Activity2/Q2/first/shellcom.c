
#include "shellcom.h"

#define BUFFER_LEN 1024

void MinShell() {
  char line[BUFFER_LEN]; 
  char *argv[100];       
  char *path = "/bin/";  
  char progpath[20];     
  int argc,i = 0;             

  while (1) {
    printf("My minshell>> "); 
    if (!fgets(line, BUFFER_LEN, stdin))
      break;

    size_t length = strlen(line);
    if (line[length - 1] == '\n')
      line[length - 1] = '\0';
    if (strcmp(line, "exit") == 0) { 
      break;
    }

    char *token; 
    token = strtok(line, " ");
    while (token != NULL) {
      argv[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    argv[i] = NULL; 
    argc = i; 
    for (i = 0; i < argc; i++) {
      printf("%s\n", argv[i]); 
    }
    strcpy(progpath, path);    
    strcat(progpath, argv[0]); 
    for (i = 0; i < strlen(progpath); i++){ 
      if (progpath[i] == '\n') {
        progpath[i] = '\0';
      }
    }
    int pid = fork(); 
    if (pid == 0) { 
      execvp(progpath, argv);
      fprintf(stderr, "execvp failed in execvp\n");
    } 
    else { // Parent
      wait(NULL);
      printf("Exit from child process\n");
    }
  }
}