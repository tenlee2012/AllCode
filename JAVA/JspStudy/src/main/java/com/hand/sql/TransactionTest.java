package com.hand.sql;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Created by ljh on 2016/8/2.
 */
public class TransactionTest {

    public static void main(String args[]) {
        insertUserData();
        JdbcTest.query();
    }

    public static void insertUserData() {
        Connection conn = null;
        Statement st = null;
        try {
            conn = JdbcTest.buildConn();
            conn.setAutoCommit(false);
            String sql = "insert into tbl_user(id, name, password, email) values(4, '小张', '123', 'xiaozhang@qq.com');";
            st = conn.createStatement();
            st.executeUpdate(sql);
            sql = "insert into tbl_user(id, name, password, email) values(4, '小张', '123', 'xiaozhang@qq.com');";
            st.executeUpdate(sql);
            conn.commit();
        } catch (SQLException e) {
            System.out.println("==========捕获到异常=======");
            e.printStackTrace();
            try {
                conn.rollback();
            } catch (SQLException e1) {
                e1.printStackTrace();
                System.out.println("==========回滚到异常=======");
            }
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
