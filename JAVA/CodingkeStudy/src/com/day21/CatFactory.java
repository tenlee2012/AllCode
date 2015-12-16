package com.day21;

import java.beans.BeanInfo;
import java.beans.IntrospectionException;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Properties;

public class CatFactory {
	
	private static Properties prop = new Properties();
	static {
		//当前线程的类加载器,加载配置文件
		InputStream inStream = 
				Thread.currentThread().getContextClassLoader().getResourceAsStream("com/day21/cat.properties");
		try {
			prop.load(inStream);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static Cat newUser() {
		String cat = prop.getProperty("cat");
		Cat c = null;
		try {
			Class beanClass = Class.forName(cat);
			c = (Cat)beanClass.newInstance();
			BeanInfo beaninfo = Introspector.getBeanInfo(beanClass);
			//获取所有属性描述器
			PropertyDescriptor[] pds = beaninfo.getPropertyDescriptors();
			for(PropertyDescriptor pd:pds){
				String name = pd.getName();
//				System.out.println("name: " + name + pds.length + prop.getProperty("age"));
				if("name".equals(name)){
					Method m = pd.getWriteMethod();
					m.invoke(c, prop.getProperty("name"));
				}else if ("age".equals(name)) {
					Method m = pd.getWriteMethod();
					m.invoke(c, Integer.parseInt(prop.getProperty("age")));
				}
			}
		} catch (ClassNotFoundException | IntrospectionException | InstantiationException | IllegalAccessException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
		return c;
	}
}
