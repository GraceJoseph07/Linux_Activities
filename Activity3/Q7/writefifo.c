#include"chat.h"
void main() 
{
    int fd;
    fd = mkfifo("pipe1",0666);
    if(fd<0)
        printf("\nError in creation of Pipe1");
    else
        printf("\nPipe1 created successfully");
    int fd1;
    fd1 = mkfifo("pipe2",0666);
    if(fd1<0)
        printf("\nError in creation of Pipe2");
    else
        printf("\nPipe2 created successfully\n");
}
