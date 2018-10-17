

JniTest$ javac com/learn/jnitest/Hello.java -d ./bin
JniTest$ javah -jni -cp ./bin -d ./jni com.learn.jnitest.Hello
jni$ g++ -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -fPIC -shared -o libhello.so hello.cpp
JniTest]$ java -Djava.library.path=./jni -cp ./bin com.learn.jnitest.Hello