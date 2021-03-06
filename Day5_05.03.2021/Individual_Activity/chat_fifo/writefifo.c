 #include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
 
 int main(){ 
	int fd;  
	char * fifo1 = "/tmp/fifo1";  
	mkfifo(fifo1, 0666); 
	char arr1[100], arr2[100]; 
	while (1) 
	{ 
		fd = open(fifo1, O_WRONLY); 
		fgets(arr2, 100, stdin); 
		write(fd, arr2, strlen(arr2)+1); 
		close(fd); 
		fd = open(fifo1, O_RDONLY);  
		read(fd, arr1, sizeof(arr1)); 
		printf("Text received by receiver: %s\n", arr1); 
		close(fd); 
	} 
	return 0; 
} 
