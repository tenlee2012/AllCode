<%--
  Created by IntelliJ IDEA.
  User: ljh
  Date: 2016/8/6
  Time: 17:19
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" %>
<%@ page import="com.hand.dao.FilmDao" %>
<%@ page import="com.hand.bean.Film" %>
<%@ page import="java.util.List" %>
<%@ page import="com.hand.utils.PageUtil" %>
<%
    int totalPage = FilmDao.getTotalPage();
    String s_p = request.getParameter("p");
    if(s_p == null || "".equals(s_p)) s_p = "1";
    int nowPage = Integer.parseInt(s_p);
    if(nowPage <= 0 || nowPage > totalPage) nowPage = 1;
    List<Film> list = FilmDao.queryAll(nowPage);
    List<Integer> pager = PageUtil.pageAlgorithm(nowPage, totalPage);
%>
<html>
<head>
    <title>电影</title>
    <meta charset="utf-8">
    <link href="https://cdn.bootcss.com/materialize/0.97.7/css/materialize.min.css" rel="stylesheet">
    <link href="https://cdn.bootcss.com/material-design-icons/2.2.3/iconfont/material-icons.css" rel="stylesheet">
</head>
<body>
<div class="navbar-fixed">
    <ul id="dropdown1" class="dropdown-content">
        <li><a href="<%=request.getContextPath()%>/film.jsp">所有电影</a></li>
        <li><a href="<%=request.getContextPath()%>/addfilm.jsp">添加电影</a></li>
    </ul>
    <nav class="teal lighten-2">
        <div class="nav-wrapper container">
            <a href="<%=request.getContextPath()%>/" class="brand-logo">Logo</a>
            <ul class="right hide-on-med-and-down">
                <li><a href="<%=request.getContextPath()%>/" class="active">首页</a></li>
                <li><a class="dropdown-button" href="<%=request.getContextPath()%>/film.jsp" data-activates="dropdown1"
                    data-beloworigin="true" data-hover="true">电影<i class="mdi-navigation-arrow-drop-down right"></i></a></li>
                <li><a href="#">关于</a></li>
                <% if(request.getSession().getAttribute("name") == null) { %>
                <li><a href="<%=request.getContextPath()%>/login">登录</a></li>
                <% } else {%>
                <li><%=request.getSession().getAttribute("name")%></li>
                <li><a href="<%=request.getContextPath()%>/logout">退出</a></li>
                <% }%>
            </ul>
        </div>
    </nav>
</div>
<div class="container">
    <div class="row">&nbsp;</div>
    <div class="row">
        <div class="col s0 m0">&nbsp;</div>
        <div class="col s12 m12">
            <ul class="pagination center-align">
            <% for(int p : pager) { %>
                <% if(nowPage == p) { %>
                    <li class="active"><a href="/film.jsp?p=<%=p%>"><%=p%></a></li>
                <% } else { %>
                    <li class="waves-effect"><a href="/film.jsp?p=<%=p%>"><%=p%></a></li>
                <% } %>
            <% } %>
            </ul>
            <table class="bordered striped centered responsive-table" style="font-size: smaller;">
                <thead>
                <tr>
                    <th data-field="film_id">Film_id</th>
                    <th data-field="title">Title</th>
                    <th data-field="description">Description</th>
                    <th data-field="language">Language</th>
                    <th></th>
                    <th></th>
                </tr>
                </thead>
                <tbody>
                    <% for(Film f : list) { %>
                    <tr>
                        <td><%=f.getFilm_id()%></td>
                        <td><%=f.getTitle()%></td>
                        <td><%=f.getDesc()%></td>
                        <td><%=f.getLanguage()%></td>
                        <td><a class="waves-effect waves-light btn"href="/editfilm?id=<%=f.getFilm_id()%>">编辑</a></td>
                        <td><a class="waves-effect red darken-1 btn fuck" film_id="<%=f.getFilm_id()%>">删除</a></td>
                    </tr>
                    <% } %>
                </tbody>
            </table>
            <ul class="pagination center-align">
            <% for(int p : pager) { %>
                <% if(nowPage == p) { %>
                    <li class="active"><a href="/film.jsp?p=<%=p%>"><%=p%></a></li>
                <% } else { %>
                    <li class="waves-effect"><a href="/film.jsp?p=<%=p%>"><%=p%></a></li>
                <% } %>
            <% } %>
            </ul>
        </div>
    </div>

</div>
</body>
<script src="https://cdn.bootcss.com/jquery/3.1.0/jquery.min.js"></script>
<script src="https://cdn.bootcss.com/materialize/0.97.7/js/materialize.min.js"></script>
<script type="text/javascript">
    $(document).ready(function() {
        $(".fuck").click(function () {
            var r=confirm("你确定要删除吗??");
            if(r == true) {
                var film_id = $(this).attr("film_id");
                $.ajax({
                    url: "/api/film/"+film_id,
                    method: "delete",
                    data: {"film_id": film_id},
                    success: function (data) {
                        Materialize.toast('<i class="material-icons red-text text-accent-4">done</i>' + data, 1000, "rounded");
                        setTimeout(function(){window.location="/film.jsp";}, 1500);
                    },
                    error: function (data) {
                        Materialize.toast('<i class="material-icons red-text text-accent-4">error</i>'+data.responseText, 4000, "rounded");
                    },
                });
            }
            return false;
        });
    });
</script>
</html>
