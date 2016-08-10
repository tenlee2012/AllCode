<#import "base.ftl" as com>
<#escape x as x?html>
    <@com.page title="编辑电影信息">
<div class="navbar-fixed">
    <ul id="dropdown1" class="dropdown-content">
        <li><a href="${context_path!""}/film.jsp">所有电影</a></li>
        <li><a href="${context_path!""}/addfilm.jsp">添加电影</a></li>
    </ul>
    <nav class="teal lighten-2">
        <div class="nav-wrapper container">
            <a href="${context_path!""}/" class="brand-logo">Logo</a>
            <ul class="right hide-on-med-and-down">
                <li><a href="${context_path!""}/">首页</a></li>
                <li><a class="dropdown-button active" href="${context_path!""}/film.jsp" data-activates="dropdown1"
                       data-beloworigin="true" data-hover="true">电影<i class="mdi-navigation-arrow-drop-down right"></i></a></li>
                <li><a href="#">关于</a></li>
                <#if name??>
                    <li>${name}</li>
                    <li><a href="${context_path!""}/logout">退出</a></li>
                <#else>
                    <li><a href="${context_path!""}/login">登录</a></li>
                </#if>
            </ul>
        </div>
    </nav>
</div>
    <div class="container">
        <div class="row">&nbsp;</div>
        <div class="row">
            <div class="col s0 m3">&nbsp;</div>
            <div class="col s12 m6">
                <form method="post">
                    <div class="row">
                        <div class="input-field col s12">
                            <input readonly="readonly" id="film_id" name="film_id" type="text" class="validate" value="${film_id?c!"null"}">
                            <label for="last_name">Film id</label>
                        </div>
                    </div>
                    <div class="row">
                        <div class="input-field col s12">
                            <input name="title" id="title" type="text" class="validate" value="${title!"null"}">
                            <label for="Title">Title</label>
                        </div>
                    </div>
                    <div class="row">
                        <div class="input-field col s12">
                            <textarea id="desc" name="desc" class="materialize-textarea">${desc!""}</textarea>
                            <label for="Description">Description</label>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col s12">
                        <select name="language_id" id="language_id">
                            <#if all_language?exists>
                            <#list all_language?keys as lan>
                                <#if lan=language_id?string>
                                    <option selected="selected" value="${lan}">${all_language[lan]}</option>
                                <#else>
                                    <option value="${lan}">${all_language[lan]}</option>
                                </#if>
                            </#list>
                            </#if>
                        </select>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col s12">
                            <div class="input-field col s6 m5 center-align">&nbsp;</div>
                            <div class="input-field col s6 m3 center-align">&nbsp;</div>
                            <div class="input-field col s12 m4 right-align">
                                <button type="submit" id="submit_btn" class="waves-effect teal lighten-2 btn accent-4">修改</button>
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
        $("#submit_btn").click(function() {
            var title = $("#title").val();
            var desc = $("#desc").val();
            var lan_id = $("#language_id").val();
            if(title == "") {
                Materialize.toast('<i class="material-icons red-text text-accent-4">warning</i>标题没写', 2000);
                return false;
            }
            if(desc == "") {
                Materialize.toast('<i class="material-icons red-text text-accent-4">warning</i>描述没写', 2000);
                return false;
            }
            if(lan_id == "") {
                Materialize.toast('<i class="material-icons red-text text-accent-4">warning</i>语言没写', 2000);
                return false;
            }
            $.ajax ({
                url: "/api/film/"+$("#film_id").val(),
                method: "put",
                data: {"film_id": $("#film_id").val(), "title": $("#title").val(),
                    "desc": $("#desc").val(), "language_id":$("#language_id").val()},
                success: function(data) {
                    console.log(data);
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
</@com.page>
</#escape>
