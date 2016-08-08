package com.hand.freemarker;

import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;

import java.io.File;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by ljh on 2016/8/4.
 */
public class Tets {
    public static void main(String args[]) {
        Configuration cfg = new Configuration();
        try {
            cfg.setDirectoryForTemplateLoading(new File("templates"));

            Map root = new HashMap();

            Map map = new HashMap();
            map.put("1", "haha");
            map.put("2", "heeh");

            root.put("user", "fuck");
            List<String> dizhi = new ArrayList<>();
            dizhi.add("北京");
            dizhi.add("上海");
            root.put("lst", dizhi);
            root.put("htm2", "1 > 2");
            root.put("sss", null);
            root.put("haha", "haha");
            root.put("mymap", map);

            Template t1 = cfg.getTemplate("b.ftl");
            Writer out = new OutputStreamWriter(System.out);
            t1.process(root, out);
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (TemplateException e) {
            e.printStackTrace();
        }
    }
}
