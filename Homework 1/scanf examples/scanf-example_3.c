/*
   This example shows that "prompting" a user and scanning
   input are not really connected to each other.

   At the "prompt" enter several numbers. What happens?
   Uncomment line 19, and then enter several numbers at a prompt.
   What happens? Why?
*/
#include <stdio.h>  // printf(), scanf()

int main()
{
   printf("Please enter a number: ");
   double x;
   int rv = scanf("%lf", &x);
   while( rv > 0 )
   {
      printf("%f\n", x);

      printf("Please enter a number: ");
      rv = scanf("%lf", &x);
   }

   return 0;
}
