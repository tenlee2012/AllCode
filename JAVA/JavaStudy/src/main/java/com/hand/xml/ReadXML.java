package com.hand.xml;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;

/**
 * Created by ljh on 2016/7/30.
 */
public class ReadXML {
    public static void main(String[] args) {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = null;
        try {
            builder = factory.newDocumentBuilder();
            Document document = builder.parse(new File("languages.xml"));
            Element root = document.getDocumentElement();
            NodeList nlist = root.getElementsByTagName("lan");
            for(int i = 0; i < nlist.getLength(); i++) {
                Element lan = (Element) nlist.item(i);
                System.out.println("-----------------");
                System.out.println(lan.getAttribute("id"));

                NodeList clist = lan.getChildNodes();
                clist.getLength();
                for(int j = 0; j < clist.getLength(); j++)  {
                    Node c = clist.item(j);
                    if(c instanceof Element) {
                        System.out.println(c.getNodeName() + " = "
                            + c.getTextContent());
                    }
                }

//                Element name = (Element) lan.getElementsByTagName("name").item(0);
//                Element ide = (Element) lan.getElementsByTagName("ide").item(0);
//                System.out.println("name = " + name.getTextContent());
//                System.out.println("ide = " + ide.getTextContent());

            }

        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        } catch (SAXException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
