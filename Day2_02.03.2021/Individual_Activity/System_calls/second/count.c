#include "count.h"
int lines, characters, words;

void checkfile()
{
	int fd,nbytes;
	char ch[16384];
    fd=open("file1.txt",O_RDONLY);

	if(fd<0){
		perror("open");
		exit(1);
	}

    words = 0,lines = 0;
    while(nbytes=read(fd,ch,sizeof(ch))){
        for(int i=0;i<nbytes;i++){
            // Checking for new lines 
            if (ch[i] == '\n')
               lines++;
            // Checking words in the document
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               words++;
        }
        characters=nbytes;
    }
    /* Close files to release resources */
    close(fd);
}
//returns number of lines
int getLinesNo(){
  return lines;
}
//returns the number of characters
int getCharactersNo(){
  return characters;
}
//returns the number of words
int getWordsNo(){
  return words;
}