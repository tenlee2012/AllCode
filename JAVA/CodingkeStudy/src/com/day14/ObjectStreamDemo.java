package com.day14;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;

public class ObjectStreamDemo {

	public static void objectIn() {
		try {
			InputStream in = new FileInputStream("/home/tenlee/Desktop/1.txt");
			ObjectInputStream ois = new ObjectInputStream(in);
			Cat cat = (Cat)ois.readObject();
			System.out.println("name: " + cat.getName());
			System.out.println("age: " + cat.getAge());
			ois.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		Cat cat = new Cat("mimi", 3);
		OutputStream out;
		try {
			out = new FileOutputStream("/home/tenlee/Desktop/1.txt");
			ObjectOutputStream oos = new ObjectOutputStream(out);
			oos.writeObject(cat);
			oos.close();
			out.close();
			objectIn();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
