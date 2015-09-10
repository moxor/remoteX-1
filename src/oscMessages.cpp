#include "oscMessages.h"


void oscMessages::setActiveQuad(ofxOscMessage &m,int quad){
	m.setAddress("/active/set");
	m.addFloatArg(quad);

}

void oscMessages::setOscMessageInputs(ofAbstractParameter &e,ofxOscMessage &m, int quad){

     string adress="/surface/"+to_string(quad);
	string name=e.getName();
	cout << "got event from: "+e.getName() +" " +e.toString()<< endl;

     setParameters=true;
     sendOSC=true;
//Set the Adresses
     if(name.find("Video") != std::string::npos){
          setVideo(e,m,adress);
     }
     else if(name.find("Image") != std::string::npos){
          setImage(e,m,adress);
     }
     else if(name.find("Kinectinect") != std::string::npos){
          setKinect(e,m,adress);
     }
     else if(name.find("Cam") != std::string::npos||name.find("Sam") != std::string::npos||name.find("Buf") != std::string::npos){
          setCamera(e,m,adress);
     }
     else if(name.find("3d") != std::string::npos){
          set3d(e,m,adress);
     }
     else if(name.find("Slideshow") != std::string::npos||name.find("sh ") != std::string::npos){
          setSlideshow(e,m,adress);
     }
     if(setParameters)setTheParameters(e,m);
}
void oscMessages::setTheParameters(ofAbstractParameter &e,ofxOscMessage &m){
//set the Values
          if(e.type() == typeid(ofParameter<bool>).name()){
               m.addIntArg((int)e.cast<bool>().get());
          }
          else if(e.type() == typeid(ofParameter<float>).name()){
               m.addFloatArg(e.cast<float>().get());
          }
          else if(e.type() == typeid(ofParameter<ofVec2f>).name()){
               ofVec2f tmp=e.cast<ofVec2f>();         
               m.addFloatArg(tmp.x);
               m.addFloatArg(tmp.y);
          }
          else if(e.type() == typeid(ofParameter<ofVec3f>).name()){
           
               ofVec3f tmp=e.cast<ofVec3f>();         
               m.addFloatArg(tmp.x);
               m.addFloatArg(tmp.y);
               m.addFloatArg(tmp.z);
          }
          else if(e.type() == typeid(ofParameter<ofColor>).name()){
               ofColor tmp=e.cast<ofColor>();
               m.addFloatArg(tmp.r);
               m.addFloatArg(tmp.g);
               m.addFloatArg(tmp.b);
               m.addFloatArg(tmp.a);
          }
          else if(e.type() == typeid(ofParameter<ofFloatColor>).name()){
               ofColor tmp=e.cast<ofColor>();
               m.addFloatArg(tmp.r);
               m.addFloatArg(tmp.g);
               m.addFloatArg(tmp.b);
               m.addFloatArg(tmp.a);
          }
}
void oscMessages::setVideo(ofAbstractParameter &e,ofxOscMessage &m,string adress){
     string name=e.getName();
     if(name == "Video On/Off")m.setAddress(adress+"/video/show");     
     else if(name == "Load Video")m.setAddress("/active/video/load");
     else if(name == "Scale Video")m.setAddress(adress+"/video/mult/xy");  
     else if(name == "Fit Video to quad")m.setAddress(adress+"/video/fit");
     else if(name == "Keep Video aspect ratio")m.setAddress(adress+"/video/keepaspect");     
     else if(name == "Video Horizontal flip")m.setAddress(adress+"/video/hmirror");     
     else if(name == "Video Vertical flip")m.setAddress(adress+"/video/vmirror");
     else if(name == "Video color")m.setAddress(adress+"/video/color");
     else if(name == "Video Audio Volume")m.setAddress(adress+"/video/volume");
     else if(name == "Video Speed")m.setAddress(adress+"/video/speed");
     else if(name == "Video Loop")m.setAddress(adress+"/video/loop");
     else if(name == "Video Greenscreen")m.setAddress(adress+"/video/greenscreen");

}
void oscMessages::setImage(ofAbstractParameter &e,ofxOscMessage &m,string adress){
     string name=e.getName();
     //     //image

     if(name == "Image On/Off")m.setAddress(adress+"/img/show");     
     else if(name == "Load Image")m.setAddress("/active/img/load");     
     else if(name == "Fit image to quad")m.setAddress(adress+"/img/fit");     
     else if(name == "Keep image aspect ratio")m.setAddress(adress+"/img/keepaspect");
     else if(name == "Scale Image")m.setAddress(adress+"/img/mult/xy");  
     else if(name == "Image horizontal flip")m.setAddress(adress+"/img/hmirror");     
     else if(name == "Image vertical flip")m.setAddress(adress+"/img/vmirror");     
     else if(name == "Image Greenscreen")m.setAddress(adress+"/img/greenscreen");
     else if(name == "Image color")m.setAddress(adress+"/img/color");

}
void oscMessages::setKinect(ofAbstractParameter &e,ofxOscMessage &m,string adress){
     string name=e.getName();
     //Kinect------------------------------------------------------------------
     if(name == "Kinect On/Off")m.setAddress(adress+"/kinect/show");
     else if(name == "Kinect close/open")m.setAddress(adress+"/kinect/close");     
     else if(name == "Kinect show image")m.setAddress(adress+"/kinect/show/image");     
     else if(name == "Kinect grayscale")m.setAddress(adress+"/kinect/show/grayscale");     
     else if(name == "Kinect mask")m.setAddress(adress+"/kinect/mask");     
     else if(name == "Kinect detect")m.setAddress(adress+"/kinect/contour");     
     else if(name == "Scale Kinect")m.setAddress(adress+"/kinect/mult/xy");     
     else if(name == "Kinect threshold near")m.setAddress(adress+"/kinect/threshold/near");
     else if(name == "Kinect threshold far")m.setAddress(adress+"/kinect/threshold/far");
     else if(name == "Kinect angle")m.setAddress(adress+"/kinect/angle");
     else if(name == "Kinect blur")m.setAddress(adress+"/kinect/blur");     
     else if(name == "Kinect smooth")m.setAddress(adress+"/kinect/contour/smooth");
     else if(name == "Kinect simplify")m.setAddress(adress+"/kinect/contour/simplelse ify");
     else if(name == "Kinect min blob")m.setAddress(adress+"/kinect/contour/area/min");
     else if(name == "Kinect max blob")m.setAddress(adress+"/kinect/contour/area/max");
     else if(name == "Kinect color")m.setAddress(adress+"/kinect/color");
}
void oscMessages::setCamera(ofAbstractParameter &e,ofxOscMessage &m,string adress){
     string name=e.getName();
     //--camera----------------------------------------------------------

     if(name == "Camera On/Off")m.setAddress(adress+"/cam/show");
     else if(name == "Scale Camera")m.setAddress(adress+"/cam/mult/xy");     
     else if(name == "Fit Camera to quad")m.setAddress(adress+"/cam/fit");     
     else if(name == "Keep Camera aspect ratio")m.setAddress(adress+"/cam/keepaspect");     
     else if(name == "Camera horizontal flip")m.setAddress(adress+"/cam/hmirror");     
     else if(name == "Camera vertical flip")m.setAddress(adress+"/cam/vmirror");     
     else if(name == "Camera color")m.setAddress(adress+"/cam/color");
     else if(name == "Camera Volume")m.setAddress(adress+"/cam/volume");
     else if(name == "Camera Greenscreen")m.setAddress(adress+"/cam/greenscreen");

     else if (name.size()==4&&name.find("Cam")!= std::string::npos){
          if (e.cast<bool>()){
               setParameters=false;
               m.setAddress(adress+"/cam/num");
               if(name.find("0")!= std::string::npos)m.addIntArg(0);
               else if(name.find("1")!= std::string::npos)m.addIntArg(1);
               else if(name.find("2")!= std::string::npos)m.addIntArg(2);
               else if(name.find("3")!= std::string::npos)m.addIntArg(3);
          }
          else sendOSC=false;
     }
}
void oscMessages::set3d(ofAbstractParameter &e,ofxOscMessage &m,string adress){
     string name=e.getName();
     //     //3d model
     if(name == "Load 3d")m.setAddress("/active/3d/load");     
     else if(name == "3d Scale")m.setAddress(adress+"/3d/scale/xyz");
     else if(name == "3d Rotate")m.setAddress(adress+"/3d/rotate/xyz");
     else if(name == "3d Move")m.setAddress(adress+"/3d/move/xyz");
     else if(name == "animation")m.setAddress(adress+"/3d/animation");
     else if(name == "3d smooth"&&e.cast<bool>())
     {
     setParameters=false;
     m.setAddress(adress+"/3d/texture/mode");
     m.addIntArg(0);
     m.addIntArg(1);
     }
     else if(name == "3d wire"&&e.cast<bool>())
     {
     setParameters=false;
     m.setAddress(adress+"/3d/texture/mode");
     m.addIntArg(1);
     m.addIntArg(1);
     }
     else if(name == "3d dots"&&e.cast<bool>())
     {
     setParameters=false;
     m.setAddress(adress+"/3d/texture/mode");
     m.addIntArg(2);
     m.addIntArg(1);
     }
     else sendOSC=false;
}
void oscMessages::setSlideshow(ofAbstractParameter &e,ofxOscMessage &m,string adress){
     string name=e.getName();
     if(name == "Slideshow On/Off")m.setAddress(adress+"/slideshow/show");
     else if(name == "Load Slideshow")m.setAddress("/active/slideshow/folder");     
     else if(name == "Fit Slideshow to quad")m.setAddress(adress+"/slideshow/fit");     
     else if(name == "Kinecteep Slideshow aspect ratio")m.setAddress(adress+"/slideshow/keep_aspect");     
     else if(name == "sh Greenscreen")m.setAddress(adress+"/slideshow/greenscreen");     
     else if(name == "sh ts duration")m.setAddress(adress+"/slideshow/duration");
}
void oscMessages::setOscMessageQuadOptions(ofAbstractParameter &e,ofxOscMessage &m, int quad){
     string adress="/surface/"+to_string(quad);
     string name=e.getName();
     cout << "got event from: "+e.getName() +" " +e.toString()<< endl;

     setParameters=true;
     sendOSC=true;

//QuadOptions
     //GreenScreen
     if(name == "gs threshold")m.setAddress(adress+"/greenscreen/threshold");
     else if(name == "gs color")m.setAddress(adress+"/greenscreen/color");
     //timeline
     else if(name == "use Timeline")m.setAddress("/projection/timeline/toggle");
     else if(name == "Timeline seconds")m.setAddress("/projection/timeline/duration");
     else if(name == "tl tint")m.setAddress(adress+"/timeline/tint");
     else if(name == "tl color")m.setAddress(adress+"/timeline/color");
     else if(name == "tl alpha")m.setAddress(adress+"/timeline/alpha");
     else if(name == "tl 4 slides")m.setAddress(adress+"/timeline/slides");


//edge blend

     else if(name == "Edge Blend On/Off")m.setAddress(adress+"/edgeblend/show");
     else if(name == "eb ower")m.setAddress(adress+"/edgeblend/power");
     else if(name == "eb gamma")m.setAddress(adress+"/edgeblend/gamma");
     else if(name == "eb luminance")m.setAddress(adress+"/edgeblend/luminance");
     else if(name == "eb left")m.setAddress(adress+"/edgeblend/amount/left");
     else if(name == "eb right")m.setAddress(adress+"/edgeblend/amount/right");
     else if(name == "eb top")m.setAddress(adress+"/edgeblend/amount/top");
     else if(name == "eb bottom")m.setAddress(adress+"/edgeblend/amount/bottom");

//blend modes

      else if(name == "Blending Modes On/Off")m.setAddress(adress+"/blendmodes/show");
      else if(name == "screen"){
          setParameters=false;
          m.setAddress(adress+"/blendmodes/mode");
          m.addIntArg(0);
          m.addIntArg(1);
     }
    else if(name == "add"){
          setParameters=false;
          m.setAddress(adress+"/blendmodes/mode");
          m.addIntArg(0);
          m.addIntArg(1);
     }
     else if(name == "subtract"){
          setParameters=false;
          m.setAddress(adress+"/blendmodes/mode");
          m.addIntArg(0);
          m.addIntArg(1);
     }
     else if(name == "multiply"){
          setParameters=false;
          m.setAddress(adress+"/blendmodes/mode");
          m.addIntArg(0);
          m.addIntArg(1);
     }
//solid color
     else if(name == "Solid colors onOff")m.setAddress(adress+"/solid/show");
     else if(name == "Solid Colors")m.setAddress(adress+"/solid/color");


// /*    else if(name == "modesetup on/off")m.setAddress("/projection/mode/setup/toggle");
// */
//mask

     else if(name == "m on/off")m.setAddress(adress+"/mask/show");
     else if(name == "m invert")m.setAddress(adress+"/mask/invert");
     else if(name == "mask edit on/off")m.setAddress("/projection/mode/masksetup/toggle");
//Deform
     else if(name == "Deform On/Off")m.setAddress(adress+"/deform/show");
     else if(name == "bezier On/Off")m.setAddress(adress+"/deform/bezier");
     else if(name == "bezier Reset")m.setAddress(adress+"/deform/bezier/reset");
     else if(name == "spherize light")m.setAddress(adress+"/deform/bezier/spherize/light");
     else if(name == "spherize strong")m.setAddress(adress+"/deform/bezier/spherize/strong");
     else if(name == "Grid")m.setAddress(adress+"/deform/grid");
     else if(name == "Grid rows")m.setAddress(adress+"/deform/grid/rows");
     else if(name == "Grid columns num")m.setAddress(adress+"/deform/grid/columns");
     else if(name == "edit")m.setAddress(adress+"/deform/edit");
//crop
     else if(name == "rc top")m.setAddress(adress+"/crop/rectangular/top");
     else if(name == "rc right")m.setAddress(adress+"/crop/rectangular/right");
     else if(name == "rc left")m.setAddress(adress+"/crop/rectangular/left");
     else if(name == "rc bottom")m.setAddress(adress+"/crop/rectangular/bottom");
     else if(name == "cc x")m.setAddress(adress+"/crop/circular/x");
     else if(name == "cc y")m.setAddress(adress+"/crop/circular/y");
     else if(name == "cc radius")m.setAddress(adress+"/crop/circular/radius");
//transition
     else if(name == "Trans colors onOff")m.setAddress(adress+"/solid/trans/show");
     else if(name == "Transition Colors")m.setAddress(adress+"/solid/trans/color");
     else if(name == "ts duration")m.setAddress(adress+"/solid/trans/duration");

     if(setParameters)setTheParameters(e,m);
}
void oscMessages::setOscMessage(ofAbstractParameter &e,ofxOscMessage &m, int quad){
     string adress="";
     string name=e.getName();
     cout << "got event from: "+e.getName() +" " +e.toString()<< endl;

     setParameters=true;
     sendOSC=true;

     if(setParameters)setTheParameters(e,m);
     //GLobalplacement
     if (name == "move x")m.setAddress(adress+"/placement/x");
     else if(name == "move y")m.setAddress(adress+"/placement/y");
     else if(name == "width")m.setAddress(adress+"/placement/w");
     else if(name == "height")m.setAddress(adress+"/placement/h");
     else if(name == "reset")m.setAddress(adress+"/placement/reset");
//Projection
   else if(name == "live resync")m.setAddress("/projection/resync");
   else if(name == "live On/Off")m.setAddress("/projection/stop");
   else if(name == "fullscreen on/off")m.setAddress("/projection/fullscreen/toggle");
   else if(name == "Gui On/Off")m.setAddress("/projection/gui/toggle");
   else if(name == "Direct save")m.setAddress("/projection/save");
   else if(name == "Direct load")m.setAddress("/projection/load");
   else if(name == "Load file")m.setAddress("/projection/loadfile");
   else if(name == "Save file")m.setAddress("/projection/savefile");
     //sampler
     else if(name == "Sampler OnOff")m.setAddress(adress+"/sampler/show");
     else if(name == "s c0"){
          m.setAddress(adress+"/sampler/num");
          m.addIntArg(0);
          setParameters=false;
     }
     else if(name == "s c1"){
          m.setAddress(adress+"/sampler/num");
          m.addIntArg(1);
          setParameters=false;
     }
     else if(name == "s c2"){
          m.setAddress(adress+"/sampler/num");
          m.addIntArg(2);
          setParameters=false;
     }
     else if(name == "s c3"){
          m.setAddress(adress+"/sampler/num");
          m.addIntArg(3);
          setParameters=false;
     }
     else if(name == "s b0"){
          m.setAddress(adress+"/sampler/buffernum");
          m.addIntArg(0);
          setParameters=false;
     }
     else if(name == "s b1"){
          m.setAddress(adress+"/sampler/buffernum");
          m.addIntArg(1);
          setParameters=false;
     }
     else if(name == "s b2"){
          m.setAddress(adress+"/sampler/buffernum");
          m.addIntArg(2);
          setParameters=false;
     }
     else if(name == "s b3"){
          m.setAddress(adress+"/sampler/buffernum");
          m.addIntArg(3);
          setParameters=false;
     }

//     else if(name == "Record")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/record/"+ofToString(SharedSamplerBufferIndex));
//     else if(name == "PlayAny")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/play");
//     else if(name == "Pause")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/pause");
//     else if(name == "Clear Buffer")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/clear");
//     else if(name == "Play 0")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/playbuffer/0");
//     else if(name == "Play 1")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/playbuffer/1");
//     else if(name == "Play 2")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/playbuffer/2");
//     else if(name == "Play 3")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/playbuffer/3");
//     else if(name == "s sampnum")
//     else if(name == "b recnum")m.setAddress("/sharedsampler/"+ofToString(SharedSamplerIndex)+"/record/"+ofToString(SharedSamplerBufferIndex));
}