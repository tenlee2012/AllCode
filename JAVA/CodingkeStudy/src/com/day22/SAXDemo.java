package com.day22;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;

import com.day22.Person;

/**
 * Simple API for XML
 * 比DOM更快更轻
 * 基于事件驱动，灵活性差，顺序读取，不能来回跳读
 * @author tenlee
 *
 */
public class SAXDemo {

	public static void main(String[] args) {
		List<Person> list = parseSAXXml();
		for(Person p:list) {
			System.out.println(p);
		}
	}

	private static List<Person> parseSAXXml() {
		List<Person> list = new ArrayList<>();
		//
		SAXParserFactory factory = SAXParserFactory.newInstance();
		try {
			SAXParser sax = factory.newSAXParser();
			InputStream is = Thread.currentThread().getContextClassLoader()
					.getResourceAsStream("com/day22/person.xml");
			PersonHandler dh = new PersonHandler();
			sax.parse(is, dh);
			list = dh.getPersons();
		} catch (ParserConfigurationException | SAXException | IOException e) {
			e.printStackTrace();
		}
		return list;
	}

}
