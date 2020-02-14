/*


*/

#include <windows.h>
#include <stdio.h>

// function prototype
void printError(char* functionName);


int main(void)
{
  HANDLE hProcess;
  HANDLE hThread;
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  DWORD dwProcessId = 0;
  DWORD dwThreadId = 0;
  ZeroMemory(&si, sizeof(si));
  ZeroMemory(&pi, sizeof(pi));
  BOOL bCreateProcess = NULL;
   int choice = 6;

   
   
     while (choice != 0)
     {
      printf("Please make a choice from the following list.\n");
      printf(" 0: Quit\n 1: Run Notepad\n 2: Run WordPad\n*3:Run cmd shell\n 4:Run Calculator\n 5:Run Explorer\nEnter your choice now:");
      scanf("%d", &choice);
      printf("%d\n", choice);
      if (choice == 1)
      // printf("%d\n", choice);
      {
         bCreateProcess = CreateProcess("C:\\WINDOWS\\system32\\notepad.exe",
         NULL,
         NULL,
         NULL,
         FALSE,
         0,
         NULL,
         NULL,
         &si,
         &pi);
         if (bCreateProcess == FALSE)
         {
            printf("Error\n");
            
         }
         printf("Started program 1 with pid = %d\n",pi.dwProcessId);
         // WaitForSingleObject(pi.hProcess,INFINITE);
         // CloseHandle(pi.hThread);
         // CloseHandle(pi.hProcess);
      }
     }

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
