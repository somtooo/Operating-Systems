/*
   A simple demonstration of using environment variables
   (and command line arguments).

   See
      http://docs.oracle.com/javase/6/docs/api/java/lang/System.html#getenv(java.lang.String)
*/

public class EnvironmentVariables
{
   public static void main(String[] args)
   {
      // walk the args array and look for environment variables
      for (int i = 0; i < args.length; i++)
      {
         String value = System.getenv( args[i] );
         if ( value == null )
         {
            System.out.println( args[i] + " is not an environment variable." );
         }
         else
         {
            System.out.println( "The value of " + args[i] + " is " + value );
         }
      }
   }//main()
}