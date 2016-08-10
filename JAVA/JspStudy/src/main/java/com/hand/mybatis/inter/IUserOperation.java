package com.hand.mybatis.inter;

import com.hand.entity.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * Created by ljh on 2016/8/9.
 */
public interface IUserOperation {
    User selectUserByID(int id);
    List selectUsers(String name);
    void addUser(User user);
    int updateUser(User user);
    List getUserArticle(int id);
}
