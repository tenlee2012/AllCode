package com.hand.freemarker;

import java.io.*;
import java.util.*;
import java.lang.reflect.*;
import javax.servlet.*;
import javax.servlet.http.*;
import freemarker.template.*;

/**
 * <p>This is very very primitive MVC Controller servlet base class, based
 * on example 1. The application specific controller servlet should extend
 * this class.
 */
public class ControllerServlet extends HttpServlet {
    private Configuration cfg; 
    
    public void init() {
        cfg = new Configuration();
        cfg.setServletContextForTemplateLoading(
                getServletContext(), "WEB-INF/templates");
        cfg.setTemplateUpdateDelay(0);
        cfg.setTemplateExceptionHandler(
                TemplateExceptionHandler.HTML_DEBUG_HANDLER);
        cfg.setObjectWrapper(ObjectWrapper.BEANS_WRAPPER);
        cfg.setDefaultEncoding("UTF-8");
        cfg.setOutputEncoding("UTF-8");
        cfg.setLocale(Locale.CHINA);
    }
    
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        doGet(req, resp);
    }
    
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
        throws ServletException, IOException {
        
        // Choose action method
        String action = req.getServletPath();
        if (action == null) action = "index";
        if (action.startsWith("/")) action = action.substring(1);
        if (action.lastIndexOf(".") != -1) {
            action = action.substring(0, action.lastIndexOf("."));
        }
        Method actionMethod;
        try {
            actionMethod =
                    getClass().getMethod(action + "Action",
                    new Class[]{HttpServletRequest.class, Page.class});
        } catch (NoSuchMethodException e) {
            throw new ServletException("Unknown action: " + action);
        }
        
        // Set the request charset to the same as the output charset,
        // because HTML forms normally send parameters encoded with that.
        req.setCharacterEncoding(cfg.getOutputEncoding());
        
        // Call the action method
        Page page = new Page();
        try {
            actionMethod.invoke(this, new Object[]{req, page});
        } catch (IllegalAccessException e) {
            throw new ServletException(e);
        } catch (InvocationTargetException e) {
            throw new ServletException(e.getTargetException());
        }
        
        if (page.getTemplate() != null) { // show a page with a template
            // Get the template object
            Template t = cfg.getTemplate(page.getTemplate());
            
            // Prepare the HTTP response:
            // - Set the MIME-type and the charset of the output.
            //   Note that the charset should be in sync with the output_encoding setting.
            resp.setContentType("text/html; charset=" + cfg.getOutputEncoding());
            // - Prevent browser or proxy caching the page.
            //   Note that you should use it only for development and for interactive
            //   pages, as it significantly slows down the Web site.
            resp.setHeader("Cache-Control", "no-store, no-cache, must-revalidate, "
                    + "post-check=0, pre-check=0");
            resp.setHeader("Pragma", "no-cache");
            resp.setHeader("Expires", "Thu, 01 Dec 1994 00:00:00 GMT");
            Writer out = resp.getWriter();
            
            // Merge the data-model and the template
            try {
                t.process(page.getRoot(), out);
            } catch (TemplateException e) {
                throw new ServletException(
                        "Error while processing FreeMarker template", e);
            }
        } else if (page.getForward() != null) { // forward request
            RequestDispatcher rd = req.getRequestDispatcher(page.getForward());
            rd.forward(req, resp);            
        } else {
            throw new ServletException("The action didn't specified a command.");
        }
    }
}