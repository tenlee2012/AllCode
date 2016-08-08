package com.hand.sql;

import com.hand.sql.entity.ConnectionFactory;

import java.io.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by ljh on 2016/8/5.
 */
public class pictureDemo {
    public static void main(String args[]) {
        savePicture();
//        readPicture();
    }

    public static void readPicture() {
        String sql = "insert into tbl_user(name, password, email, picture)values(?,?,?,?);";
        Connection conn = null;
        PreparedStatement ps = null;
        InputStream in = null;
        try {
            in = new FileInputStream("C:/Users/ljh/Desktop/test.jpg");

            conn = ConnectionFactory.getInstance().makeConnection();
            conn.setAutoCommit(false);
            ps = conn.prepareStatement(sql);
            ps.setString(1, "fuck");
            ps.setString(2, "fuck");
            ps.setString(3, "fuck@qq.com");
            ps.setBinaryStream(4, in);

            ps.executeUpdate();
            conn.commit();

            System.out.println("OKOKOKOK");
        } catch (SQLException e) {
            try {
                conn.rollback();
            } catch (SQLException e1) {
                e1.printStackTrace();
            }
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                ps.close();
                conn.close();
                in.close();
            } catch (SQLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void savePicture() {
        String sql = "select picture from tbl_user where id=9;";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        InputStream in = null;
        BufferedInputStream bis = null;

        FileOutputStream fos = null;
        BufferedOutputStream bos = null;
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            rs.next();
            in = rs.getBinaryStream("picture");
            byte bs[] = new byte[100];
            bis = new BufferedInputStream(in);
            fos = new FileOutputStream("test.jpg");
            bos = new BufferedOutputStream(fos);
            int len = 0;
            while ((len = bis.read(bs)) > -1) {
                bos.write(bs, 0, len);
            }
            bos.flush();
            System.out.println("out put OKOKOKOK");
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                bis.close();
                bos.close();
                fos.close();
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                rs.close();
                ps.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
    }
}
