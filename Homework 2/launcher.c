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
  RECT rectDesktop;
  GetClientRect(GetDesktopWindow(), &rectDesktop);
  ZeroMemory(&si, sizeof(si));
  ZeroMemory(&pi, sizeof(pi));
  BOOL bCreateProcess = NULL;
  int choice = 6;
  DWORD dwCode;
  char notePad[50],wordPad[50],cmd[50],calculator[50],explorer[50];
  sprintf(notePad,"%s\\system32\\notepad.exe",getenv("WINDIR"));
  sprintf(cmd,"%s\\system32\\cmd.exe",getenv("WINDIR"));
  sprintf(calculator,"%s\\system32\\calc.exe",getenv("WINDIR"));
  sprintf(explorer,"%s\\explorer.exe",getenv("WINDIR"));
  sprintf(wordPad,"%s\\Windows NT\\Accessories\\wordpad.exe",getenv("programfiles"));
 
   
     while (choice != 0)
     {
      printf("Please make a choice from the following list.\n");
      printf(" 0: Quit\n 1: Run Notepad\n 2: Run WordPad\n*3:Run cmd shell\n 4:Run Calculator\n 5:Run Explorer\nEnter your choice now:");
      scanf("%d", &choice);
      printf("%d\n", choice);
      if (choice == 3)
      {
         si.dwX = si.dwXSize = (rectDesktop.left);
         si.dwY = si.dwYSize = (rectDesktop.top);
         si.dwFlags = STARTF_USEFILLATTRIBUTE|STARTF_USEPOSITION | STARTF_USESIZE;
         si.lpTitle = "Whats your command";
         si.dwFillAttribute=FOREGROUND_BLUE| BACKGROUND_RED| BACKGROUND_GREEN| BACKGROUND_BLUE;
         putenv("PROMPT=Speak to me>");
         
         bCreateProcess = CreateProcess(cmd,
         NULL,
         NULL,
         NULL,
         FALSE,
         CREATE_NEW_CONSOLE,
         NULL,
         NULL,
         &si,
         &pi);
         if (bCreateProcess == FALSE)
         {
            printError("CreateProcess");
            
         }
         printf("Started program 1 with pid = %d\n",pi.dwProcessId);
         WaitForSingleObject(pi.hProcess,INFINITE);
         // CloseHandle(pi.hThread);
         // CloseHandle(pi.hProcess);
         if(GetExitCodeProcess(pi.hProcess, &dwCode))
            printf("After terminated, code = %X\n", dwCode);
         else
           printError("GetExitCodeProcess");
      }
      
      else if (choice == 1)
      {
         bCreateProcess = CreateProcess(notePad,
         NULL,
         NULL,
         NULL,
         FALSE,
         CREATE_NEW_CONSOLE,
         NULL,
         NULL,
         &si,
         &pi);
         if (bCreateProcess == FALSE)
         {
            printError("CreateProcess");
            
         }
         printf("Started program 1 with pid = %d\n",pi.dwProcessId);
      }
      else if (choice == 2)
      {
         bCreateProcess = CreateProcess(wordPad,
         NULL,
         NULL,
         NULL,
         FALSE,
         CREATE_NEW_CONSOLE,
         NULL,
         NULL,
         &si,
         &pi);
         if (bCreateProcess == FALSE)
         {
            printError("CreateProcess");
            
         }
         printf("Started program 1 with pid = %d\n",pi.dwProcessId);
      }
      else if (choice == 4)
      {
         bCreateProcess = CreateProcess(calculator,
         NULL,
         NULL,
         NULL,
         FALSE,
         CREATE_NEW_CONSOLE,
         NULL,
         NULL,
         &si,
         &pi);
         if (bCreateProcess == FALSE)
         {
            printError("CreateProcess");
            
         }
         printf("Started program 1 with pid = %d\n",pi.dwProcessId);
      }
      else if (choice == 5)
      {
         bCreateProcess = CreateProcess(explorer,
         NULL,
         NULL,
         NULL,
         FALSE,
         CREATE_NEW_CONSOLE,
         NULL,
         NULL,
         &si,
         &pi);
         if (bCreateProcess == FALSE)
         {
            printError("CreateProcess");
            
         }
         printf("Started program 1 with pid = %d\n",pi.dwProcessId);
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

