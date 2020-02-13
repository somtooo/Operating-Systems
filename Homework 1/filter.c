/*
*/
#include <stdio.h>   // scanf(), fscanf(), fprintf(), fopen()
#include <stdlib.h>  // atoi(), getenv()

int main(int argc, char* argv[])
{
  float numbers[10000]; 
  int totalNumberOfElements = 0;
  int numOfColumns = 3;
  int numOfRow;
  char* pPath;
  char* pPath2;
  int numFromConfigFile;
  int numFromConfigForPrecision;
  int precision = 13;

// config file configuration
  FILE * configFile;
  configFile = fopen("filter.cfg","r");
  if (configFile != NULL)
  {
    fscanf(configFile,"%d",&numFromConfigFile);
    fscanf(configFile,"%d",&numFromConfigForPrecision);
    numOfColumns = numFromConfigFile;
    precision = numFromConfigForPrecision;
    // printf("%s",precision);
  }
  
 
//environment variable configuration
  pPath = getenv ("cs302HW1COLUMNS");
  pPath2 = getenv("CS302HW1PRECISION");
  if (atoi(pPath) != 0){
      // printf("%s",pPath);
      numOfColumns= atoi(pPath);
      // printf("%d",numOfColumns);
  }
  if (atoi(pPath2)!=0){
    // printf("%s",pPath2);
    precision= atoi(pPath2);
      // printf("%d",precision);
    
  }

  //command line varible configuration
   int numOfColumnsFromCommandLine = atoi(argv[1]);
   int temp2Precision = atoi(argv[2]);
   if (numOfColumnsFromCommandLine != 0)
   {
     numOfColumns = numOfColumnsFromCommandLine;
   }
   if (temp2Precision != 0)
   {
     precision = temp2Precision;
   }
   
    
  
  for (int i = 0; i < 69; i++)
  {
      scanf ("%f \n",&numbers[i]);
      if ((int)numbers[i]!=0)
     {
       totalNumberOfElements++;
     }
  }

numOfRow = (totalNumberOfElements/numOfColumns)*numOfColumns;
  
  for (int j = 0; j < numOfRow; j+=numOfColumns)
  {
    printf("\n");
    int rowCounter = j + numOfColumns;
     for (int i = j; i<rowCounter; i++)
   { 
     if ((int)numbers[i]!=0)
     {
 printf ("%.*f  ",precision,numbers[i]);
     }
   }
  }

   return 0;
}
