package com.hand.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by ljh on 2016/8/6.
 */
public class UserDao {
    public static boolean login(String name) {
        Connection conn = ConnectionFactory.getInstance().makeConnection();
        PreparedStatement ps = null;
        ResultSet rs = null;
        String sql = "select customer_id from customer where first_name=?;";
        try {
            ps = conn.prepareStatement(sql);
            ps.setString(1, name);
            rs = ps.executeQuery();
            if(rs.next()) {
                return true;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return false;
    }
}
