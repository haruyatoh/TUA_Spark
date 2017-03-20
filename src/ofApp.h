#pragma once

#include "ofMain.h"
#include "ofxOpticalFlowFarneback.h"

#define FARNE_USE_CAMERA

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage CoverImage;
    
    ofVideoGrabber videoSource;
    ofxOpticalFlowFarneback flowSolver;
    
    int camWidth;
    int camHeight;
    ofTexture tex;
    
    //波形
    void audioIn(float * input, int bufferSize, int nChannels);
    vector<float> left;
    ofSoundStream soundStream;
    
    int slide;
    int elapsedTime;
    int red,green,blue;
};
