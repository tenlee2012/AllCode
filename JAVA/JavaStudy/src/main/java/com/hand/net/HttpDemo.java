package com.hand.net;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

/**
 * Created by ljh on 2016/8/1.
 */
public class HttpDemo {
    public static void main(String args[]) {
        new ReadByGet().start();
        new ReadPost().start();
    }

    static class ReadByGet extends Thread {
        @Override
        public void run() {
            try {
                URL url = new URL("http://www.baidu.com");
                URLConnection connection = url.openConnection();

                InputStream is = connection.getInputStream();
                InputStreamReader isr = new InputStreamReader(is);
                BufferedReader br = new BufferedReader(isr);
                String line;
                StringBuilder sb = new StringBuilder();
                while((line = br.readLine()) != null) {
                    sb.append(line);
                }
                br.close();
                isr.close();
                is.close();
                System.out.println(sb);
            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    static class ReadPost extends Thread {

        @Override
        public void run() {
            try {
                URL url = new URL("http://www.baidu.com");
                URLConnection conn = url.openConnection();
                HttpURLConnection connection = (HttpURLConnection) conn;
                connection.addRequestProperty("encoding", "UTF-8");
                connection.setDoInput(true);
                connection.setDoOutput(true);
                connection.setRequestMethod("POST");

                OutputStream os = connection.getOutputStream();
                OutputStreamWriter osw = new OutputStreamWriter(os);
                BufferedWriter bw = new BufferedWriter(osw);

                bw.write("kw=haha");
                bw.flush();

                InputStream is = connection.getInputStream();
                InputStreamReader isr = new InputStreamReader(is);
                BufferedReader br = new BufferedReader(isr);

                FileOutputStream fileOutputStream = new FileOutputStream("baidu.html");
                OutputStreamWriter fows = new OutputStreamWriter(fileOutputStream);
                BufferedWriter fbw = new BufferedWriter(fows);

                String line;
                StringBuilder builder = new StringBuilder();
                while((line = br.readLine()) != null) {
                    fbw.write(line);
                    builder.append((line));
                }
                bw.close();
                osw.close();
                br.close();
                isr.close();
                is.close();
                fbw.close();
                fows.close();
                fileOutputStream.close();
                System.out.println(builder.toString());
            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
