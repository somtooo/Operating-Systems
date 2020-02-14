#include <windows.h>
#include <stdio.h> 


int main(void){
    int choice = 6;
    while (choice != 0)
    {
        printf("%d\n", choice);
        printf("Please make a choice from the following list.\n");
        // printf(" 0: Quit\n 1: Run Notepad\n 2: Run WordPad\n*3:Run cmd shell\n 4:Run Calculator\n 5:Run Explorer\nEnter your choice now:");
        choice = scanf("%d", &choice);
        
    }


    return 0;

  printf("Please enter a number: ");
   double x;
   int rv = scanf("%lf", &x);
   while( rv > 0 )
   {
      printf("%f\n", x);

      printf("Please enter a number: ");
      rv = scanf("%lf", &x);
   }
}


