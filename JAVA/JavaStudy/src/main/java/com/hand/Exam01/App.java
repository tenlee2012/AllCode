package com.hand.Exam01;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import java.io.*;

/**
 * Created by ljh on 2016/8/1.
 */
public class App {
    public static void main(String args[]) {
        new Get().start();
    }
}

class Get extends Thread {
    HttpClient client = HttpClients.createDefault();

    @Override
    public void run() {
        HttpGet get = new HttpGet("http://files.saas.hand-china.com/java/target.pdf");
        try {

            HttpResponse response = client.execute(get);
            HttpEntity entity = response.getEntity();
            byte[] result = EntityUtils.toByteArray(entity);

            FileOutputStream fow = new FileOutputStream("target.pdf");
            BufferedOutputStream bos = new BufferedOutputStream(fow);
            bos.write(result);
            System.out.println("Write Success");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
