#include "guiCamera.h"

void GuiCamera::setup(){
    cameraParameters.add(gCtoggleOnOff.set("Camera On/Off",false));
    //cameraParameters.add(gCtoggleShowImage.set("Camera show image",false));
    //cameraParameters.add(gCtoggleGrayscale.set("Camera grayscale",false));
    //cameraParameters.add(gCtoggleMask.set("Camera mask",false));
    //cameraParameters.add(gCtoggleDetect.set("Camera detect",false));
    cameraParameters.add(gC2SliderScale.set("Scale Camera ",ofVec2f(1,1), ofVec2f(0.1, 0.1), ofVec2f(10,10)));
    cameraParameters.add(gCtoggFit.set("Fit Camera to quad",false));
    cameraParameters.add(gCtoggKeepAspect.set("Keep Camera aspect ratio",false));
    cameraParameters.add(gCtoggHflip.set("Camera horizontal flip",false));
    cameraParameters.add(gCtoggVflip.set("Camera vertical flip",false));
    cameraParameters.add(gCcolor.set("Camera color",ofFloatColor(1,1,1), ofFloatColor(0, 0), ofFloatColor(1,1)));
    cameraParameters.add(gCtoggGreenscreen.set("Camera Greenscreen",false));
    cameraParameters.add(gCfsliderVolume.set("Camera Volume",0.0, 0.0, 1.0));
    cameraParametersSecond.add(gCtoggleSampler.set("Camera sampler playback",false));

}

void GuiCamera::draw(){
    //ofSetColor(red, green, blue);
    //ofCircle(posX, posY, radius);
}




