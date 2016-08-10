package com.hand;

import com.google.gson.JsonObject;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
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
import java.io.*;

/**
 * Created by ljh on 2016/8/1.
 */
public class App{
    public static void main(String args[]) {
        String source = getData();
        String result[] = DatatoArry(source);
        toXML(result);
        toJson(result);
    }

    public static String getData() {
        HttpClient client = HttpClients.createDefault();
        HttpGet get = new HttpGet("http://hq.sinajs.cn/list=sz300170");
//        HttpGet get = new HttpGet("http://hq.sinajs.cn/list=sh601006");
        String  result = null;
        try {
            HttpResponse response = client.execute(get);
            HttpEntity entity = response.getEntity();
            result = EntityUtils.toString(entity, "UTF-8");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result;
    }

    public static String[] DatatoArry(String str) {
        String data[] = str.split(",");
        String result[] = new String[6];
        for(int i = 0; i < 6; i++) {
            result[i] = data[i];
        }
        result[0] = data[0].substring(21);
        return result;
    }

    public static void toJson(String[] datas) {
        JsonObject jsonObject = new JsonObject();
        jsonObject.addProperty("name", datas[0]);
        jsonObject.addProperty("open", datas[1]);
        jsonObject.addProperty("close", datas[2]);
        jsonObject.addProperty("current", datas[3]);
        jsonObject.addProperty("high", datas[4]);
        jsonObject.addProperty("low", datas[5]);

        saveFile("hand.json", jsonObject.toString());
    }
    public static void toXML(String[] datas) {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        try {
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document document = builder.newDocument();

            Element root = document.createElement("stock");

            Element name = document.createElement("name");
            name.setTextContent(datas[0]);
            Element open = document.createElement("open");
            open.setTextContent(datas[1]);
            Element close = document.createElement("close");
            close.setTextContent(datas[2]);
            Element current = document.createElement("current");
            current.setTextContent(datas[3]);
            Element high = document.createElement("high");
            high.setTextContent(datas[4]);
            Element low = document.createElement("low");
            low.setTextContent(datas[5]);

            root.appendChild(name);
            root.appendChild(open);
            root.appendChild(close);
            root.appendChild(current);
            root.appendChild(low);
            root.appendChild(high);

            document.appendChild(root);
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            transformer.setOutputProperty("encoding", "UTF-8");

            StringWriter writer = new StringWriter();
            transformer.transform(new DOMSource(document), new StreamResult(writer));
            saveFile("hand.xml", writer.toString());
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        } catch (TransformerConfigurationException e) {
            e.printStackTrace();
        } catch (TransformerException e) {
            e.printStackTrace();
        }
    }
    public static void saveFile(String file_name, String content) {
        try {
            FileOutputStream fos = new FileOutputStream(file_name);
            BufferedOutputStream bos = new BufferedOutputStream(fos);
            bos.write(content.getBytes());
            bos.close();
            fos.close();
            System.out.println(file_name + " save successful!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


