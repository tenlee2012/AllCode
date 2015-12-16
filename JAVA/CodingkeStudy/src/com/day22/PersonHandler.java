package com.day22;

import java.util.ArrayList;
import java.util.List;

import javax.xml.stream.events.StartElement;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class PersonHandler extends DefaultHandler{
	private List<Person> persons;
	private Person p;
	private String tag;
	
	public List<Person> getPersons() {
		return persons;
	}
	
	@Override
	public void startDocument() throws SAXException {
		super.startDocument();
		persons = new ArrayList<Person>();
		System.out.println("开始解析文档了");
	}
	@Override
	public void startElement(String uri, String localName, String qName,
			Attributes attributes) throws SAXException {
		super.startElement(uri, localName, qName, attributes);
		if("person".equals(qName)) {
			p = new Person();
			p.setPersonid(attributes.getValue("personid"));
		}
		tag = qName;
	}
	/**
	 * 处理文本内容，包括空格
	 */
	@Override
	public void characters(char[] ch, int start, int length)
			throws SAXException {
		super.characters(ch, start, length);
		if(tag != null) {
			if("name".equals(tag)) {
				p.setNamne(new String(ch, start, length));
			} else if ("age".equals(tag)) {
				p.setAge(new String(ch, start, length));
			} else if ("sex".equals(tag)) {
				p.setSex(new String(ch, start, length));
			} else if ("tel".equals(tag)) {
				p.setTel(new String(ch, start, length));
			}
		}
	}
	@Override
	public void endElement(String uri, String localName, String qName)
			throws SAXException {
		super.endElement(uri, localName, qName);
		if("person".equals(qName)) {
			persons.add(p);
		}
		tag = null;
	}


	@Override
	public void endDocument() throws SAXException {
		super.endDocument();
		System.out.println("解析结束");
	}
}
