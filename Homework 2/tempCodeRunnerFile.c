WaitForSingleObject(pi.hProcess,INFINITE);
         CloseHandle(pi.hThread);
         CloseHandle(pi.hProcess);