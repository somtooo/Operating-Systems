/*
   Compile and run this program. When propted for an integer,
   enter
   1a 2
   and hit the return key. What happens? Why?
*/
#include <stdio.h>   // for scanf(), printf()

int main( )
{
   int x = -1, y = -1;

   printf("Please enter an integer:\n");
   scanf("%d", &x);
   printf("x = %d\n", x);

   printf("Please enter an integer:\n");
   scanf("%d", &y);
   printf("y = %d\n", y);

   return 0;
}
