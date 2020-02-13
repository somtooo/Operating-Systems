/*
   This example shows that "prompting" a user and scanning
   input are not really connected to each other.

   At the "prompt" enter several numbers. What happens?
   Uncomment line 21, and then enter several numbers at a prompt.
   What happens? Why?
*/
import java.util.Scanner;

class Scanner_Example_3
{
   public static void main(String[] args)
   {
      Scanner sc = new Scanner(System.in);

      System.out.print("Please enter a number: ");
      double x = sc.nextDouble();
      while( true )
      {
         //System.out.println(x);

         System.out.print("Please enter a number: ");
         x = sc.nextDouble();
      }
   }
}
