package com.hand.filter;

import javax.servlet.*;
import java.io.IOException;

/**
 * Created by ljh on 2016/8/3.
 */
//@WebFilter(filterName = "EncodingFilter", urlPatterns = "/*",
//    initParams = {@WebInitParam(name="encoding", value="utf-8")})
public class EncodingFilter implements javax.servlet.Filter {
    private String charEncoding = null;

    public EncodingFilter() {
        super();
        System.out.println("=========过滤器构造=====");
    }

    public void init(FilterConfig config) throws ServletException {
        charEncoding = config.getInitParameter("encoding");
        System.out.println("=========过滤器init=====" + charEncoding);
        charEncoding  = charEncoding == null ?  "utf-8" : charEncoding;
    }

    public void doFilter(ServletRequest req, ServletResponse resp,
                         FilterChain chain) throws ServletException, IOException {
        System.out.println("=========过滤器 doFilter=====");
        if(!charEncoding.equals(req.getCharacterEncoding())) {
            req.setCharacterEncoding(charEncoding);
        }
        resp.setCharacterEncoding(charEncoding);
        chain.doFilter(req, resp);
    }

    public void destroy() {
        System.out.println("=========过滤器init=====");
    }
}
