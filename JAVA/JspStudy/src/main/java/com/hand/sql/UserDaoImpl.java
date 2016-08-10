package com.hand.sql;

import com.hand.entity.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * Created by ljh on 2016/8/2.
 */
public class UserDaoImpl implements UserDao{
    @Override
    public void save(Connection conn, User user) throws SQLException {
        PreparedStatement ps = conn
                .prepareCall("insert into tbl_user(name, password, email)values(?, ?, ?);");
        ps.setString(1, user.getName());
        ps.setString(2, user.getPassword());
        ps.setString(3, user.getEmail());

        ps.execute();
    }

    @Override
    public void update(Connection conn, Long id, User user) throws SQLException {
        PreparedStatement ps = conn
                .prepareCall("update tbl_user set name=?, password=?, email=?" +
                        "where id=?");
        ps.setString(1, user.getName());
        ps.setString(2, user.getPassword());
        ps.setString(3, user.getEmail());
        ps.setLong(4, id);

        ps.execute();
    }

    @Override
    public void delete(Connection conn, User user) throws SQLException {
        PreparedStatement ps = conn
                .prepareCall("delete from tbl_user where id = ?;");
        ps.setLong(1, user.getId());

        ps.execute();
    }
}
