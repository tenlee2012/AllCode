<%--
  Created by IntelliJ IDEA.
  User: ljh
  Date: 2016/8/3
  Time: 10:55
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="javax.servlet.http.Cookie" %>
<%@ page import="com.hand.sql.entity.User" %>
<% User u = (User)request.getAttribute("user"); %>
<html>
<head>
    <title>登录成功</title>
</head>
<body>
<p>用户名: <%= u.getName() %></p>
<p>密码: <%= u.getEmail() %></p>
<img src="<%= u.getPicture()%>"/>
</body>
</html>
