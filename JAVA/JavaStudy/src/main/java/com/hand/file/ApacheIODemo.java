package com.hand.file;

import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;

/**
 * Created by ljh on 2016/7/28.
 */
public class ApacheIODemo {
    public static void main(String[] args) {
        try {
            String s = FileUtils.readFileToString(new File("hello.txt"));
            FileUtils.copyFile(new File("hello.txt"),
                    new File("hello_tmp.txt"));
            System.out.println(s);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
