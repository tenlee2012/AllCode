#### 生成
mvn archetype:generate -DgroupId=com.hand -DartifactId=Exam03 -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
#### 编译
mvn compile clean
#### 运行
mvn exec:java -Dexec.mainClass="com.hand.App"
