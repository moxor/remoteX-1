#include "guiImage.h"

void GuiImage::setup(){

    imageParameters.add(gItoggleOnOff.set("Image On/Off",false));
    imageParameters.add(gItoggleLoad.set("Load Image",false));
    imageParameters.add(gI2SliderScale.set("Scale Image",ofVec2f(1,1), ofVec2f(0.1, 0.1), ofVec2f(10,10)));
    imageParameters.add(gItoggFit.set("Fit image to quad",false));
    imageParameters.add(gItoggKeepAspect.set("Keep image aspect ratio",false));
    imageParameters.add(gItoggHflip.set("Image horizontal flip",false));
    imageParameters.add(gItoggVflip.set("Image vertical flip",false));
    imageParameters.add(gIcolor.set("Image color",ofFloatColor(1,1,1), ofFloatColor(0, 0), ofFloatColor(1, 1)));
    imageParameters.add(gItoggGreenscreen.set("Image Greenscreen",false));
}

void GuiImage::draw(){
    //ofSetColor(red, green, blue);
    //ofCircle(posX, posY, radius);
}


