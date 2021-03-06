#include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
int main() 
{ 
	int fd1; 
	char * fifo1 = "/tmp/fifo1"; 
	mkfifo(fifo1, 0666); 
	char input1[100], input2[100]; 
	while (1) 
	{  
		fd1 = open(fifo1,O_RDONLY); 
		read(fd1, input1, 100);  
		printf("Text input by Sender: %s\n", input1); 
		close(fd1); 
		fd1 = open(fifo1,O_WRONLY); 
		fgets(input2, 100, stdin); 
		write(fd1, input2, strlen(input2)+1); 
		close(fd1); 
	} 
	return 0; 
} 
