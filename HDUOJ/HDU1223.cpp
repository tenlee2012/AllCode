import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BigInteger[][] f=new BigInteger[51][51];
    public static void main(String[] args) throws FileNotFoundException {
        Scanner cin=new Scanner(System.in);
        init();
        f[1][1]=BigInteger.valueOf(1);
        for(int i=2;i<=50;i++){
            for(int j=1;j<=i;j++){
                f[i][j]=f[i-1][j].add(f[i-1][j-1]).multiply(BigInteger.valueOf(j));
            }
        }
        int t=cin.nextInt();
        while(t--!=0){
            int n=cin.nextInt();
            println(n);
        }

    }
    static void init(){
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++)
            f[i][j]=BigInteger.ZERO;
        }
    }
    static void  println(int n){
        BigInteger big=BigInteger.ZERO;
        for(int i=1;i<=n;i++)
            big=big.add(f[n][i]);
        System.out.println(big.toString());
    }
}