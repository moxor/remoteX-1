#include "guiKinect.h"

void GuiKinect::setup(){
    kinectParameters.add(gKtoggleOnOff.set("Kinect  On/Off",false));
    kinectParameters.add(gKtoggleLoad.set("Kinect close/open ",false));
    kinectParameters.add(gKtoggleShowImage.set("Kinect show image",false));
    kinectParameters.add(gKtoggleGrayscale.set("Kinect grayscale",false));
    kinectParameters.add(gKtoggleMask.set("Kinect mask",false));
    kinectParameters.add(gKtoggleDetect.set("Kinect detect",false));
    kinectParameters.add(gK2SliderScale.set("Scale Kinect ",ofVec2f(1,1), ofVec2f(0.1, 0.1), ofVec2f(10,10)));
    kinectParameters.add(gKtoggFit.set("Fit Kinect  to quad",false));
    kinectParameters.add(gKtoggKeepAspect.set("Keep Kinect  aspect ratio",false));
    kinectParameters.add(gKtoggHflip.set("Kinect  horizontal flip",false));
    kinectParameters.add(gKtoggVflip.set("Kinect  vertical flip",false));
    kinectParameters.add(gKcolor.set("Kinect  color",ofFloatColor(1,1,1), ofFloatColor(0, 0), ofFloatColor(1,1)));
    kinectParameters.add(gKtoggGreenscreen.set("Kinect  Greenscreen",false));

    kinectParametersSecond.add(gKfsliderTrshNear.set("Kinect threshold near", 255.0, 0.0, 255.0));
    kinectParametersSecond.add(gKfsliderTrshFar.set("Kinect threshold far", 0.0,0.0, 255.0));
    kinectParametersSecond.add(gKfsliderAngle.set("Kinect angle",0.0,-30.0, 30.0));
    kinectParametersSecond.add(gKfsliderBlur.set("Kinect blur",  3.0,0.0, 10.0));
    kinectParametersSecond.add(gKfsliderBlobiMin.set("Kinect min blob", 0.01,  0.01,1.0));
    kinectParametersSecond.add(gKfsliderBlobMax.set("Kinect max blob",  1.0, 0.01,1.0));
    kinectParametersSecond.add(gKfsliderSmooth.set("Kinect smooth", 10.0,0.0, 20.0));
    kinectParametersSecond.add(gKfsliderSimplify.set("Kinect simplify", 0.0,  0.0,2.0));
}

void GuiKinect::draw(){
    //ofSetColor(red, green, blue);
    //ofCircle(posX, posY, radius);
}


