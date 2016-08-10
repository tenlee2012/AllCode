<#if mymap?exists>
    <#list mymap?keys as mapKey>
        ${mapKey}
    ${mymap[mapKey]}
    </#list>
</#if>
<#if bibibi??>
 bibibi
<#else>
 iiii
</#if>
