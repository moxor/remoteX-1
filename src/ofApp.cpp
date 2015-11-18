#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    //ofSetLogLevel(OF_LOG_VERBOSE);

    ofSetFrameRate(35);
    sender.setup(HOST, PORT);
    //Colors
    ofBackground(0xad,0x46,0x01,100);
    ofxGuiSetFillColor(ofColor(0xff,0x4f,0x20,100));
    ofxGuiSetBackgroundColor(ofColor(0xff,0xa5,0x8d,100));
    ofxGuiSetTextColor(ofColor(0xff,0xff,0xff,255));
    ofxGuiSetHeaderColor(ofColor(0x64,0x54,0x44));
    ofxGuiSetBorderColor(ofColor(0x30,0x5b,0x74));
    bgImage.load("image/bg.png");
    //ofEnableSmoothing();
    ofSetCircleResolution(60);



    video_color_r = 10; video_color_g = 10; video_color_b = 10; video_color_a = 10;

    //setupPreviewVideo();
    setupInputPages();
    setupQuadOptionsPages();
    setupQuadSelectionPages();
    //Options----------------------------------------------
    optionGroup.setup();
    optionParametersClass.add(optionGroup.optionParameters);
    optionParametersClass.add(optionGroup.optionProjectParameters);
    guiOptionPanel.setup(optionParametersClass,"",900,100);
    guiOptionPanel.setName("Options");
    ofAddListener(optionParametersClass.parameterChangedE(),this,&ofApp::guiEvent);


    //Sampler --------------------------------------------------------
    samplerGroup.setup();
    samplerParametersClass.add(samplerGroup.samplerParameters);
    samplerParametersClassSecond.add(samplerGroup.bufferParameters);
    guiSamplerPanel.setup(samplerParametersClass,"",0,0);
    guiSamplerPanel2.setup(samplerParametersClassSecond,"", 220,0);
    //cam
    matrixSamCam.setup("cam to record from",4);
    vector<ofParameter<bool>> matrix_sCam;
    matrix_sCam.push_back(ofParameter<bool>("s c0",false));
    matrix_sCam.push_back(ofParameter<bool>("s c1",false));
    matrix_sCam.push_back(ofParameter<bool>("s c2",false));
    matrix_sCam.push_back(ofParameter<bool>("s c3",false));
    for(unsigned int i = 0; i < matrix_sCam.size(); i++) {
        matrixSamCam.add(new ofxMinimalToggle(matrix_sCam.at(i)));
    }
    matrixSamCam.setElementHeight(26);
    matrixSamCam.allowMultipleActiveToggles(false);
    guiSamplerPanel.add(&matrixSamCam);

    //buffer
       // //sampler buffer
     vector<ofParameter<bool>> matrix_bufferSam;
     matrix_bufferSam.push_back(ofParameter<bool>("s b0",false));
     matrix_bufferSam.push_back(ofParameter<bool>("s b1",false));
     matrix_bufferSam.push_back(ofParameter<bool>("s b2",false));
     matrix_bufferSam.push_back(ofParameter<bool>("s b3",false));
     matrixBufferSam.setup("Buf Slot for recording",4);
     for(unsigned int i = 0; i < matrix_bufferSam.size(); i++) {
         matrixBufferSam.add(new ofxMinimalToggle(matrix_bufferSam.at(i)));
     }

    matrixBufferSam.setElementHeight(26);
    matrixBufferSam.allowMultipleActiveToggles(false);
    guiSamplerPanel2.add(&matrixBufferSam);
    samplerPage.setup("sampler", "", 445,445);
    samplerPage.setSize(440,200);
    samplerPage.add(&guiSamplerPanel);
    samplerPage.add(&guiSamplerPanel2);
    ofAddListener(samplerParametersClass.parameterChangedE(),this,&ofApp::guiEvent);
    ofAddListener(samplerParametersClassSecond.parameterChangedE(),this,&ofApp::guiEvent);

}

