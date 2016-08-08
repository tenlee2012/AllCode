package com.hand.servlet;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by ljh on 2016/8/3.
 */
public class HelloServlet extends HttpServlet{
    @Override
    public void init() throws ServletException {
        System.out.println("=============init()=========");
        super.init();
    }
    @Override
    public void init(ServletConfig config) throws ServletException {
        System.out.println("=============init(config)=========");
        super.init(config);
    }
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException,IOException {
        System.out.println("=============service=========");
        super.service(request, response);
    }
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException{
        System.out.println("=============doPost=========");
    }
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        System.out.println("=============doGet=========");
        PrintWriter pw = response.getWriter();
        pw.println("hello world");
        pw.close();
    }
    @Override
    public void destroy(){

    }
}
