package com.hand.xml;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.DocumentHelper;

/**
 * Created by ljh on 2016/7/30.
 */
public class Dom4jDemo {
    public static void main(String args[]) {
        try {
            String xmlString = "<root><people>AELY</people></root>";
            Document document = DocumentHelper.parseText(xmlString);

            System.out.println(document.asXML());
        } catch (DocumentException e) {
            e.printStackTrace();
        }
    }
}
