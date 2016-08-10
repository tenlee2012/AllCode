package com.hand;


import java.util.*;

/**
 * Created by tenlee on 16-7-29.
 */
public class App {
    public static void main(String[] args) {
        Random rm = new Random();
        List<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < 50; i++) {
            list.add(rm.nextInt(100));
        }
        System.out.print("随机生成的50个小于100的数,分别为:");

        Map<Integer, List> map = new HashMap<Integer, List>();
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));
            if (i != 49) System.out.print(", ");

            int t = list.get(i) / 10;

            if (map.get(t) == null) {
                List<Integer> tmp = new ArrayList<Integer>();
                tmp.add(list.get(i));
                map.put(t, tmp);
            } else {
                map.get(t).add(list.get(i));
            }
        }
        System.out.print("\n");
        System.out.print("Map中的数据为:");
        printMap(map);

        for(int i = 0; i < 10; i++) {
            if(map.get(i) != null) {
                mySort(map.get(i));
            }
        }
        System.out.print("排序后Map中的数据为:");
        printMap(map);
    }

    public static void printMap(Map<Integer, List> map) {
        System.out.print("{");
        for (int i = 0; i < 10; i++) {
            if (map.get(i) != null) {
                System.out.print(i + "=>[");
                List<Integer> list_tmp = map.get(i);
                for (int j = 0; j < list_tmp.size(); j++) {
                    System.out.print(list_tmp.get(j));
                    if (j != (list_tmp.size() - 1))
                        System.out.print(",");
                }
                System.out.print("],");
            }
        }
        System.out.print("}\n");
    }
    public static void mySort(List<Integer> list) {
        int arr[] = new int[100];
        int size = 0;
        for(size = 0; size < list.size(); size++) {
            arr[size] = list.get(size);
        }
        for(int i = 0; i < size; i++) {
            for(int j = i; j < size; j++) {
                if(arr[i] > arr[j]) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        list.clear();
        for(int i = 0; i < size; i++) {
            list.add(arr[i]);
        }
    }
}

