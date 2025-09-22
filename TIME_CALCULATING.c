#include <stdio.h>
#include<time.h>

int main() 
{
  int c; clock_t start,end;double timex;
  start=clock();
  /*DO THE WORK HERE*/

  // 
  end=clock();
  timex=((double)(end-start))/CLOCKS_PER_SEC;
  
  printf("%lf",timex);
  return 0;
}