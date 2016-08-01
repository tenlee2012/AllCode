package com.hand.net;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by ljh on 2016/8/1.
 */
public class ApacheHttpDemo {
    public static void main(String args[]) {
//        new Get().start();
        new Post().start();
    }
}

class Get extends Thread {
    HttpClient client = HttpClients.createDefault();

    @Override
    public void run() {
        HttpGet get = new HttpGet("http://www.baidu.com");
        try {

            HttpResponse response = client.execute(get);
            HttpEntity entity = response.getEntity();
            String result = EntityUtils.toString(entity, "UTF-8");

            FileOutputStream fow = new FileOutputStream("baidu1.html");
            OutputStreamWriter fosw = new OutputStreamWriter(fow);
            BufferedWriter fbw = new BufferedWriter(fosw);
            fbw.write(result);

            fbw.close();
            fosw.close();
            fow.close();
            System.out.println("文件写入成功");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Post extends Thread {
    HttpClient client = HttpClients.createDefault();
    @Override
    public void run() {
        HttpPost post = new HttpPost("https://accounts.douban.com/login");
        try {
            client.execute(post);
            List<BasicNameValuePair> params = new ArrayList<BasicNameValuePair>();
            params.add(new BasicNameValuePair("form_email", "fuck"));
            params.add(new BasicNameValuePair("form_password", "fuck"));

            post.setEntity(new UrlEncodedFormEntity(params, "UTF-8"));

            HttpResponse response = client.execute(post);
            HttpEntity entity = response.getEntity();
            String result = EntityUtils.toString(entity, "UTF-8");

            FileOutputStream fow = new FileOutputStream("baidu1.html");
            OutputStreamWriter fosw = new OutputStreamWriter(fow);
            BufferedWriter fbw = new BufferedWriter(fosw);
            fbw.write(result);

            fbw.close();
            fosw.close();
            fow.close();
            System.out.println("文件写入成功");
        } catch (IOException e) {
            e.printStackTrace();
        }
        ;

    }
}
