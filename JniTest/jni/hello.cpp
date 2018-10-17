
#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "com_learn_jnitest_Hello.h"

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#ifdef __cplusplus
extern "C"
{
#endif 

JNIEXPORT jstring JNICALL Java_com_learn_jnitest_Hello_hello(JNIEnv *env, jclass cls, jstring j_str){
    const char* c_str = NULL;
    char buff[128] = {0};
    // NewString / NewStringUTF C++字符串转jni字符串
    // GetStringChars / GetStringUTFChars  jni字符串转C++字符串
    // ReleaseStringChars / ReleaseStringUTFChars  释放jni字符串，和NewString(UTF)配合使用

    // 数组 Get<Type>ArrayElements 
    // 子数组 Get<Type>ArrayRegon

    // 对象数组 GetObjectArrayElements / GetObjectArrayElements

    // jni数组长度 GetArrayLength 

    //共享大数据  NewDirectByteBuffer / GetDirectBufferAddress / GetDirectBufferCapacity

    //*********JNI 访问 java*************//
    // GetObjectClass 获取实例的类类型
    // GetMethodID 获取实例的方法id
    // GetStaticMethodID 获取类方法id
    // Call<Type>Method 调用有特定返回值的实例方法
    // CallStatic<Type>Method 调用有特定返回值的类方法

// GetFieldID  获取实例属性id
// Get<Type>Field  获取实例属性的值
// GetStaticFieldID  获取类属性id
// GetStatic<Type>Field  获取类属性值

// 线程同步 MonitorEnter / MonitorExit

// 引用处理  DeleteLocalRef
// 强全局引用 NewGlobalRef / DeleteGlobalRef
// 弱全局引用 NewWeakGlobalRef / DeleteWeakGlobalRef
// isSameObject 

c_str = env->GetStringUTFChars(j_str, NULL); 
if (NULL == c_str) {
    printf("out of memory\n");
    return NULL;
}

printf("c_str: %s\n", c_str);
snprintf(buff, sizeof(buff), c_str, strlen(c_str));

env->ReleaseStringUTFChars(j_str, c_str);
return env->NewStringUTF(buff);

}

JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_test(JNIEnv* env, jclass cls, 
            jboolean z, jbyte b, jchar c, jshort s, jint n, jlong l, jfloat f, jdouble d,
            jstring str, jobject obj1, jobject obj2, jintArray arr){
    printf("%s, %d, %c, %hd, %d, %ld, %f, %lf\n", z==0?"false":"true", b, c, s, n, l, f, d);
    const char* c_str = NULL;
    c_str = env->GetStringUTFChars(str, NULL);
    if (NULL == c_str) {
        printf("out of memory\n");
        return ;
    }

    env->ReleaseStringUTFChars(str, c_str);

    return ;
} 


JNIEXPORT jstring JNICALL Java_com_learn_jnitest_Hello_critical(JNIEnv *env, jclass cls, jstring jstr)
{
    const jchar* c_str = NULL;
    char buff[128] = "hello ";
    char* pBuff = buff + 6;
    c_str = env->GetStringCritical(jstr, NULL);
    if (NULL == c_str) {
        printf("out of memory\n");
        return NULL;
    }

    while (*c_str) {
        *pBuff++ = *c_str++;
    }
    env->ReleaseStringCritical(jstr, c_str);
    return env->NewStringUTF(buff);
}

JNIEXPORT jstring JNICALL Java_com_learn_jnitest_Hello_region(JNIEnv *env, jclass cls, jstring jstr)
{
    char buff[128] = "hello ";
    char* pBuff = buff + 6;
    jint len = env->GetStringLength(jstr);
    // 将jstr中的unicode字符串以utf编码拷贝到缓存中
    env->GetStringUTFRegion(jstr, 0, len, pBuff); 

    return env->NewStringUTF(buff);

}


JNIEXPORT jint JNICALL Java_com_learn_jnitest_Hello_sumArray(JNIEnv *env, jclass cls, jintArray arr)
{
    jint sum = 0;
    jint len = env->GetArrayLength(arr);
#ifdef ELEMENTS
        jint* pint = env->GetIntArrayElements(arr, NULL);
#elif CRITICAL
    // 暂停JVM GC
    jint* pint = env->GetPrimitiveArrayCritical(arr, NULL);
#else
    jint* pint = (jint*)malloc(len*sizeof(jint));
    env->GetIntArrayRegion(arr, 0, len, pint);
#endif
    for(int i = 0; i < len; ++i){
        sum += pint[i];
    }
#ifdef ELEMENTS
    env->ReleaseIntArrayElements(arr, pint, 0);
#elif CRITICAL
    env->ReleasePrimitiveArrayCritical(arr, pint, 0);
#endif 
    return sum;

}


JNIEXPORT jint JNICALL Java_com_learn_jnitest_Hello_sum2dArray(JNIEnv *env, jclass cls, jobjectArray objarr)
{
    jint sum = 0;
    int len  = env->GetArrayLength(objarr);
    int sublen = 0;
    jint* pint = NULL;
    printf("objarr len: %d\n", len);
    for (int i = 0; i < len; ++i) {
        jintArray item = (jintArray)env->GetObjectArrayElement(objarr, i);
        sublen = env->GetArrayLength(item);
        pint = env->GetIntArrayElements(item, NULL);
        for (int j = 0; j < sublen; ++j) {
            //printf("subElement: %d\n", pint[j]);
            sum += pint[j];
        }
        env->ReleaseIntArrayElements(item, pint, 0);
    }

    return sum;
}

JNIEXPORT jobjectArray JNICALL Java_com_learn_jnitest_Hello_initIntArray(JNIEnv *env, jclass cls, jint size) 
{
    // 创建一个int[] 的引用
    jclass intcls = env->FindClass("[I");
    if (NULL == intcls) {
        printf("find class fail\n");
        return NULL;
    }
    // 创建一个对象数组
    jobjectArray objarr = env->NewObjectArray(size, intcls, NULL);
    if (NULL == objarr) {
        printf("new class fail\n");
        return NULL;
    }
    // 赋值
    int buff[size];
    jintArray intarr = NULL;
    for (int i = 0; i < size; ++i) {
        // 创建临时数组对象
        intarr = env->NewIntArray(size);
        if (NULL == intarr) {
            printf("new int array fail");
            return NULL;
        }
        for(int j = 0; j < size; ++j) {
            buff[j] = i*j;
            printf("%d,", buff[j]);
        }
        printf("\n");
        env->SetIntArrayRegion(intarr, 0, size, buff);
        env->SetObjectArrayElement(objarr, i, intarr);
        env->DeleteLocalRef(intarr);
    }

    return objarr;
}

JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_callJavaStaticMethod
  (JNIEnv *env, jclass cls)
{
    //1. 从classpath路径下搜索Hello这个类并返回类Class对象 

    jclass clz = env->FindClass("com/learn/jnitest/Hello");
    if (NULL == clz) {
        printf("find class fail\n");
        return ;
    }
    if (env->IsInstanceOf(clz, cls)) {
        printf("cls is instance of hello\n");
        jclass clz = env->GetObjectClass(cls);
    } else {
        printf("cls is not instance of hello\n");
    }
    //2. 获取methodid
    jmethodID mid = env->GetStaticMethodID(cls, "classMethod", "(Ljava/lang/String;I)V");
    if (NULL == mid) {
        printf("get static method id fail\n");
        return ;
    }
    //3. 构造参数(optional)
    jstring str = env->NewStringUTF("get static method ok");
    //4. 调用CallStaticVoidMethod
    env->CallStaticVoidMethod(cls, mid, str, 1);
    //5. 释放局部引用
    env->DeleteLocalRef(str);
    env->DeleteLocalRef(clz);

    return ;

}

JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_callJavaInstanceMethod
  (JNIEnv *env, jclass cls)
{
    //1. 从classpath路径中搜索class文件
    jclass clz = env->FindClass("com/learn/jnitest/Hello");
    if (NULL == clz) {
        printf("find class fail\n");
        return ;
    }
    //2. 从class文件中搜索method
    jmethodID mid = env->GetMethodID(clz, "instanceMethod", "(Ljava/lang/String;I)V");
    if (NULL == mid) {
        printf("get method id fail\n");
        return ;
    }

    //3. 构造参数(optional)
    jstring str = env->NewStringUTF("get method id ok");

#if 0
    //5. 调用CallVoidMethod
    jobject obj = env->NewObject(clz, mid, str, 1);
#endif

    //4. 创建该类的实例
    jmethodID mid_con = env->GetMethodID(clz, "<init>", "()V");
    jobject obj = env->NewObject(clz, mid_con);
    env->CallVoidMethod(obj, mid, str, 1);

    //6. 释放局部引用
    env->DeleteLocalRef(str);
    env->DeleteLocalRef(clz);
    env->DeleteLocalRef(obj);

    return ;
}

JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_accessStaticField(JNIEnv *env, jclass cls)
{
    // .在classpath路径中搜索class
    jclass clz = env->FindClass("com/learn/jnitest/Hello");
    if (NULL == clz) {
        printf("find class fail\n");
        return ;
    }

    // .在class中搜索field id
    jfieldID fid = env->GetStaticFieldID(clz, "name", "Ljava/lang/String");
    if (NULL == fid) {
        printf("get static field id fail\n");
        return ;
    }

    // .获取field value
    jstring str = (jstring)env->GetStaticObjectField(clz, fid);
    if (NULL == str) {
        printf("get static object fail\n");
        return ;
    }
    const char* pstr = env->GetStringUTFChars(str, NULL);
    if (NULL == pstr) {
        printf("get string utf fail\n");
        return ;
    }
    printf("field value: %s\n", pstr);
    env->ReleaseStringUTFChars(str, pstr);

    // .重设filed的值
    jstring s = env->NewStringUTF("max");
    if (NULL == s) {
        printf("new string utf fail\n");
        return ;
    }

    env->SetStaticObjectField(clz, fid, s);

    // .释放局部引用
    env->DeleteLocalRef(clz);
    env->DeleteLocalRef(str);
    env->DeleteLocalRef(s);

    return ;

}

JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_accessInstanceField(JNIEnv *env, jclass cls, jobject obj)
{
    // .在classpath中搜索class
    jclass clz = env->FindClass("com/learn/jnitest/Hello");
    if (NULL == clz) {
        printf("find class fail\n");
        return ;
    }

    clz = env->GetObjectClass(obj);

    // .在class中搜索field id
    jfieldID fid = env->GetFieldID(clz, "str", "Ljava/lang/String");
    if (NULL == fid) {
        printf("get field fail \n");
        return ;
    }
    jfieldID fintid = env->GetFieldID(clz, "len", "I");
    if (NULL == fintid) {
        printf("get int field fail \n");
        return ;
    }
    
    if (env->IsInstanceOf(obj, clz)) {
        // .获取field value
        jstring str = (jstring)env->GetObjectField(obj, fid);
        const char* pstr = env->GetStringUTFChars(str, NULL);
        if (NULL == pstr) {
            printf("get string utf fail\n");
            return ;
        }
        printf("field value: %s\n", pstr);
        env->ReleaseStringUTFChars(str, pstr);

        // .重设field的值
        jstring s = env->NewStringUTF("rongyao");
        env->SetObjectField(obj, fid, s);
        env->DeleteLocalRef(str);
        env->DeleteLocalRef(s);

        // .int field
        jint val = env->GetIntField(obj, fintid);
        printf("field value: %d\n", (int)val);
        env->SetIntField(obj, fintid, 8);
    }

    env->DeleteLocalRef(clz);
    return ;
}

#ifdef __cplusplus
}
#endif

