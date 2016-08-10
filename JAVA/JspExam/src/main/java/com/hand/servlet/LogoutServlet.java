package com.hand.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * Created by ljh on 2016/8/8.
 */
public class LogoutServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(request.getSession().getAttribute("name") != null) {
            request.getSession().removeAttribute("name");
        }
        if(request.getSession().getAttribute("login") != null) {
            request.getSession().removeAttribute("login");
        }
        response.sendRedirect("/");
    }
}
