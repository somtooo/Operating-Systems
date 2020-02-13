/*
   This program reads one character at a time from standard input,
   converts all lower case letters to upper case, all upper case
   letters to lower case, and writes them to standard output.

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
      if ( 'a' <= c && c <= 'z' )
      {
         c -= 32;
      }
      else if ( 'A' <= c && c <= 'Z' )
      {
         c += 32;
      }
      printf("%c", c);
      fflush(stdout);
   }
   return 0;
}