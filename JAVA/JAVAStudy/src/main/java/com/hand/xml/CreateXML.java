package com.hand.xml;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.io.StringWriter;

/**
 * Created by ljh on 2016/7/30.
 */
public class CreateXML {
    public static void main(String[] args) {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder  builder = factory.newDocumentBuilder();
            Document document = builder.newDocument();

            Element root = document.createElement("staff");
            root.setAttribute("cat", "it");

            Element lan1 = document.createElement("lan");
            lan1.setAttribute("id", "1");

            Element name1 = document.createElement("name");
            name1.setTextContent("JAVA");

            Element ide1 = document.createElement("ide");
            name1.setTextContent("Intellij IDEA");

            lan1.appendChild(name1);
            lan1.appendChild(ide1);
            root.appendChild(lan1);

            document.appendChild(root);


            //--------------
            try {
                TransformerFactory transformerFactory = TransformerFactory.newInstance();
                Transformer transformer = transformerFactory.newTransformer();
                StringWriter writer = new StringWriter();
                transformer.transform(new DOMSource(document), new StreamResult(writer));
                System.out.println(writer.toString());

                transformer.transform(new DOMSource(document), new StreamResult(new File("newxml.xml")));
            } catch (TransformerConfigurationException e) {
                e.printStackTrace();
            } catch (TransformerException e) {
                e.printStackTrace();
            }


        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        }

    }
}
