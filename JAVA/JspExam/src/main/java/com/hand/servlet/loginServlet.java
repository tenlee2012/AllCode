package com.hand.servlet;

import com.hand.dao.UserDao;
import freemarker.template.Template;
import freemarker.template.TemplateException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.Writer;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by ljh on 2016/8/6.
 */
public class loginServlet extends BaseServlet {

    protected String template_name = "login.ftl";

    public void init() {
        super.init();
        setTemplate_name(template_name);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String name = request.getParameter("name");
        String next = request.getParameter("next");
        //登录成功后要跳转的页面
        if(next == null || next == "") next = "index.jsp";

        if (name != null && UserDao.login(name)) {
            HttpSession session = request.getSession();
            session.setAttribute("login", "1");  // 如登陆成功就在session写入login = 1
            session.setAttribute("name", name);  // 如登陆成功就在session写入login = 1
            response.sendRedirect(next);
            return;
        }
        Map<String, String> root = new HashMap<>();
        root.clear();
        root.put("error_message", "用户名不正确");
        templateProcess(request, response, root);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        templateProcess(request, response, null);
    }


}
