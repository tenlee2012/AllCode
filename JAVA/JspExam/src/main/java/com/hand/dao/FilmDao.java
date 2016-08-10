package com.hand.dao;

import com.hand.bean.Film;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by ljh on 2016/8/6.
 */
public class FilmDao {
    public static final int PER_PAGE = 20;

    public static void main(String args[]) {
//        System.out.println(getTotalPage());
        System.out.println(queryAll(1));
//        Film f = new Film();
//        f.setLanguage_id(1);
//        f.setDesc("hahaha");
//        f.setTitle("hahahahah");
//        System.out.println(addFilm(f));
    }

    public static int getTotalPage() {
        String sql = "select count(0) from film;";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            if(rs.next()) {
                return rs.getInt(1) / PER_PAGE + 1;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return 0;
    }
    public static List<Film> queryAll(int pag) {
        String sql = "select film.film_id, film.title, film.description, lan.language_id, lan.name" +
                " from film, language as lan  where film.language_id=lan.language_id limit ?,?;";
        if (pag <= 0) pag = 1;
        int start = PER_PAGE * (pag - 1);
        int end = PER_PAGE * pag;
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        List films = new ArrayList<>();
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            ps = conn.prepareStatement(sql);
            ps.setInt(1, start);
            ps.setInt(2, end);
            rs = ps.executeQuery();
            while (rs.next()) {
                Film f = new Film();
                f.setFilm_id(rs.getInt(1));
                f.setTitle(rs.getString(2));
                f.setDesc(rs.getString(3));
                f.setLanguage_id(rs.getInt(4));
                f.setLanguage(rs.getString(5));
                films.add(f);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return films;
    }

    public static Film queryById(int id) {
        String sql = "select film_id, title, description, language_id from film where film_id=?";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        Film f = new Film();
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            ps = conn.prepareStatement(sql);
            ps.setInt(1, id);
            rs = ps.executeQuery();
            if (rs.next()) {
                f.setFilm_id(rs.getInt(1));
                f.setTitle(rs.getString(2));
                f.setDesc(rs.getString(3));
                f.setLanguage_id(rs.getInt(4));
            }
        } catch (SQLException e) {
//            e.printStackTrace();
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return f;
    }

    public static boolean updateById(Film f) {
        String sql = "update film set title=?, description=?, language_id=? where film_id=?";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            conn.setAutoCommit(false);
            ps = conn.prepareStatement(sql);
            ps.setInt(4, f.getFilm_id());
            ps.setString(1, f.getTitle());
            ps.setString(2, f.getDesc());
            ps.setInt(3, f.getLanguage_id());
            int res = ps.executeUpdate();
            conn.commit();

            if (res >= 0) return true;
        } catch (SQLException e) {
            System.out.println("update rollback");
            try {
                conn.rollback();
            } catch (SQLException e1) {

            }
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return false;
    }

    public static boolean addFilm(Film f) {
        String sql = "INSERT INTO film(title, description, language_id) values(?,?,?);";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            conn.setAutoCommit(false);
            ps = conn.prepareStatement(sql);

            ps.setString(1, f.getTitle());
            ps.setString(2, f.getDesc());
            ps.setInt(3, f.getLanguage_id());

            int res = ps.executeUpdate();
            conn.commit();
            System.out.println("insert success");
            if (res >= 0) return true;
        } catch (SQLException e) {
            System.out.println("insert rollback");
//            e.printStackTrace();
            try {
                conn.rollback();
            } catch (SQLException e1) {

            }
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return false;
    }
    public static boolean deleteFilmById(int id) {
        String sql = "delete from film WHERE film_id=?;";
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = ConnectionFactory.getInstance().makeConnection();
            conn.setAutoCommit(false);
            ps = conn.prepareStatement(sql);

            ps.setInt(1, id);

            int res = ps.executeUpdate();
            conn.commit();

            if (res >= 0) return true;
            System.out.println("delete success");
        } catch (SQLException e) {
            System.out.println("delete rollback");
//            e.printStackTrace();
            try {
                conn.rollback();
            } catch (SQLException e1) {

            }
        } finally {
            ConnectionFactory.closeSql(conn, ps, rs);
        }
        return false;
    }
}
