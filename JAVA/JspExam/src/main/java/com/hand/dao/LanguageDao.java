package com.hand.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by ljh on 2016/8/6.
 */
public class LanguageDao {
    public static void main(String args[]) {
//        System.out.println(getAllLanguageId());
    }

    public static Map<String, String> getAllLanguageId() {
        String sql = "select language_id, name from language;";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        Map<String, String> map = new HashMap<>();
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            while(rs.next()) {
                map.put(rs.getInt(1)+"", rs.getString(2));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return map;
    }
}
