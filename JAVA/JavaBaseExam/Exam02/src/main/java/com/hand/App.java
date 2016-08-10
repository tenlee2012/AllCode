package com.hand;

import java.util.Scanner;
/**
 * Author: tenlee
 * Date: 2016-07-29
 */
public class App {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入工资: ");
        double x = scan.nextDouble();
        double ans = 0;
        if(x > 3500) {
            ans = cal(x-3500);
        }
        System.out.println("所需要缴纳的税费为: " + ans);
    }
    public static double cal(double sal) {
        double tmp = sal, ans = 0.0;
        if(sal > 80000) {
            ans += (tmp - 80000) * 0.45;
            tmp = 80000;
        }
        if(tmp > 55000 && tmp <= 80000) {
            ans += (tmp - 55000) * 0.35;
            tmp = 55000;
        }
        if(tmp > 35000 && tmp <= 55000) {
            ans += (tmp - 35000) * 0.30;
            tmp = 35000;
        }
        if(tmp > 9000 && tmp <= 35000) {
            ans += (tmp - 9000) * 0.25;
            tmp = 9000;
        }
        if(tmp > 4500 && tmp <= 9000) {
            ans += (tmp - 4500) * 0.20;
            tmp = 4500;
        }
        if(tmp > 1500 && tmp <= 4500) {
            ans += (tmp - 1500) * 0.10;
            tmp = 1500;
        }
        if(tmp <= 1500) {
            ans += (tmp) * 0.03;
        }
        return ans;
    }
}

