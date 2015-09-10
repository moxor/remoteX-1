
#ifndef ___24ofParameterGUIClass__guiCamera__
#define ___24ofParameterGUIClass__guiCamera__

#include "ofMain.h"


class GuiCamera {
public:
    void setup();
    void draw();
    
    ofParameterGroup cameraParameters;
    ofParameter<bool> gCtoggleOnOff;
    ofParameter<bool> gCtoggleShowImage;
    ofParameter<bool> gCtoggleGrayscale;
    ofParameter<bool> gCtoggleMask;
    ofParameter<bool> gCtoggleDetect;
    ofParameter<ofVec2f> gC2SliderScale;
    ofParameter<bool> gCtoggFit;
    ofParameter<bool> gCtoggKeepAspect;
    ofParameter<bool> gCtoggHflip;
    ofParameter<bool> gCtoggVflip;
    ofParameter<ofFloatColor> gCcolor;
    ofParameter<bool> gCtoggGreenscreen;
    ofParameter<float>  gCfsliderVolume;
    ofParameterGroup cameraParametersSecond;
    ofParameter<bool>  gCtoggleSampler;

};
#endif
