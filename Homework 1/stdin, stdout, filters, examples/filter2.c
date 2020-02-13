/*
   This program reads one character at a time from standard input, and
   then writes each upper case character twice to standard output.

   When using Windows, if standard input is the console
   keyboard, use ^z (Ctrl-z) to denote the end of file
   (and you must use ^z at the beginning of a line!).
*/
#include <stdio.h>

int main()
{
   int c;
   while ( (c = getchar()) != EOF )
   {
      if ( 'A' <= c && c <= 'Z' )  // check for upper case
      {
         printf("%c", c);  // print once
      }
      printf("%c", c);     // and (maybe) print again
   }
   return 0;
}
