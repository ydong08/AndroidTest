#include <jni.h>
#include <string>
#include <android/log.h>

static const char* TAG = "Native";
#define LOGI(fmt, args...)  __android_log_print(ANDROID_LOG_INFO, TAG, fmt, ##args);
#define LOGD(fmt, args...)  __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args);
#define LOGE(fmt, args...)  __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_castles_activethread_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL Java_com_castles_activethread_MainActivity_getbuf(JNIEnv* env, jobject thiz) {

    int num = 10;
    while(0 < --num) {
        LOGI("getbuf: %d", num);
    }
}
