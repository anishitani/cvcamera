#include <jni.h>

#include <android/log.h>

#define  LOG_TAG    "native-lib"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C"
void
Java_com_anishitani_cvcamera_JNIInterface_processImage(
        JNIEnv *env, jobject obj,
        jint width, jint height, jbyteArray image
) {
    jboolean isCopy;
    unsigned char* _image = (unsigned char *) env->GetByteArrayElements(image,&isCopy);



    LOGI("HELLO WORLD!");
}
