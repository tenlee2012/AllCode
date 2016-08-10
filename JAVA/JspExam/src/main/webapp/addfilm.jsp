<%@ page import="com.hand.dao.LanguageDao" %>
<%@ page import="java.util.Map" %><%--
  Created by IntelliJ IDEA.
  User: ljh
  Date: 2016/8/6
  Time: 21:37
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="utf-8" %>
<%
    Map all_language = LanguageDao.getAllLanguageId();
%>
<html>
<head>
    <title>添加电影信息</title>
    <meta charset="utf-8">
    <link href="https://cdn.bootcss.com/materialize/0.97.7/css/materialize.min.css" rel="stylesheet">
    <link href="https://cdn.bootcss.com/material-design-icons/2.2.3/iconfont/material-icons.css" rel="stylesheet">
    <script src="https://cdn.bootcss.com/jquery/3.1.0/jquery.min.js"></script>
    <script src="https://cdn.bootcss.com/materialize/0.97.7/js/materialize.min.js"></script></head>
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
        <div class="col s0 m3">&nbsp;</div>
        <div class="col s12 m6">
            <form method="post" id="editform">
                <div class="row">
                    <div class="input-field col s12">
                        <input name="title" id="title" type="text" class="validate" required="true">
                        <label for="Title">Title</label>
                    </div>
                </div>
                <div class="row">
                    <div class="input-field col s12">
                        <textarea id="desc" name="desc" class="materialize-textarea" required="true"></textarea>
                        <label for="Description">Description</label>
                    </div>
                </div>
                <div class="row">
                    <div class="col s12">
                        <select name="language_id" id="language_id">
                            <% for(Object lan : all_language.keySet()) {%>
                                <option value="<%=lan%>"><%=all_language.get(lan)%></option>
                            <% } %>
                        </select>
                    </div>
                </div>
                <div class="row">
                    <div class="col s12">
                        <div class="input-field col s6 m5 center-align">&nbsp;</div>
                        <div class="input-field col s6 m3 center-align">&nbsp;</div>
                        <div class="input-field col s12 m4 right-align">
                            <button type="submit" id="submit_btn" class="waves-effect teal lighten-2 btn accent-4">添加</button>
                        </div>
                    </div>
                </div>
            </form>
        </div>
    </div>
</div>
<script type="text/javascript">
    $(document).ready(function() {
        $('select').material_select();
        $("#editform").submit(function() {
            event.preventDefault();
            var title = $("#title").val();
            var desc = $("#desc").val();
            var lan_id = $("#language_id").val();
            $.ajax ({
                url: "/api/film/",
                method: "post",
                data: {"title": title, "desc": desc, "language_id": lan_id},
                success: function(data) {
                    Materialize.toast('<i class="material-icons red-text text-accent-4">done</i>'+data, 1000, "rounded");
                    setTimeout(function(){window.location="/film.jsp";}, 1500);
                },
                error: function(data) {
                    Materialize.toast('<i class="material-icons red-text text-accent-4">error</i>'+data.responseText, 4000, "rounded");
                },
            });
            return false;
        });
    });
</script>
</body>
</html>
