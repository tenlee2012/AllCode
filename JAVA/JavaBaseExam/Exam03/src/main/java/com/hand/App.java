package com.hand;

import java.util.Scanner;
/**
 * Author: tenlee
 * Date: 2016-07-29
 */

import java.util.Scanner;

/**
 * Author: tenlee
 * Date: 2016-07-29
 */
public class App {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入日期: ");
        String date_str = scan.next();
        if(!check(date_str)) {
            System.out.println("你输入的日期格式不正确!!");
            return;
        }
        System.out.println("你输入的日期为当年的第 " + slove(date_str) + " 天");
    }

    /**
     * 计算第几天
     * @param str
     * @return
     */
    public static int slove(String str) {
        String ds[] = str.split("-");
        int year = Integer.parseInt(ds[0]);
        int month = Integer.parseInt(ds[1]);
        int day = Integer.parseInt(ds[2]);
        int tmp = 1;
        int sum = 0;
        while(tmp < month) {
            sum += calMonthDays(year, tmp);
            tmp++;
        }
        sum += day;
        return sum;
    }

    /**
     * 检查日期格式是否正确
     * @param str
     * @return
     */
    public static boolean check(String str) {
        if(str.length() != 10) {
            return false;
        }
        String da[] = str.split("-");
        if(da.length != 3) {
            return false;
        }
        if(da.length == 3) {
            int year = Integer.parseInt(da[0]);
            int month = Integer.parseInt(da[1]);
            int day = Integer.parseInt(da[2]);
 
            if(year <= 0) {
                return false;
            }
            if(month <= 0 || month > 12) {
                return false;
            }
            int days = calMonthDays(year, month);
            if(day <= 0 || day > days) {
                return false;
            }
        }
        return true;
    }

    /**
     * 判断是否是闰年
     * @param year
     * @return
     */
    public static boolean isRunYear(int year) {
        if((year % 4 == 0 && year % 100 != 0)
                || (year % 400 == 0)) {
            return true;
        }
        return false;
    }

    /**
     * 计算该年月有多少天
     * @param year
     * @param month
     * @return
     */
    public static int calMonthDays(int year, int month) {
        if(month == 1) return 31;
        if(month == 2 && isRunYear(year)) return 29;
        if(month == 2 && !isRunYear(year)) return 28;
        if(month == 3) return 31;
        if(month == 4) return 30;
        if(month == 5) return 31;
        if(month == 6) return 30;
        if(month == 7) return 31;
        if(month == 8) return 31;
        if(month == 9) return 30;
        if(month == 10) return 31;
        if(month == 11) return 30;
        if(month == 12) return 31;
        return 0;
    }
}

