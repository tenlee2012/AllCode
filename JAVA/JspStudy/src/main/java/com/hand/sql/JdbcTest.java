package com.hand.sql;

import java.sql.*;

/**
 * Created by ljh on 2016/8/2.
 */
public class JdbcTest {
    public static void main(String args[]) {
//        String sql = "insert into tbl_user(name, password, email) values('小张', '123', 'xiaozhang@qq.com');";
//        DMA(sql);
//        query();
//
//        sql = "update tbl_user set email='haha@qq.com' where name='小张';";
//        DMA(sql);
//        query();

//        String sql = "delete from tbl_user where id=4;";
//        DMA(sql);
//        query();
        query();
    }

    public static Connection buildConn() throws SQLException {
        Connection conn = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jsp_db?characterEncoding=utf-8",
                    "root", "12345");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return conn;
    }

    public static void query() {
        String sql = "select * from tbl_user";
        Connection conn = null;
        Statement st = null;
        ResultSet rs = null;
        try {
            conn = buildConn();
            st = conn.createStatement();
            rs = st.executeQuery(sql);

            while (rs.next()) {
                System.out.print(rs.getInt("id") + " ");
                System.out.print(rs.getString("name") + " ");
                System.out.print(rs.getString("password") + " ");
                System.out.print(rs.getString("email") + " ");
                System.out.print("\n");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                rs.close();
                st.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void DMA(String sql) {
        Connection conn = null;
        Statement st = null;
        try {
            conn = buildConn();
            st = conn.createStatement();
            int count = st.executeUpdate(sql);
            System.out.println("向数据库更新了" + count + "条数据");
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                st.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
