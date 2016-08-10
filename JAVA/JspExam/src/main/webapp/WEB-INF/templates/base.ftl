<#macro page title>
<html>
<head>
    <title>${title?html}</title>
    <meta charset="utf-8">
    <#--<link href="/static/css/materialize.min.css" rel="stylesheet">-->
    <link href="https://cdn.bootcss.com/materialize/0.97.7/css/materialize.min.css" rel="stylesheet">
    <link href="https://cdn.bootcss.com/material-design-icons/2.2.3/iconfont/material-icons.css" rel="stylesheet">
    <script src="https://cdn.bootcss.com/jquery/3.1.0/jquery.min.js"></script>
    <script src="https://cdn.bootcss.com/materialize/0.97.7/js/materialize.min.js"></script></head>
<body>
<#nested >
</body>

<#--<script src="/static/js/materialize.min.js"></script>-->
</html>
</#macro>