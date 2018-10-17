/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_learn_jnitest_Hello */

#ifndef _Included_com_learn_jnitest_Hello
#define _Included_com_learn_jnitest_Hello
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_learn_jnitest_Hello
 * Method:    hello
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_learn_jnitest_Hello_hello
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    test
 * Signature: (ZBCSIJFDLjava/lang/String;Ljava/lang/Object;Lcom/learn/jnitest/MyClass;[I)V
 */
JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_test
  (JNIEnv *, jclass, jboolean, jbyte, jchar, jshort, jint, jlong, jfloat, jdouble, jstring, jobject, jobject, jintArray);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    critical
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_learn_jnitest_Hello_critical
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    region
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_learn_jnitest_Hello_region
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    sumArray
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_com_learn_jnitest_Hello_sumArray
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    sum2dArray
 * Signature: ([[I)I
 */
JNIEXPORT jint JNICALL Java_com_learn_jnitest_Hello_sum2dArray
  (JNIEnv *, jclass, jobjectArray);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    initIntArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_learn_jnitest_Hello_initIntArray
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    objArray
 * Signature: ([Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_objArray
  (JNIEnv *, jclass, jobjectArray);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    callJavaStaticMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_callJavaStaticMethod
  (JNIEnv *, jclass);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    callJavaInstanceMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_callJavaInstanceMethod
  (JNIEnv *, jclass);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    accessStaticField
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_accessStaticField
  (JNIEnv *, jclass);

/*
 * Class:     com_learn_jnitest_Hello
 * Method:    accessInstanceField
 * Signature: (Lcom/learn/jnitest/Hello;)V
 */
JNIEXPORT void JNICALL Java_com_learn_jnitest_Hello_accessInstanceField
  (JNIEnv *, jclass, jobject);

#ifdef __cplusplus
}
#endif
#endif