package com.hand.sql;

import com.hand.entity.User;

import java.sql.Connection;
import java.sql.SQLException;

/**
 * Created by ljh on 2016/8/2.
 */
public interface UserDao {
    public void save(Connection conn, User user) throws SQLException;

    public void update(Connection conn, Long id, User user) throws SQLException;

    public void delete(Connection conn, User user) throws SQLException;
}