void ofApp::setupPreviewVideo(){
    camWidth = 320;  // try to grab at this size.
    camHeight = 240;

    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(unsigned int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    vidGrabber.setDeviceID(4);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.setVerbose(false);
    //vidGrabber.setPixelFormat(parseDesiredPixelFormat("RGB"));
    vidGrabber.initGrabber(camWidth, camHeight);
}
void ofApp::setupQuadSelectionPages(){
     //QuadSelection----------------------------------------

    //guiQuadSelectionPanel.setup("Quad Selection");
    guiQuadSelectionPanel.setAlignHorizontal();
    guiQuadSelectionPanel.setShowHeader(false);
    guiQuadSelectionPanelSecond.setAlignHorizontal();
    guiQuadSelectionPanelSecond.setup("","",0,25);
    guiQuadSelectionPanelSecond.setShowHeader(false);

    vector<ofParameter<bool>> quads;
    for(int i=0;i<73;i++){
        quads.push_back(ofParameter<bool>(to_string(i),false));
    }
    for(unsigned int i = 0; i < 36; i++) {

        guiQuadSelectionPanel.add(new ofxMinimalToggle(quads.at(i),24, 24));
        quadSelectionParametersClass.add(quads.at(i));
        //guiQuadSelectionPanel.add(new ofxToggle(quads.at(i).set(to_string(i),false),20, 20));
    }
    for(unsigned int i = 36; i < quads.size()-1; i++) {
        //guiQuadSelectionPanelSecond.add(new ofxToggle(quads.at(i).set(to_string(i),false),20, 20));
        guiQuadSelectionPanelSecond.add(new ofxMinimalToggle(quads.at(i),24, 24));
        quadSelectionParametersClass.add(quads.at(i));
    }
    guiQuadSelectionPanelSecond.add(new ofxMinimalToggle(quads.at(72).set("add quad",false),90, 24));
    quadSelectionParametersClass.add(quads.at(72));

    //Groups
    guiQuadSelectionPanelGroup.setup("Groups","",770,00);
    guiQuadSelectionPanelGroup.setAlignHorizontal();
    guiQuadSelectionPanelGroup.setShowHeader(false);
    vector<ofParameter<bool>> quadsGroups;
    for(int i=0;i<9;i++){
        quadsGroups.push_back(ofParameter<bool>("group"+to_string(i),false));
    }
    for(unsigned int i = 36; i < quadsGroups.size(); i++) {
        guiQuadSelectionPanelGroup.add(new ofxMinimalToggle(quadsGroups.at(i).set("group"+to_string(i),false),20, 60));
    }
    for(unsigned int i = 0; i < quadsGroups.size(); i++) {
        quadSelectionGroupParametersClass.add(quadsGroups.at(i));
    }
    quadSelectionPage.setup("Quad Selection");
    quadSelectionPage.add(&guiQuadSelectionPanel);
    quadSelectionPage.add(&guiQuadSelectionPanelSecond);
    quadSelectionPage.add(&guiQuadSelectionPanelGroup);
    quadSelectionPage.setDefaultBackgroundColor(ofColor(0xff,0xa5,0x8d,100));
    quadSelectionPage.setDefaultFillColor(ofColor(0xff,0xa5,0x8d,100));
    quadSelectionPage.setSize(1090,90);
    activeQuad=3;
    ofAddListener(quadSelectionParametersClass.parameterChangedE(),this,&ofApp::guiEventQuad);
    ofAddListener(quadSelectionGroupParametersClass.parameterChangedE(),this,&ofApp::guiEventQuad);


}
void ofApp::setupQuadOptionsPages(){
    //QuadOptions-------------------------------------------
    quadOptionsGroup.setup();
    //Transform
    quadOptionsParametersClass.add(quadOptionsGroup.quadOptionsParameters);
    guiQuadOptionsPanel.setup(quadOptionsParametersClass);
    guiQuadOptionsPanel.setName("Quad Transform");
    //Effects
    quadOptionsParametersClassSecond.add(quadOptionsGroup.quadOptionsParametersSecond);
    guiQuadOptionsPanel2.setup(quadOptionsParametersClassSecond);
    guiQuadOptionsPanel2.setName("Effects");
    matrixBlendingModes.setup("Mode Selection",4);
    vector<ofParameter<bool>> matrix_bm;
    matrix_bm.push_back(ofParameter<bool>("screen",false));
    matrix_bm.push_back(ofParameter<bool>("add",false));
    matrix_bm.push_back(ofParameter<bool>("sub",false));
    matrix_bm.push_back(ofParameter<bool>("mult",false));
    for(unsigned int i = 0; i < matrix_bm.size(); i++) {
        matrixBlendingModes.add(new ofxMinimalToggle(matrix_bm.at(i)));
    }
    matrixBlendingModes.setElementHeight(26);
    matrixBlendingModes.allowMultipleActiveToggles(false);
    guiQuadOptionsPanel2.add(&matrixBlendingModes);
    //Effects 2
    quadOptionsParametersClassScTs.add(quadOptionsGroup.quadOptionsParametersThird);
    guiQuadOptionsPanelScTs.setup(quadOptionsParametersClassScTs);
    guiQuadOptionsPanelScTs.setName("Effects");
    //Global
    quadOptionsParametersClassGlobalQuad.add(quadOptionsGroup.quadOptionsGlobalQuadParameters);
    guiQuadOptionsPanelGlobalQuad.setup(quadOptionsParametersClassGlobalQuad);
    //Pages
    quadOptionsTransformPage.setup("Trans");
    quadOptionsTransformPage.add(&guiQuadOptionsPanel);
    quadOptionsEffectsPage.setup("Effcts");
    quadOptionsEffectsPage.add(&guiQuadOptionsPanel2);
    quadOptionsEffectsPage2.setup("Effcts2");
    quadOptionsEffectsPage2.add(&guiQuadOptionsPanelScTs);
    quadOptionsGlobalQuadPage.setup("Global");
    quadOptionsGlobalQuadPage.add(&guiQuadOptionsPanelGlobalQuad);
    //tabbedPage
    quadOptionsPages.setup("Quad Effects/Transform","",1100,10);

    quadOptionsPages.add(&quadOptionsTransformPage);
    quadOptionsPages.add(&quadOptionsEffectsPage);
    quadOptionsPages.add(&quadOptionsEffectsPage2);
    quadOptionsPages.add(&quadOptionsGlobalQuadPage);
    quadOptionsPages.setSize(240, 660);
    quadOptionsPages.setDefaultBackgroundColor(ofColor(0xff,0xa5,0x8d,100));

    //EventListeners
    ofAddListener(quadOptionsParametersClass.parameterChangedE(),this,&ofApp::guiEventQuadOptions);
    ofAddListener(quadOptionsParametersClassScTs.parameterChangedE(),this,&ofApp::guiEventQuadOptions);
    ofAddListener(quadOptionsParametersClassSecond.parameterChangedE(),this,&ofApp::guiEventQuadOptions);
    ofAddListener(quadOptionsParametersClassGlobalQuad.parameterChangedE(),this,&ofApp::guiEventQuadOptions);

}
void ofApp::setupInputPages(){
    ///the setups

    videoGroup.setup();
    imageGroup.setup();
    kinectGroup.setup();
    cameraGroup.setup();
    Group3d.setup();
    slideshowGroup.setup();

    //video
    videoParametersClass.add(videoGroup.videoParameters);
    guiVideoPanel.setup(videoParametersClass);
    guiVideoPanel.setName("Video Input");
    videoPage.setup("Video");
    videoPage.add(&guiVideoPanel);
    //image
    imageParametersClass.add(imageGroup.imageParameters);
    guiImagePanel.setup(imageParametersClass);
    guiImagePanel.setName("Image Input");
    imagePage.setup("Image");
    imagePage.add(&guiImagePanel);
    //kinect
    kinectParametersClass.add(kinectGroup.kinectParameters);
    kinectParametersSecondClass.add(kinectGroup.kinectParametersSecond);
    guiKinectPanel.setup(kinectParametersClass);
    guiKinectPanel.setName("Kinect Input");
    guiKinectPanel2.setup(kinectParametersSecondClass,"", 220);
    guiKinectPanel2.setName("Kinect More");
    kinectPage.setup("Kinect");
    kinectPage.add(&guiKinectPanel);
    kinectPage.add(&guiKinectPanel2);
    //Camera
    cameraParametersClass.add(cameraGroup.cameraParameters);
    cameraParametersSecondClass.add(cameraGroup.cameraParametersSecond);
    guiCameraPanel.setup(cameraParametersClass);
    guiCameraPanel.setName("Camera Input");
    //Matrix Cameras

    matrixCam.setup("Cam Selection",4);
    vector<ofParameter<bool>> matrix_cams;
    matrix_cams.push_back(ofParameter<bool>("Cam0",false));
    matrix_cams.push_back(ofParameter<bool>("Cam1",false));
    matrix_cams.push_back(ofParameter<bool>("Cam2",false));
    matrix_cams.push_back(ofParameter<bool>("Cam3",false));
    for(unsigned int i = 0; i < matrix_cams.size(); i++) {
        matrixCam.add(new ofxMinimalToggle(matrix_cams.at(i)));
    }

    matrixCam.setElementHeight(26);
    matrixCam.allowMultipleActiveToggles(false);
    guiCameraPanel.add(&matrixCam);
    //cameraPage
    cameraPage.setup("Camera/v4l2/syphon");
    cameraPage.add(&guiCameraPanel);
    //cameraPage.add(&guiCameraPanel2);
    //3d
    Parameters3dClass.add(Group3d.Parameters3d);
    vector<ofParameter<bool>> matrix_renderModes;
    matrix_renderModes.push_back(ofParameter<bool>("3d smooth",false));
    matrix_renderModes.push_back(ofParameter<bool>("3d wire",false));
    matrix_renderModes.push_back(ofParameter<bool>("3d dots",false));
    matrix3dRenderModes.setup("3d animation type",3);
    for(unsigned int i = 0; i < matrix_renderModes.size(); i++) {
        matrix3dRenderModes.add(new ofxMinimalToggle(matrix_renderModes.at(i)));
    }
    matrix3dRenderModes.setElementHeight(26);
    matrix3dRenderModes.allowMultipleActiveToggles(false);
    gui3dPanel.setup(Parameters3dClass);
    gui3dPanel.setName("3d Input");
    gui3dPanel.add(&matrix3dRenderModes);
    Page3d.setup("3d");
    Page3d.add(&gui3dPanel);
    //Slideshow
    slideshowParametersClass.add(slideshowGroup.slideshowParameters);
    guiSlideshowPanel.setup(slideshowParametersClass);
    guiSlideshowPanel.setName("Slideshow Input");
    slideshowPage.setup("Slideshow");
    slideshowPage.add(&guiSlideshowPanel);

    //input pages
    inputPages.setup("Inputs", "",10,100);
    inputPages.setSize(440, 500);
    inputPages.add(&videoPage);
    inputPages.add(&imagePage);
    inputPages.add(&kinectPage);
    inputPages.add(&cameraPage);
    inputPages.add(&Page3d);
    inputPages.add(&slideshowPage);

    // Input listeners
    ofAddListener(videoParametersClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(imageParametersClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(kinectParametersClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(kinectParametersSecondClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(cameraParametersClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(cameraParametersSecondClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(Parameters3dClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(slideshowParametersClass.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(slideshowParametersClassSC.parameterChangedE(),this,&ofApp::guiEventInputs);
    ofAddListener(slideshowParametersClassTS.parameterChangedE(),this,&ofApp::guiEventInputs);
}
//--------------------------------------------------------------
void ofApp::update()
{
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    bgImage.draw(400,200);
    quadSelectionPage.draw();
    inputPages.draw();
    guiOptionPanel.draw();
    quadOptionsPages.draw();
    //vidGrabber.draw(460,100);
    samplerPage.draw();

}
void ofApp::guiEventQuadOptions(ofAbstractParameter &e){
        for(unsigned int i=0;i<quadSelectionParametersClass.size();i++){

            if(quadSelectionParametersClass.getBool(i)){
                ofxOscMessage q;
                msg.setOscMessageQuadOptions(e,q,i);
                if(msg.sendOSC){sender.sendMessage(q);
                cout << q.getAddress() +" " +q.getArgAsString(0)<< endl;}
        }
    }
}
void ofApp::guiEvent(ofAbstractParameter &e){
        for(unsigned int i=0;i<quadSelectionParametersClass.size();i++){

            if(quadSelectionParametersClass.getBool(i)){
                ofxOscMessage q;
                msg.setOscMessage(e,q,i);
                if(msg.sendOSC){sender.sendMessage(q);
                cout << q.getAddress() +" " +q.getArgAsString(0)<< endl;}
        }
    }
}
void ofApp::guiEventInputs(ofAbstractParameter &e){
    cout<<e.getName()<<endl;
    if (quadSelectionParametersClass.size()==1){
        for(unsigned int i=0;i<quadSelectionParametersClass.size();i++){
            if(quadSelectionParametersClass.getBool(i)){
                activeQuad=i;
                ofxOscMessage m;
                msg.setActiveQuad(m,activeQuad);
                sender.sendMessage(m);
            }
        }
    }
    for(unsigned int i=0;i<quadSelectionParametersClass.size();i++){
        if (e.getName().find("Load") != string::npos&&i==activeQuad){
            if (e.cast<bool>()){
                ofxOscMessage m;
                msg.setOscMessageInputs(e,m,activeQuad);
                sender.sendMessage(m);
                cout << m.getAddress() +" "+to_string(m.getArgAsInt(0))<< endl;
            }
        }
        if (e.getName().find("Load") != string::npos&& !e.cast<bool>()){}
        else if(quadSelectionParametersClass.getBool(i)&&e.getName().find("Load") == string::npos){
            ofxOscMessage q;
            msg.setOscMessageInputs(e,q,i);
            if(msg.sendOSC){sender.sendMessage(q);
            cout << q.getAddress() +" "+to_string(q.getArgAsInt(0))<< endl;}
        }
    }


}
void ofApp::guiEventQuad(ofAbstractParameter &e){
<<<<<<< HEAD
    if (quadSelectionParametersClass.size()==1){
        for(unsigned int i=0;i<quadSelectionParametersClass.size();i++){
            if(quadSelectionParametersClass.getBool(i)){
                activeQuad=i;
                ofxOscMessage m;
                msg.setActiveQuad(m,activeQuad);
                sender.sendMessage(m);
            }
        }
    }
    if (e.getName()=="add quad"){
        ofxOscMessage m;
        m.setAddress("/surface/add");
        m.addIntArg(0);
        sender.sendMessage(m);
        cout << m.getAddress() +" " +to_string(m.getArgAsFloat(0))<< endl;
    }
    else if(e.cast<bool>()){  
=======
    if(e.cast<bool>()){
>>>>>>> upstream/master
        activeQuad=atoi(e.getName().c_str());
        ofxOscMessage m;
        msg.setActiveQuad(m,activeQuad);
        sender.sendMessage(m);
        cout << m.getAddress() +" " +to_string(m.getArgAsFloat(0))<< endl;
    }

}
void ofApp::exit()
{
//    delete gui0;
//    delete gui1;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case 'b':
        {
        ofxOscMessage m;
        m.setAddress("/active/deform/edit");
        sender.sendMessage(m);
        }
        break;
    default:
        break;
    }
/*     // toggles fullscreen mode
    if(key == 'f')

        bFullscreen = !bFullscreen;

        if(!bFullscreen)
        {
            ofSetFullscreen(false);
        }
        else if(bFullscreen == 1)
        {
            ofSetFullscreen(true);
        }
*/
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{


}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
