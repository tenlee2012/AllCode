package com.hand.servlet;


import com.hand.sql.entity.ConnectionFactory;
import com.hand.sql.entity.User;
import com.sun.corba.se.spi.orbutil.fsm.Input;

import javax.servlet.ServletContext;
import java.io.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by ljh on 2016/8/5.
 */
public class UserDao {
    public static ServletContext servletContext;
    public static void main(String args[]) {
        System.out.println(login("fuck", "fuck"));
    }
    public static User login(String name, String password) {
        Connection conn = ConnectionFactory.getInstance().makeConnection();
        String sql = "select id from tbl_user where name=? and password=?;";
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            ps = conn.prepareStatement(sql);
            ps.setString(1, name);
            ps.setString(2, password);
            rs = ps.executeQuery();
            rs.last();
            int result = rs.getRow();

            if(result == 1)
                return getUser(rs.getInt(1));
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                if(ps != null)
                    ps.close();
                if(conn != null)
                    conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return null;
    }
    public static User getUser(int id) {
        String sql = "select id, name, email, picture from tbl_user where id=?";
        Connection conn = ConnectionFactory.getInstance().makeConnection();
        PreparedStatement ps = null;
        ResultSet rs = null;
        User u = null;
        InputStream in = null;
        try {
            ps = conn.prepareStatement(sql);
            ps.setInt(1, id);
            rs = ps.executeQuery();
            u = new User();
            if(rs.next()) {
                u.setName(rs.getString("name"));
                u.setEmail(rs.getString("email"));
                in = rs.getBinaryStream("picture");
            }
            if(in != null) {
                u.setPicture(servletContext.getRealPath("WEB-INF/" + id + u.getName() + ".jpg"));
                saveFile(in, u.getPicture());
            } else {
                u.setPicture("");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                rs.close();
                ps.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return u;
    }
    public static void saveFile(InputStream in, String fileName) {
        BufferedInputStream bis = null;
        FileOutputStream fos = null;
        BufferedOutputStream bos = null;
        try {
            bis = new BufferedInputStream(in);
            fos = new FileOutputStream(fileName);
            bos = new BufferedOutputStream(fos);
            byte bs[] = new byte[1000];
            int len = 0;
            while ((len = bis.read(bs)) > -1) {
                bos.write(bs, 0, len);
            }
            bos.flush();
            System.out.println("SAVE OK OK OK OK" + fileName);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if(bos != null) bos.close();
                if(bis != null) bis.close();
                if(fos != null) fos.close();
                if(in != null) in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }


    }

}
