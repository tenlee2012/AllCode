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
 * Created by ljh on 2016/8/6.
 * 用来处理电影的增加,修改,删除的servlet
 */
public class FilmAPIServlet extends BaseServlet {

    // 检查参数是否合法
    protected Film checkParams(String title, String desc, String language_id) {
        if(title == null || "".equals(title)) return null;
        if(desc == null || "".equals(desc)) return null;
        if(language_id == null) return null;
        try {
            if(!LanguageDao.getAllLanguageId().containsKey(language_id)) {
                return null;
            }
        } catch (Exception e) {
            return null;
        }
        Film f = new Film();
        f.setTitle(title);
        f.setDesc(desc);
        f.setLanguage_id(Integer.parseInt(language_id));
        return f;
    }

    //新建一个film, 使用post方法
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
//        response.setContentType("application/json; charset=utf-8");
        String title = request.getParameter("title");
        String desc = request.getParameter("desc");
        String language_id = request.getParameter("language_id");
        Film f = checkParams(title, desc, language_id);
        if (f != null) {
            if(FilmDao.addFilm(f)) {
                response.getWriter().println("添加电影信息成功,不错哟!");
                return;
            }
        }
        response.setStatus(400);
        response.getWriter().println("抱歉,操作失败!");
    }

    //删除一个film, 使用delete方法
    @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
//        response.setContentType("application/json; charset=utf-8");
        try {
            String action = request.getRequestURI().toString();
            String film_id = action.substring(10);
            if(FilmDao.deleteFilmById(Integer.parseInt(film_id))) {
                response.getWriter().println("删除电影信息成功,不错哟!");
                return;
            }
        } catch (Exception e) {
        }
        response.setStatus(400);
        response.getWriter().println("抱歉,含有约束,操作失败!");
    }

    //更新一个film, 使用put方法
    @Override
    protected void doPut(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
//        response.setContentType("application/json; charset=utf-8");
        try {
            String action = request.getRequestURI().toString();
            String id = action.substring(10);
            String film_id = request.getParameter("film_id");
            String title = request.getParameter("title");
            String desc = request.getParameter("desc");
            String language_id = request.getParameter("language_id");

            System.out.println(id + film_id + title + desc + language_id);
            Film f = checkParams(title, desc, language_id);
            if (f != null) {
                // 并且 film_id不为空并和 id 参数一致
                if (film_id != null && film_id.equals(id)) {
                    f.setFilm_id(Integer.parseInt(film_id)); //更新需要id
                    if (FilmDao.updateById(f)) {
                        response.getWriter().println("电影信息更新成功,不错哟!");
                        return;
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        response.setStatus(400);
        response.getWriter().println("抱歉,操作失败!");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.sendRedirect("/index.jsp");
    }
}
