package com.hand.filter;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by ljh on 2016/8/6.
 */
public class RequestFilter implements Filter {
    private String charEncoding = null;

    public void init(FilterConfig config) throws ServletException {
        charEncoding = config.getInitParameter("encoding");
        charEncoding  = charEncoding == null ?  "utf-8" : charEncoding;
    }

    public void doFilter(ServletRequest req, ServletResponse resp,
                         FilterChain chain) throws ServletException, IOException {
        if(!charEncoding.equals(req.getCharacterEncoding())) {
            req.setCharacterEncoding(charEncoding);
        }
        resp.setCharacterEncoding(charEncoding);

        HttpServletRequest httpServletRequest = (HttpServletRequest) req;
        HttpServletResponse httpServletResponse = (HttpServletResponse) resp;
        String action = httpServletRequest.getServletPath();
        if(action.startsWith("/")) action = action.substring(1);
        HttpSession session = httpServletRequest.getSession();
        String loginFlag = (String)session.getAttribute("login");
//        System.out.println("action#" + action + "#" + loginFlag + "#");
        if(!"1".equals(loginFlag) &&
                !"".equals(action) &&
                !"login".equals(action) &&
                !action.startsWith("index") &&
                !action.startsWith("static")) {
            httpServletResponse.sendRedirect("/login?next=" + action);
            return;
        }

        chain.doFilter(req, resp);
    }

    @Override
    public void destroy() {

    }

}
