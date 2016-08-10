package com.hand.servlet;

import freemarker.template.Configuration;
import freemarker.template.Template;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.Writer;
import java.util.Locale;
import java.util.Map;

/**
 * Created by ljh on 2016/8/6.
 */
public class BaseServlet extends HttpServlet{
    protected Configuration cfg;
    protected String template_name = "index.ftl";

    public void init() {
        cfg = new Configuration();
        cfg.setServletContextForTemplateLoading(
                getServletContext(), "WEB-INF/templates");
        cfg.setDefaultEncoding("UTF-8");
        cfg.setOutputEncoding("UTF-8");
        cfg.setLocale(Locale.CHINA);
    }
    protected void templateProcess(HttpServletRequest request, HttpServletResponse response,
                                   Map map) {
        Template t = null;
        try {
            t = cfg.getTemplate(getTemplate_name());
            response.setContentType("text/html; charset=" + t.getEncoding());
            Writer out = response.getWriter();
            t.process(map, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String getTemplate_name() {
        return template_name;
    }

    public void setTemplate_name(String template_name) {
        this.template_name = template_name;
    }
}
