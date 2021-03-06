#include "copy.h"

int copyfile()
{
	int fd,fd1,nbytes, flag,maxlen=128;
	char buf[maxlen];
	fd=open("file1.txt",O_RDONLY);
	fd1=open("file2.txt",O_WRONLY|O_CREAT, 0666);
	//checking if data is present in the files
	if(fd<0 || fd1<0)
	{
		perror("open");
		exit(1);
	}
	nbytes=read(fd,buf,maxlen);
	//reading the file content
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	//writing the contents copied from file1
	flag = write(fd1,buf,nbytes);
	close(fd);
	close(fd1);
	if(flag)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}