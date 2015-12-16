package com.day20;

import java.io.Serializable;

public class Info implements Serializable{
	private String to;
	private String from;
	private String info;
	private int type; // 0表示登陆，1表示发送消息
	private String name;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getType() {
		return type;
	}
	public void setType(int type) {
		this.type = type;
	}
	public Info() {
		super();
	}
	public Info(String to, String from, String info) {
		super();
		this.to = to;
		this.from = from;
		this.info = info;
	}
	public String getTo() {
		return to;
	}
	public void setTo(String to) {
		this.to = to;
	}
	public String getFrom() {
		return from;
	}
	public void setFrom(String from) {
		this.from = from;
	}
	public String getInfo() {
		return info;
	}
	public void setInfo(String info) {
		this.info = info;
	}
	@Override
	public String toString() {
		return "Info [to=" + to + ", from=" + from + ", info=" + info
				+ ", type=" + type + ", name=" + name + "]";
	}
	
}
