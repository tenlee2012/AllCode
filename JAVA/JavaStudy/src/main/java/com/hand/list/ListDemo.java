package com.hand.list;

import java.util.*;

/**
 * Created by ljh on 2016/7/27.
 */
public class ListDemo{
    public static void main(String[] args) {
        List<String> lists = null;

        lists = new ArrayList<>();
        lists.add("1haha");
        lists.add("5haha");
        lists.add("3haha");
        lists.add(1, "4hehe");
        lists.remove(2);
        lists.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.compareTo(o1);
            }
        });

        for(String i : lists) {
            System.out.println(i);
        }
//        System.out.println("----------------");
//        for(int i = 0; i < lists.size(); i++) {
//            System.out.println(lists.get(i));
//        }
//        System.out.println("----------------");
//        Iterator<String> it = lists.iterator();
//        while(it.hasNext()) {
//            System.out.println(it.next());
//        }
        List<Person> ps = new ArrayList<>();
        Set<Person> s = new HashSet<>();
        ps.add(new Person("ACA"));
        ps.add(new Person("AAA"));
        ps.add(new Person("ABA"));
        ps.sort(new Person());

        s.add(new Person("ACA"));
        s.add(new Person("AAA"));
        s.add(new Person("ABA"));
        for(Person p : s) {
            System.out.println(p);
        }
        System.out.println("----------------");
        for(Person p : ps) {
            System.out.println(p);
        }
    }
}

class Person implements Comparator<Person>, Comparable<Person>{
    private String name;

    public Person() {
    }

    public Person(String name) {
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    @Override
    public int compare(Person o1, Person o2) {
        return o1.compareTo(o2);
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                '}';
    }

    @Override
    public int compareTo(Person o) {
        return this.name.compareTo(o.getName());
    }
}
