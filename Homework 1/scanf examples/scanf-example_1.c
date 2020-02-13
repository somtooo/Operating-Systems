/*
   Compile and run this program. Try many different ways of
   inputting what the program asks for. Try putting each input
   on its own line. Try putting all the inputs on a single line.
   Notice that it does not make any difference. Every C program
   sees it input as a single "stream" of characters. The CR key
   that marks the end of a line is just another character in the
   stream. Each  call to scanf() reads just what is supposed to
   from the input stream, and leaves the rest of the stream
   for the next call to scanf().

   Run this program using I/O redirection with the accompanying input
   file, input.txt. That is, run this program using the command-line
         C:\> scanf-example_1.exe  <  input.txt
   Notice how this program reads its input from a file without any
   obvious reference to file I/O in the C source code.

   Run this program again with I/O redirection of both the input and
   the output, like this.
         C:\> scanf-example_1.exe  <  input.txt  >  output.txt
   Notice how this program con also write to a file without any
   reference to file I/O in the C source code. I/O redirection is a
   very powerful operating system concept.
*/
#include <stdio.h>   // for scanf(), printf()
#include <string.h>  // for strlen()

int main( )
{
   int x, y, z;
   char s1[10];
   char s2[10];

   printf("Please enter three integers:\n");
   scanf("%d%d%d", &x, &y, &z);
   printf("Their sum is = %d\n", x+y+z);

   printf("\n");  // print a blank line

   printf("Please enter two integers:\n");
   scanf("%d%d", &x, &y);
   printf("Their sum is = %d\n", x+y);

   printf("\n");  // print a blank line

   printf("Please enter a short string:\n");
   scanf("%s", s1);
   printf("The length of your string = %d\n", strlen(s1));

   printf("\n");  // print a blank line

   printf("Please enter two short strings:\n");
   scanf("%s%s", s1, s2);
   printf("The length of your first string  = %d\n", strlen(s1));
   printf("The length of your second string = %d\n", strlen(s2));

   return 0;
}
