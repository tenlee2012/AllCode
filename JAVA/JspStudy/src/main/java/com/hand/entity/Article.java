package com.hand.entity;

/**
 * Created by ljh on 2016/8/9.
 */
public class Article {
    private int id;
    private User user;
    private String title;
    private String content;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    @Override
    public String toString() {
        return "Article{" +
                "id=" + id +
                ", user=" + user.getId() +
                ", title='" + title + '\'' +
                ", content='" + content + '\'' +
                '}';
    }
}
