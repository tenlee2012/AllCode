<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<html>
<title>Index</title>
<body>
<meta charset="utf-8"/>
<h2>Hello World!</h2>
<% out.println("IP:" + request.getRemoteAddr()); %>
<br />
<p>Today's is <%= new java.util.Date().toLocaleString()%></p>
<%! int day=3; %>
<% int d=3; %>
<% out.println(day++); %>
<% out.println(d++); %>
<% if(day == 6 || day == 7) {%>
    <p>今天是周末</p>
<% } else { %>
    <p>今天不是周末</p>
<%} %>
</body>
</html>
