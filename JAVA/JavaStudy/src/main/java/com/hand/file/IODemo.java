package com.hand.file;

import java.io.*;

/**
 * Created by ljh on 2016/7/28.
 */
public class IODemo {
    public static void main(String[] args) {
//        copyByteStream();
//        readByteStream();
//        writeByteStream();
//        readByBufferedByteStream();
        rwByBufferedCHarStream();
    }

    /**
     * 按字节流读取
     */
    public static String readByteStream() {
        String inputString = null;
        try {
            FileInputStream fis = new FileInputStream("hello.txt");
            byte[] input = new byte[1024];
            fis.read(input);

            inputString = new String(input, "UTF-8");
            System.out.println(inputString);
            fis.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return inputString;
    }

    /**
     * 按字节流读取
     */
    public static void writeByteStream() {
        try {
            FileOutputStream fos = new FileOutputStream("hello.txt");
            String outputString = readByteStream();
            byte output[] = outputString.getBytes("UTF-8");
            fos.write(output);
            fos.close();
            System.out.println("写入成功");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 按字节流读取
     */
    public static void copyByteStream() {
        try {
            FileInputStream fis = new FileInputStream("movie.mp4");
            FileOutputStream fos = new FileOutputStream("movie1.mp4");

            byte input[] = new byte[50];
            long before = System.currentTimeMillis();
            int len = 0;
            while ((len = fis.read(input)) != -1) {
                fos.write(input, 0, len);
            }
            fis.close();
            fos.close();
            System.out.println("DONE");
            System.out.println("Cost: " + (System.currentTimeMillis() - before));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    /**
     * 使用 带缓冲的 字节流 BufferedInputStream 读取速度是不使用的近 30 倍
     */
    public static void readByBufferedByteStream() {
        try {
            FileInputStream fis = new FileInputStream("movie.mp4");
            BufferedInputStream bis = new BufferedInputStream(fis);
//            FileOutputStream fos = new FileOutputStream("movie2.mp4", true);
            FileOutputStream fos = new FileOutputStream("movie2.mp4");
            BufferedOutputStream bos = new BufferedOutputStream(fos);

            long before = System.currentTimeMillis();
            int len = 0;
            byte input[] = new byte[100];
            while ((len = bis.read(input)) != -1) {
                bos.write(input, 0, len); //不然会出现,iput数组没有被填满,会使用上次的数据
            }
            bis.close();
            bos.close();
            fis.close();
            fos.close();
            System.out.println("Buffer Cost: " + (System.currentTimeMillis() - before));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 按字符流读取和写入
     */
    public static void rwByCharStream() {
        try {
            FileInputStream fis = new FileInputStream("hello.txt");
            InputStreamReader isr = new InputStreamReader(fis, "UTF-8");

            FileOutputStream fos = new FileOutputStream("hello_tmp.txt");
            OutputStreamWriter osw = new OutputStreamWriter(fos);

            char input[] = new char[100];
            int len = 0;
            while ((len = isr.read(input)) != -1) {
                osw.write(input, 0, len);
//                System.out.println(new String(input, 0, len));
            }

            isr.close();
            osw.close();
            fis.close();
            fis.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 带缓冲的, 按字符流读取和写入
     */
    public static void rwByBufferedCHarStream() {
        try {
            FileInputStream fis = new FileInputStream("hello.txt");
            FileOutputStream fos = new FileOutputStream("hello_tmp.txt");
            InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
            OutputStreamWriter osw = new OutputStreamWriter(fos);

            BufferedReader br = new BufferedReader(isr);
            BufferedWriter bw = new BufferedWriter(osw);
//            PrintWriter pw = new PrintWriter(osw);
//            pw.println();
//            pw.close();

            String input;
            while((input = br.readLine()) != null) {
                osw.write(input);
            }
            osw.flush(); //  将剩余缓冲区内容强制输出
            isr.close();
            osw.close();
            fis.close();
            osw.close();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void FileReaderWriter() {
        try {
            FileReader fr = new FileReader("hello.txt");
            BufferedReader br = new BufferedReader(fr);

            FileWriter fw = new FileWriter("hello.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            String line;
            while((line = br.readLine()) != null) {
                bw.write(line + "\n");
            }
            bw.flush();

            bw.close();
            br.close();
            fw.close();
            fr.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void randomAccessFile() {
        File file = new File("hello.txt");


    }
}
