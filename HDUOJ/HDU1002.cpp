import java.util.*;
import java.math.*;

public class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int t;
        BigInteger a,b;
        t = cin.nextInt();
        int cases = 0;
        while(t != 0){
            t--;
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            System.out.println("Case " + (++cases) +":");
            System.out.println(a + " + " + b + " = " + a.add(b));
            if(t != 0)
                System.out.println();
        }
    }
}