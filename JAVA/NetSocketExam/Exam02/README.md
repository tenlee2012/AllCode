#### 生成
mvn archetype:generate -DgroupId=com.hand -DartifactId=Exam02 -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
#### 编译
mvn compile clean
#### 运行服务器
mvn exec:java -Dexec.mainClass="com.hand.MyServer"
#### 运行客户端
mvn exec:java -Dexec.mainClass="com.hand.MyClient"
