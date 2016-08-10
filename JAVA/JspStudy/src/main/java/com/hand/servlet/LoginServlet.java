package com.hand.servlet;

import com.hand.entity.User;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * Created by ljh on 2016/8/3.
 */
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String forward = "success.jsp";
        UserDao.servletContext = this.getServletContext();
        User u = null;
        if ((u = UserDao.login(username, password)) != null) {
            request.setAttribute("user", u);
            RequestDispatcher rd = request.getRequestDispatcher(forward);
            request.getSession().setAttribute("login", "1");
            rd.forward(request, response);
        }

//        Cookie cookie = new Cookie("username", username);
//        response.addCookie(cookie);
//        cookie = new Cookie("password", "*******");
//        response.addCookie(cookie);

        response.sendRedirect(request.getContextPath() + "/login.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        RequestDispatcher rd = request.getRequestDispatcher(request.getContextPath() + "/login.jsp");
        rd.forward(request, response);
    }
}
