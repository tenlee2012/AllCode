package com.hand.mybatis;

import com.hand.entity.Article;
import com.hand.entity.User;
import com.hand.mybatis.inter.IUserOperation;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by ljh on 2016/8/9.
 */
public class testMybatis {
    private static SqlSessionFactory sqlSessionFactory;
    private static Reader reader;
    static {
        try {
            reader = Resources.getResourceAsReader("Configuration.xml");
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static SqlSessionFactory getSqlSessionFactory() {
        return sqlSessionFactory;
    }

    public static void main(String args[]) {
//        useInterface();
//        useConfigFile();
        getUserArticles();
    }
    public static void useConfigFile() {
        SqlSession sqlSession = getSqlSessionFactory().openSession();
        try {
            User user = (User) sqlSession.selectOne("com.hand.entity.UserMapper.selectUserByID", 2);
            System.out.println(user.getName());
        } finally {
            sqlSession.close();
        }
    }

    public static void useInterface() {
        SqlSession sqlSession = getSqlSessionFactory().openSession();
        try {
            IUserOperation userOperation = sqlSession.getMapper(IUserOperation.class);
            User user = userOperation.selectUserByID(1);
            System.out.println(user.getName());

            List<User> list = userOperation.selectUsers("%");
            System.out.println(list);

            user = new User();
            user.setName("root");
            user.setPassword("root");
            user.setEmail("root@qq.com");
            userOperation.addUser(user);
            System.out.println("添加用户id is " + user.getId());
            sqlSession.commit();

            user.setName("admin");
            int cols = userOperation.updateUser(user);
            System.out.printf("更新了%d条数据", cols);
            sqlSession.commit();
        } finally {
            sqlSession.close();
        }
    }
    public static void getUserArticles() {
        System.out.println("==========");
        SqlSession session = sqlSessionFactory.openSession();
        try {
            IUserOperation operation = session.getMapper(IUserOperation.class);
            List<Article> list = operation.getUserArticle(1);
            for (Article a : list) {
                System.out.println(a);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            session.close();
        }
    }
}
