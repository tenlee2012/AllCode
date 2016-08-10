<%--
  Created by IntelliJ IDEA.
  User: ljh
  Date: 2016/8/3
  Time: 10:31
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<div>
    <form action="<%= request.getContextPath()%>/login" method="post"
        name="loginForm" id="loginForm">
        <p>UserName:</p><input type="text" name="username" id="username"/>
            <label style="color: red;" id="n_err"></label>
        <p>Password:</p><input type="password" name="password" id="password">
            <label style="color: red;" id="p_err"></label>
        <br />
        <input type="submit" value="Login"
               id="login_btn">
        <input type="reset" value="Reset">
    </form>
</div>
<script src="http://cdn.bootcss.com/jquery/1.11.2/jquery.min.js"></script>
<script>
    $(document).ready()
    {
        $("#login_btn").click(function () {
            if($("#username").val() == "") {
//                alert("请输入用户名");
                $("#username").focus();
                $("#n_err").text("请输入用户名");
                return false;
            }
            if($("#password").val() == "") {
//                alert("请输入密码");
                $("#password").focus();
                $("#p_err").text("请输入密码");
                return false;
                return false;
            }
            return true;
        });
    }
</script>
</body>
</html>
