import java.util.*;

class Main {
    public static void main(String args[]) {

         Scanner sc = new Scanner(System.in);
         String str = sc.nextLine();
         String[] S = str.split("\\.");
         int a1 = Integer.parseInt(S[0]);
         int a2 = Integer.parseInt(S[1]);
         int a3 = Integer.parseInt(S[2]);
         int a4 = Integer.parseInt(S[3]);
         if( a1>255 || a2>255 || a3>255 || a4>255)
             System.out.println("Invalid");
         else
             System.out.println("Valid");
    }
}