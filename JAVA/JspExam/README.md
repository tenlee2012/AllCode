####编译
```
mvn clean compile
```
#### 运行
```
mvn jetty:run
```
打开浏览器**http://localhost:8081/**即可访问

数据库配置文件在**src\main\resources\dbconfig.properties**

##说明
 1. 第一题, 使用`index.jsp`,显示本次实现所有功能的链接.

 2. 第二题, 使用`freemarker`作为模板引擎, 设计登录界面.地址为`/login`,
    处理为`com.hand.servlet.loginServlet`, 调用`com.hand.dao.UserDao`的
    方法进行登录验证, **区分大小写**.

 3. 第三题, 按照要求, film列表页的显示 和 添加信息页面  使用**JSP**,
    没有使用 freemarker.
     - 显示页面 film.jsp为film显示界面, 每页20条信息, 只要调用
          `com.hand.dao.FilmDao`(Film增删查改的类),
          `com.hand.utils.PageUtil`(分页工具).

     - 新增页面 addfilm.jsp, 为film添加页面,
      处理是`com.hand.servlet.FilmAPIServlet`(Film增删查改的Servlet)
     **页面使用AJAX调用RestfulAPI实现**

     - 删除功能, 点击删除会出现确认删除对话框, 处理是`com.hand.servlet.FilmAPIServlet`(Film增删查改的Servlet)
     **页面使用AJAX调用RestfulAPI实现**

 4. 编辑功能, 使用freemarker作为模板, 文件为editfilm.ftl, servlet为 `com.hand.servlet.FilmAPIServlet`
     **页面使用AJAX调用RestfulAPI实现**

 4. 编辑功能, 使用freemarker作为模板, 文件为editfilm.ftl, servlet为 `com.hand.servlet.FilmAPIServlet`
     **页面使用AJAX调用RestfulAPI实现**

 5. filter过滤未登陆用户,重定向到/login界面
 类说明
 懒得写了
