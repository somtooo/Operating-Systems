/*
   Compile and run this program. When propted for an integer,
   enter
   1a 2
   and hit the return key. What happens? Why?
*/
import java.util.Scanner;

class Scanf_vs_Scanner
{
   public static void main(String[] args)
   {
      Scanner sc = new Scanner(System.in);

      System.out.printf("Please enter an integer:\n");
      int x = sc.nextInt();
      System.out.printf("x = %d\n", x);

      System.out.printf("Please enter an integer:\n");
      int y = sc.nextInt();
      System.out.printf("y = %d\n", y);
   }
}
