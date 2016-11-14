package com.anishitani.cvcamera;

import android.view.Surface;

/**
 * Created by anishitani on 11/9/16.
 */

public class JNIInterface {
    public JNIInterface() {
        System.loadLibrary("native-lib");
    }

    public native void processImage(int width, int height, byte[] image, Surface surface);
}
