#include <jni.h>

#include <android/log.h>
#include <android/native_window_jni.h>

#include <opencv2/opencv.hpp>

#define  LOG_TAG    "native-lib"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C"
void
Java_com_anishitani_cvcamera_JNIInterface_processImage(
        JNIEnv *env, jobject obj,
        jint width, jint height,
        jbyteArray image, jobject surface
) {
    jboolean isCopy;
    unsigned char* _image = (unsigned char *) env->GetByteArrayElements(image,&isCopy);

    ANativeWindow *win = ANativeWindow_fromSurface(env,surface);

    int32_t w = ANativeWindow_getWidth(win);
    int32_t h = ANativeWindow_getHeight(win);
    LOGI("Tamanho: %dx%d", w, h);

    ANativeWindow_Buffer buff;
    ANativeWindow_setBuffersGeometry(win,w,h,WINDOW_FORMAT_RGBA_8888);
//    if(int32_t err = ANativeWindow_lock(win, &buff, NULL)){
//        LOGE("ANativeWindow_lock failed with error code %d\n", err);
//        ANativeWindow_release(win);
//        return;
//    }
    uint8_t *data = reinterpret_cast<uint8_t*>(buff.bits);
    cv::Mat red(w,h,CV_8UC4,data);
    red.setTo(cv::Scalar(255,0,0,0));
    ANativeWindow_unlockAndPost(win);
    ANativeWindow_release(win);
}
