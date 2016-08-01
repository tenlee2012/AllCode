package com.hand.file;

import java.io.*;

/**
 * Created by ljh on 2016/7/28.
 */
public class FileDemo {
    public static void main(String[] args) {
        System.out.println(~(-1));
        File file = new File("hello.txt");
        writeFile(file);

        if(file.exists()) {
            System.out.println(file.isFile());
        } else {
            System.out.println("文件不存在");
        }
        fileTree(new File("./"), 1);
    }

    public static void fileTree(File dir, int tab) {
        if(dir.isDirectory()) {
            File next[] = dir.listFiles();
            for(int i = 0; i < next.length; i++) {
                for(int j = 0; j < tab; j++) {
                    System.out.print("|--");
                }
                System.out.println(next[i].getName());
                if(next[i].isDirectory()) {
                    fileTree(next[i], tab+1);
                }
            }
        }
    }

    public static void readFIle(File file) {
        FileInputStream fis = null;
        InputStreamReader isr = null;
        BufferedReader br = null;

        try {
            fis = new FileInputStream(file);
            isr = new InputStreamReader(fis);
            br = new BufferedReader(isr);

            String line;
            while((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                br.close();
                isr.close();
                fis.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public static void writeFile(File file) {
        FileOutputStream fos  = null;
        OutputStreamWriter osw = null;
        BufferedWriter bw  = null;
        try {
            fos = new FileOutputStream(file);
            osw = new OutputStreamWriter(fos, "UTF-8");
            bw = new BufferedWriter(osw);

            bw.write("JAVA真垃圾\r\n");
            bw.write("JAVA真麻烦,尤其是文件流\r\n");
            bw.write("JAVA真恶心\r\n");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                bw.close();
                osw.close();
                fos.close();
                System.out.println("文件创建成功");
            } catch (IOException e) {
                System.out.println("文件创建失败");
                e.printStackTrace();
            }
        }
    }
}
