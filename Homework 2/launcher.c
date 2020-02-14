/*


*/

#include <windows.h>
#include <stdio.h>

// function prototype
void printError(char* functionName);


int main(void)
{
  
   int choice = -1;
   while( choice != 0 )
   {
     
      printf("Please make a choice from the following list.\n");
      printf(" 0: Quit\n 1: Run Notepad\n 2: Run WordPad\n*3:Run cmd shell\n 4:Run Calculator\n 5:Run Explorer\nEnter your choice now:");
      choice = scanf("%d", &choice);
   }

   return 0;





   return 0;
}



/****************************************************************
   The following function can be used to print out "meaningful"
   error messages. If you call a Win32 function and it returns
   with an error condition, then call this function right away and
   pass it a string containing the name of the Win32 function that
   failed. This function will print out a reasonable text message
   explaining the error and then (if chosen) terminate the program.
*/
void printError(char* functionName)
{
   LPVOID lpMsgBuf;
   int error_no;
   error_no = GetLastError();
   FormatMessage(
         FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
         NULL,
         error_no,
         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
         (LPTSTR) &lpMsgBuf,
         0,
         NULL
   );
   // Display the string.
   fprintf(stderr, "\n%s failed on error %d: ", functionName, error_no);
   fprintf(stderr, (char*)lpMsgBuf);
   // Free the buffer.
   LocalFree( lpMsgBuf );
   //ExitProcess(1);  // terminate the program
}//printError
