package com.day22;

public class Person {
	private String namne;
	private String age;
	private String sex;
	private String tel;
	private String id;
	
	public Person() {
		super();
	}
	public Person(String namne, String age, String sex, String tel) {
		super();
		this.namne = namne;
		this.age = age;
		this.sex = sex;
		this.tel = tel;
	}
	public String getNamne() {
		return namne;
	}
	public void setNamne(String namne) {
		this.namne = namne;
	}
	public String getAge() {
		return age;
	}
	public void setAge(String age) {
		this.age = age;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getTel() {
		return tel;
	}
	public void setTel(String tel) {
		this.tel = tel;
	}
	public void setPersonid(String value) {
		id = value;
	}
	@Override
	public String toString() {
		return "Person [namne=" + namne + ", age=" + age + ", sex=" + sex
				+ ", tel=" + tel + ", id=" + id + "]";
	}
	
}
