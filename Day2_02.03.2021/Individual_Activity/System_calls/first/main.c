#include "copy.h"

int main()
{
  int a;
  a = copyfile();
  switch(a)
  {
    case 0:
        printf("Content copied successfully\n");
        break;
    case 1:
        printf("No content copied\n");
        break;
  }
  return 0;
}