package com.hand.freemarker;

import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.Writer;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * Created by ljh on 2016/8/4.
 */
public class HelloFreemarker extends HttpServlet {
    private Configuration cfg;

    public void init() {
        cfg = new Configuration();
        cfg.setServletContextForTemplateLoading(
                getServletContext(), "WEB-INF/templates");
        // - Set the default charset of the template files
        cfg.setDefaultEncoding("UTF-8");
        // - Set the charset of the output. This is actually just a hint, that
        //   templates may require for URL encoding and for generating META element
        //   that uses http-equiv="Content-type".
        cfg.setOutputEncoding("UTF-8");
        // - Set the default locale
        cfg.setLocale(Locale.CHINA);
    }

    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        Map root = new HashMap();
        root.put("message", "Hello World!");

        Template t = cfg.getTemplate("test.ftl");

        resp.setContentType("text/html; charset=" + t.getEncoding());
        Writer out = resp.getWriter();

        try {
            t.process(root, out);
        } catch (TemplateException e) {
            throw new ServletException(
                    "Error while processing FreeMarker template", e);
        }
    }
}
