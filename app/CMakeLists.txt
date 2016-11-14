cmake_minimum_required(VERSION 3.4.1)

set( OPENCV_ANDROID_SDK $ENV{HOME}/tools/android/OpenCV-android-sdk/sdk )

add_library( opencv_core STATIC IMPORTED )
set_target_properties(
  opencv_core PROPERTIES IMPORTED_LOCATION
  ${OPENCV_ANDROID_SDK}/native/libs/${ANDROID_ABI}/libopencv_core.a
)

add_library( opencv_3rdparty STATIC IMPORTED )
set_target_properties(
  opencv_3rdparty PROPERTIES IMPORTED_LOCATION
  ${OPENCV_ANDROID_SDK}/native/3rdparty/libs/${ANDROID_ABI}/libtbb.a
)

set( OPENCV_ANDROID_LIBS opencv_core opencv_3rdparty )

include_directories( ${OPENCV_ANDROID_SDK}/native/jni/include )

message( "Android ABI is ${ANDROID_ABI}" )

add_library( native-lib SHARED
             src/main/cpp/native-lib.cpp )

target_link_libraries( native-lib
                       android
                       jnigraphics
                       log m z
                     ${OPENCV_ANDROID_LIBS})
