#include <stdio.h>
#include<time.h>
int main() 
{
int c;clock_t star,end;double timex;
star=clock();
/*DO THE WORK HERE*/

// 
end=clock();
timex=((double)(end-star))/CLOCKS_PER_SEC;
printf("%lf",timex);
return 0;
}