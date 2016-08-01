package com.hand.json;

import java.util.Date;

/**
 * Created by ljh on 2016/7/30.
 */
public class Student {
    private int id;
    private String name;
    private Date birthday;
    private boolean sex;

    public Student() {

    }

    public Student(int id, String name, Date birthday, boolean sex) {
        this.id = id;
        this.name = name;
        this.birthday = birthday;
        this.sex = sex;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Date getBirthday() {
        return birthday;
    }

    public boolean isSex() {
        return sex;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setBirthday(Date birthday) {
        this.birthday = birthday;
    }

    public void setSex(boolean sex) {
        this.sex = sex;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", birthday=" + birthday +
                ", sex=" + sex +
                '}';
    }
}
