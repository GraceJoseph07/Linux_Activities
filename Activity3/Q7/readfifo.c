#include"chat.h"
void main()
{
    char input[300]="start";
    int fifo_write,fifo_read;
    while(strcmp(input,"end")!=0)
    {
        fifo_write= open("pipeA",O_WRONLY);
        if(fifo_write<0)
            printf("\nError opening pipe");
        else
        {
            printf("chat1: "); 
            scanf("%s",input);
            write(fifo_write,input,299*sizeof(char));
            close(fifo_write);
        }
        fifo_read=open("pipeB",O_RDONLY);
        if(fifo_read<0)
            printf("\nError opening write pipe");
        else
        {
            read(fifo_read,input,299*sizeof(char));
            close(fifo_read);
            printf("\n%s",input);
        }
    }
}
