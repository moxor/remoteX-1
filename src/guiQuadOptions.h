
#include "ofMain.h"

class GuiQuadOptions {
public:
    void setup();
    void draw();
    
    ofParameterGroup quadOptionsCropParameters;
    ofParameter<float> gQSliderCrRcTop;
    ofParameter<float> gQSliderCrRcRight;
    ofParameter<float> gQSliderCrRcLeft;
    ofParameter<float> gQSliderCrRcBottom;
    ofParameter<float> gQSliderCrCcX;
    ofParameter<float> gQSliderCrCcY;
    ofParameter<float> gQSliderCrCcRadius;
    ofParameterGroup quadOptionsDeformParameters;
    ofParameter<bool> gQtoggleDeDeformOnOff;
    ofParameter<bool> gQtoggleDeBezier;
    ofParameter<bool> gQtoggleDeBezierReset;
    ofParameter<bool> gQtoggleDeSpherizeLight;
    ofParameter<bool> gQtoggleDeSpherizeStrong;
    ofParameter<bool> gQtoggleDeGrid;
    ofParameter<float> gQSliderDeGridRows;
    ofParameter<float> gQSliderDeGridColumns;
    ofParameter<bool> gQtoggleDeEdit;
    ofParameterGroup quadOptionsMaskParameters;
    ofParameter<bool> gQtoggleMaskOnOff;
    ofParameter<bool> gQtoggleMaskInvert;
    ofParameter<bool> gQtoggleMaskEdit;
    ofParameterGroup quadOptionsGreenscreenParameters;
    ofParameter<float> gQSliderGsThreshold;
    ofParameter<ofFloatColor> gQSliderGsColors;
    ofParameterGroup quadOptionsSurfaceParameters;
    ofParameter<bool> gQtoggleSuShowHide;
    ofParameter<bool> gQtoggleSuTimeline;
    ofParameter<float> gQSliderSuSeconds;
    ofParameter<bool> gQtoggleSuTlTint;
    ofParameter<bool> gQtoggleSuTlColor;
    ofParameter<bool> gQtoggleSuTlAlpha;
    ofParameter<bool> gQtoggleSuTl4Slides;
    ofParameterGroup quadOptionsEdgeBlendParameters;
    ofParameter<bool> gQtoggleEbOnOff;
    ofParameter<float> gQSliderEbPower;
    ofParameter<float> gQSliderEbGamma;
    ofParameter<float> gQSliderEbLuminance;
    ofParameter<float> gQSliderEbEdgesTop;
    ofParameter<float> gQSliderEbEdgesRight;
    ofParameter<float> gQSliderEbEdgesLeft;
    ofParameter<float> gQSliderEbEdgesBottom;
    ofParameterGroup quadOptionsBlendingModesParameters;
    ofParameter<bool> gQtoggleBmOnOff;
    ofParameterGroup quadOptionsGlobalQuadParameters;
    ofParameter<float> gQSliderGcX;
    ofParameter<float> gQSliderGcY;
    ofParameter<float> gQSliderGcWidth;
    ofParameter<float> gQSliderGcHeight;
    ofParameter<bool> gQtoggleGcReset;
    ofParameterGroup quadOptionsParameters;
    ofParameterGroup quadOptionsParametersSecond;
    ofParameterGroup quadOptionsParametersThird;
    ofParameter<bool> gQtoggSCOnOff;
    ofParameter<ofColor> gQcolorSC;
    ofParameter<bool> gQtoggTSOnOff;
    ofParameter<ofColor> gQcolorTS;
    ofParameter<float> gQfsliderTSduration;

};



