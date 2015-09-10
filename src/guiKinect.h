
#ifndef ___24ofParameterGUIClass__guiKinect__
#define ___24ofParameterGUIClass__guiKinect__

#include "ofMain.h"

class GuiKinect {
public:
    void setup();
    void draw();
    
    ofParameterGroup kinectParameters;
    ofParameter<bool> gKtoggleOnOff;
    ofParameter<bool> gKtoggleLoad;
    ofParameter<bool> gKtoggleShowImage;
    ofParameter<bool> gKtoggleGrayscale;
    ofParameter<bool> gKtoggleMask;
    ofParameter<bool> gKtoggleDetect;
    ofParameter<ofVec2f> gK2SliderScale;
    ofParameter<bool> gKtoggFit;
    ofParameter<bool> gKtoggKeepAspect;
    ofParameter<bool> gKtoggHflip;
    ofParameter<bool> gKtoggVflip;
    ofParameter<ofFloatColor> gKcolor;
    ofParameter<bool> gKtoggGreenscreen;
    ofParameterGroup kinectParametersSecond;
    ofParameter<float>  gKfsliderTrshNear;
    ofParameter<float>  gKfsliderTrshFar;
    ofParameter<float>  gKfsliderAngle;
    ofParameter<float>  gKfsliderBlur;
    ofParameter<float>  gKfsliderBlobiMin;
    ofParameter<float>  gKfsliderBlobMax;
    ofParameter<float>  gKfsliderSmooth;
    ofParameter<float>  gKfsliderSimplify;

};
#endif
