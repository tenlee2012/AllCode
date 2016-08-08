Hello, ${user}
=======测试if语句========
<#if user=="haha">
sb;
<#else>
dasb;
</#if>
=========测试list====
<#list lst as dizhi>
    ${dizhi}
</#list>
========包含指令====
<#include "included.txt">
========定义无参宏======
<#macro m1>
    <b>aaaaaa</b>
</#macro>
========定义带参数宏======
<#macro m2 a b>
    <b>hello, ${a}--${b}</b>
</#macro>
========调用宏======
<@m1/><@m1/>
<@m2 "xiaohong" "xiaobai"/>
=========内建函数==========
${htm2?html} 会转义
${sss!"is null"}
<#if haha?length<10>haha1</#if>
<#if haha?length<1>haha2</#if>
=========内建函数==========
<#list 1..5 as i>
    ${i}
</#list>
