package com.hand.json;

import com.google.gson.*;
import com.google.gson.reflect.TypeToken;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;

/**
 * Created by ljh on 2016/7/30.
 */
public class ParseJSON {
    public static void main(String args[]) {
//        parseList();
//        parseMap();
        parseMapList();
    }
    public static void readJsonFromFile() {
        try {
            JsonParser parser = new JsonParser();
            JsonObject object = (JsonObject) parser.parse(new FileReader("test.json"));
            System.out.println("cat = " + object.get("cat").getAsString());
            System.out.println("pop = " + object.get("pop").getAsBoolean());

            JsonArray array = object.get("languages").getAsJsonArray();

            for (int i = 0; i < array.size(); i++) {
                System.out.println("--------------------");
                JsonObject jo = array.get(i).getAsJsonObject();
                System.out.println("id = " + jo.get("id").getAsInt());
                System.out.println("name = " + jo.get("name").getAsString());
                System.out.println("ide = " + jo.get("ide").getAsString());

            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static void createJsonStr() {
        JsonObject jsonObject = new JsonObject();
        jsonObject.addProperty("cat", "it");

        JsonArray array = new JsonArray();
        JsonObject lan1 = new JsonObject();
        lan1.addProperty("id", 1);
        lan1.addProperty("name", "java");
        lan1.addProperty("ide", "Eclipse");
        array.add(lan1);

        JsonObject lan2 = new JsonObject();
        lan2.addProperty("id", 2);
        lan2.addProperty("name", "java");
        lan2.addProperty("ide", "Eclipse");
        array.add(lan2);

        JsonObject lan3 = new JsonObject();
        lan3.addProperty("id", 1);
        lan3.addProperty("name", "java");
        lan3.addProperty("ide", "Eclipse");
        array.add(lan3);

        jsonObject.add("languages", array);

        jsonObject.addProperty("pop", true);

        System.out.println(jsonObject);
    }
    /**
     * 简单的解析 JavaBean
     */
    public static void parseBean() {
        Gson gson = new Gson();

        Student stu1 = new Student(1, "张三", new Date(), false);
        System.out.println(stu1);
        // 简单的bean转为json
        String g1 = gson.toJson(stu1);
        System.out.println(g1);

        // 简单的json转为 bean
        Student stu2 = gson.fromJson(g1, Student.class);

        System.out.println(stu2);
    }

    /**
     * 将 List 转化为 Json数据
     */
    public static void parseList() {
        Gson gson = new Gson();

        List<Student> stus = new ArrayList<Student>();
        Student stu1 = new Student(1, "张三", new Date(), false);
        Student stu2 = new Student(2, "李四", new Date(201608080), true);
        Student stu3 = new Student(3, "王五", new Date(20150909), false);
        stus.add(stu1);
        stus.add(stu2);
        stus.add(stu3);

        // 带泛型的list转化为json
        String gs = gson.toJson(stus);
        System.out.println(gs);

        // json转为带泛型的list
        System.out.println("#########################");
        List<Student> stus_gson = gson.fromJson(gs,
                new TypeToken<List<Student>>(){}.getType());
        for(Student s : stus_gson) {
            System.out.println(s.toString());
        }
    }

    /**
     * 简单的 将 Map 的数据转化为 JSON
     */
    public static void parseMap() {
        Gson gson = new GsonBuilder().enableComplexMapKeySerialization().create();

        // 使用LinkedHashMap将结果按先进先出顺序排列
        Map<Integer, Student> map1 = new LinkedHashMap<Integer, Student>();
        map1.put(1000, new Student(1, "张三", new Date(), false));
        map1.put(1001, new Student(2, "李四", new Date(201608080), true));
        map1.put(1002, new Student(3, "王五", new Date(20150909), false));

        // map 转化为 json
        String s = gson.toJson(map1);
        System.out.println(s);

        System.out.println("-----------------");

        //  json 转化为 map
        Map<Integer, Student> retMap1 = gson.fromJson(s,
                new TypeToken<Map<Integer, Student>>(){}.getType());
        for(Integer i : retMap1.keySet()) {
            System.out.println("key: " + i + ", value:" + retMap1.get(i).toString());
        }

        System.out.println("########################");

                // 使用LinkedHashMap将结果按先进先出顺序排列
        Map<Student, Integer> map2 = new LinkedHashMap<Student, Integer >();
        map2.put(new Student(1, "张三", new Date(), false), 1000);
        map2.put(new Student(2, "李四", new Date(201608080), true), 1001);
        map2.put(new Student(3, "王五", new Date(20150909), false), 1002);

        // map 转化为 json
        String s2 = gson.toJson(map2);
        System.out.println(s2);

        System.out.println("-----------------");

        //  json 转化为 map
        Map<Student, Integer> retMap2 = gson.fromJson(s2,
                new TypeToken<Map<Student, Integer>>(){}.getType());
        for(Student st : retMap2.keySet()) {
            System.out.println("key: " + st.toString() + ", value:" + map2.get(st));
        }
    }

    /***
     * 将 Map<String, List>转化为 JSON
     */
    public static void parseMapList() {
        List<Student> stu_list = new ArrayList<Student>();
        stu_list.add(new Student(1, "张三", new Date(), false));
        stu_list.add(new Student(2, "李四", new Date(201608080), true));
        stu_list.add(new Student(3, "王五", new Date(20150909), false));

        Map<String, List> map = new LinkedHashMap<String, List>();
        map.put("students", stu_list);

        Gson gson = new Gson();
        String s = gson.toJson(map);

        System.out.println(s);
        System.out.println("-----------------");

        Map<String, List> retMap = gson.fromJson(s,
                new TypeToken<Map<String, List>>(){}.getType());
        for(String i : retMap.keySet()) {
            System.out.println("key: " + i + ", value: " + retMap.get(i).toString());
        }
    }
}
