package com.hand.json;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Created by ljh on 2016/7/30.
 */
public class ReadJSON {
    public static void main(String args[]) {
        try {
            JsonParser parser = new JsonParser();
            JsonObject object = (JsonObject) parser.parse(new FileReader("test.json"));
            System.out.println("cat = " + object.get("cat").getAsString());
            System.out.println("pop = " + object.get("pop").getAsBoolean());

            JsonArray array = object.get("languages").getAsJsonArray();

            for(int i = 0; i < array.size(); i++) {
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
}
