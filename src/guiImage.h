
#include "ofMain.h"

class GuiImage {
public:
    void setup();
    void draw();
    
    ofParameterGroup imageParameters;
    ofParameter<bool> gItoggleOnOff;
    ofParameter<bool> gItoggleLoad;
    ofParameter<ofVec2f> gI2SliderScale;
    ofParameter<bool> gItoggFit;
    ofParameter<bool> gItoggKeepAspect;
    ofParameter<bool> gItoggHflip;
    ofParameter<bool> gItoggVflip;
    ofParameter<ofFloatColor> gIcolor;
    ofParameter<bool> gItoggGreenscreen;
};
