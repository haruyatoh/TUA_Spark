#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    
    CoverImage.load("spring2017_desktop_color.png");
    
    camWidth = 1280;
    camHeight = 720;
    
    //videoSource.setDesiredFrameRate(30);
    videoSource.initGrabber(camWidth, camHeight);
    
    flowSolver.setup(videoSource.getWidth(), videoSource.getHeight(), 0.35, 5, 10, 1, 3, 2.25, false, false);
    
    ofEnableAlphaBlending();
    //ofSetBackgroundAuto(true);
    ofBackground(0);
    //ofSetWindowShape(videoSource.getWidth(), videoSource.getHeight());
    
    //波形
    elapsedTime = 0;
    int bufferSize =256;
    left.assign(bufferSize, 0.0);
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void testApp::update() {
    videoSource.update();
    if(videoSource.isFrameNew()) {
        flowSolver.update(videoSource);
    }
    
    //波形
    elapsedTime++;
    
    cout << elapsedTime << endl;
    
}

//--------------------------------------------------------------
void testApp::draw() {
    
    ofSetColor(255);
    ofFill();
    
    //画像キャプチャー
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);
    videoSource.draw(-camWidth/2, -camHeight/2);
    ofPopMatrix();
    
    //虹
    flowSolver.drawColored(ofGetWidth(), ofGetHeight(), 10, 3);
    
    //波形
    ofSetColor(ofColor::fromHsb(ofGetFrameNum()%255, 180, 255, 255));
    ofSetLineWidth(10);
    ofNoFill();
    slide++;
    if(slide==130)slide=0;
    ofBeginShape();
    for(unsigned int i = 0; i< left.size(); i++){
        ofVertex(i*10, 700 -left[i+slide]*4000.0f);
    }
    ofEndShape(false);
    
    //壁紙
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255, 255, 255, 102);
    CoverImage.draw(-camWidth/2, -camHeight/2, camWidth, camHeight);
    ofPopMatrix();
}

void testApp::audioIn(float * input, int bufferSize, int nChannels){

    if(elapsedTime%2==0){
        for (int i = 0; i < bufferSize; i++){
            left[i]       = input[i*2]*0.5;
        }
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {
    
}
