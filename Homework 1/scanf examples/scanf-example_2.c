/*
   Give this program lots of correct and incorrect input.
   Look at the kinds of results that you get.

   Be sure to try these experiments.

   At the first prompt, type Ctrl-Z (to close the input
   stream). What happens? Why?

   At the first prompt type one number and at the second
   prompt type one number, hit Enter, and then type Ctrl-Z
   (to close the input stream). Look carefully at the output.
   
   At the first prompt, type x and hit Enter. What happens?
   
   At the first prompt, type 42x and hit Enter. What happens?
*/
#include <stdio.h>

int main( )
{
   int x, y, z;

   printf("Please enter an integer: ");
   z = scanf("%d", &x);
   printf("The integer is = %d and scanf() returned %d\n", x, z);

   printf("Please enter two integers: \n");
   z = scanf("%d%d", &x, &y);
   printf("The integers are = %d, %d and scanf() returned %d\n", x, y, z);

   return 0;
}
