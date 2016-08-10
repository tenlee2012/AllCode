package com.hand.utils;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by ljh on 2016/8/6.
 */
public class PageUtil {
    public static final int PAGE_SHOW_NUM = 9;

    public static void main(String args[]) {
        System.out.println(pageAlgorithm(3, 20));
    }

    public static List<Integer> pageAlgorithm(int nowPage, int totalPage) {
        int left, right;
        if(nowPage > 5) {
            left = nowPage - PAGE_SHOW_NUM / 2;
        } else {
            left = 1;
        }
        right = PAGE_SHOW_NUM /2 + nowPage;
        if(right > totalPage) {
            right = totalPage;
        }
        List<Integer> pager = new ArrayList<>();
        if(left != 1) pager.add(1);
        for(int i = left; i <= right; i++) {
            pager.add(i);
        }
        if(right != totalPage) pager.add(totalPage);
        return pager;
    }
}
