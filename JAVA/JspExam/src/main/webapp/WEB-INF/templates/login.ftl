<#import "base.ftl" as com>
<#escape x as x?html>

    <@com.page title="登录">
    <div class="navbar-fixed">
        <ul id="dropdown1" class="dropdown-content">
            <li><a href="/film.jsp">所有电影</a></li>
            <li><a href="/addfilm.jsp">添加电影</a></li>
        </ul>
        <nav class="teal lighten-2">
            <div class="nav-wrapper container">
                <a href="/" class="brand-logo">Logo</a>
                <ul class="right hide-on-med-and-down">
                    <li><a href="/">首页</a></li>
                    <li><a class="dropdown-button" href="/film.jsp" data-activates="dropdown1"
                           data-beloworigin="true" data-hover="true">电影<i class="mdi-navigation-arrow-drop-down right"></i></a></li>
                    <li><a href="#">关于</a></li>
                    <li class="active"><a href="/login">登录</a></li>
                </ul>
            </div>
        </nav>
    </div>
    <div class="container">
        <div class="row">&nbsp;</div>
        <div class="row">
            <div class="col s0 m3">&nbsp;</div>
            <form class="card col s12 m6" method="post">
                <div class="row">
                    <div class="input-field col s12">
                        <h5 class="grey-text text-darken-1 center-align">请输入你的first name</h5>
                    </div>
                </div>
                <div class="row">
                    <div class="input-field col s12 center-align">
                        <i class="material-icons large teal-text">account_circle</i>
                    </div>
                </div>
                <div class="row">
                    <div class="input-field col s12">
                        <input name="name" type="text" required="true"
                        data-position="top" data-delay="50" data-tooltip="你的first name"
                        class="validate tooltipped">
                        <label for="acct_email">first name</label>
                    </div>
                    <p class="center-align" style="color:red;">${error_message!""}</p>
                </div>
                <div class="row">
                    <div class="input-field col s6 m5 center-align">&nbsp;</div>
                    <div class="input-field col s6 m3 center-align">&nbsp;</div>
                    <div class="input-field col s12 m4 right-align">
                        <button class="btn waves-effect waves-light" type="submit" name="action">登录
                            <i class="material-icons right">send</i>
                        </button>
                    </div>
                </div>
            </form>
        </div>
    </div>
    </@com.page>
</#escape>
