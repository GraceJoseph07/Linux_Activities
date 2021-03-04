#include "count.h"
int main()
{
  printf("Check for file contents\n");
  checkfile();
  printf("Number of lines : %d\n", getLinesNo());
  printf("Number of words : %d\n", getWordsNo());
  printf("Number of characters : %d\n", getCharactersNo());
}