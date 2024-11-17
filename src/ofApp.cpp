#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load("CHESTER_P_FREESTYLE.mp4"); //test video
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();
    
//    videoEcho.setup(0.3f, 0.9f, 10); //300 ms delay
//    motionBlur.setup(0.1f);
    
//    stepPrinting.setup(20); // Capture every 5th frame by default
    glitchEffect.setup(1500, 1, 0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
//    videoEcho.update(video);
    
//    if (video.isFrameNew()){
//        motionBlur.update(video);
//    }
    
//    if (video.isFrameNew()){
//        stepPrinting.update(video);
//    }
    
    if (video.isFrameNew()) {
          glitchEffect.update(video);  // Update the glitch effect
      }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    videoEcho.apply(video, 0,0, ofGetWidth(), ofGetHeight());
    
//    motionBlur.apply(video,0,0, ofGetWidth(), ofGetHeight());
//    
//    stepPrinting.apply(video, 0,0, ofGetWidth(), ofGetHeight());
    
    glitchEffect.apply(video, 0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

