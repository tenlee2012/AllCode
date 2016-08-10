<%--
  Created by IntelliJ IDEA.
  User: ljh
  Date: 2016/8/6
  Time: 17:19
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" %>

<html>
<head>
    <title>首页</title>
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
        <div class="col s0 m3">&nbsp;</div>
        <div class="col s12 m6">
            <ul class="collection with-header">
                <li class="collection-header"><h4>页面链接</h4></li>
                <li class="collection-item"><a href="/login"><h5>登录</h5></a></li>
                <li class="collection-item"><a href="/film.jsp"><h5>查看film, jsp页面</h5></a></li>
                <li class="collection-item"><a href="/addfilm.jsp"><h5>添加界面, 使用jsp页面</h5></a></li>
                <li class="collection-item"><a href="/editfilm?id=1"><h5>编辑页面, 此处是编辑id=1的链接,使用freemarker</h5></a></li>
            </ul>
            <ul class="collection with-header">
                <li class="collection-header"><h5>Restful API</h5></li>
                <li class="collection-item">添加film, /api/film/, 方法 POST</li>
                <li class="collection-item">删除film, /api/film/id, 方法 DELETE</li>
                <li class="collection-item">修改film, /api/film/id, 方法 PUT</li>
            </ul>
        </div>
    </div>
</div>
</body>
<script src="https://cdn.bootcss.com/jquery/3.1.0/jquery.min.js"></script>
<script src="https://cdn.bootcss.com/materialize/0.97.7/js/materialize.min.js"></script>
</html>
