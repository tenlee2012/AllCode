package com.hand.sql;

import com.hand.entity.User;

import java.sql.Connection;
import java.sql.SQLException;

/**
 * Created by ljh on 2016/8/2.
 */
public class UserDaoTest {
    public static void main(String args[]) {
        try {
            Connection conn = ConnectionFactory.getInstance().makeConnection();
            conn.setAutoCommit(false);

            UserDao userDao = new UserDaoImpl();
            User tom = new User();
            tom.setEmail("tom@qq.com");
            tom.setName("tom");
            tom.setPassword("tom");
            userDao.save(conn, tom);
            conn.commit();
            JdbcTest.query();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
