package com.hand;
/**
 * Author: tenlee
 * Date: 2016-07-29
 */
public class App {
    public static void main(String[] args) {
        int primes[] = new int[100];
        int j = 0;
        for(int i = 101; i <= 200; i++) {
            if(isPrime(i)) {
                primes[j++] = i;
            }
        }
        System.out.print("101-200间共有" + j + "个素数,分别是:");
        for(int i = 0; i < j; i++) {
            System.out.print(primes[i]);
            if(i != (j-1))
                System.out.print(", ");
        }
        System.out.print("\n");
    }
    /**
     *判断一个数是否是素数
     */
    public static boolean isPrime(int num) {
        for(int i = 2; i <= Math.sqrt(num); i++) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

