package com.hand.servlet;

import com.hand.bean.Film;
import com.hand.dao.FilmDao;
import com.hand.dao.LanguageDao;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by ljh on 2016/8/7.
 */
public class FilmEditServlet extends BaseServlet {

    public void init() {
        super.init();
        this.setTemplate_name("editfilm.ftl");
    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        try {
            int film_id = Integer.parseInt(id);
            Map<String, Object> map = new HashMap<>();
            Film f = FilmDao.queryById(film_id);
            map.put("name", request.getSession().getAttribute("name"));
            map.put("context_path", request.getContextPath());
            map.put("film_id", f.getFilm_id());
            map.put("title", f.getTitle());
            map.put("desc", f.getDesc());
            map.put("language_id", f.getLanguage_id());
            map.put("all_language", LanguageDao.getAllLanguageId());
            templateProcess(request, response, map);
            return;
        } catch (Exception e) {

        }

        response.sendRedirect("/index.jsp");
    }
}
