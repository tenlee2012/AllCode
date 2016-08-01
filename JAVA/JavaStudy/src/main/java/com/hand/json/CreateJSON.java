package com.hand.json;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;

/**
 * Created by ljh on 2016/7/30.
 */
public class CreateJSON {
    public static void main(String args[]) {
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
    public static void create() {

    }
}
