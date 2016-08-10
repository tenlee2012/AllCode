package com.hand.mybatis;

import com.hand.entity.User;
import com.hand.mybatis.inter.IUserOperation;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by ljh on 2016/8/10.
 */
public class MybatisSprintTest {
    private static ApplicationContext ctx;
    static {
        ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
    }

    public static void main(String args[]) {
        IUserOperation opeartor = (IUserOperation) ctx.getBean("userMapper");
        User user =  opeartor.selectUserByID(1);
        System.out.println("user name is " + user.getName());
    }
}
