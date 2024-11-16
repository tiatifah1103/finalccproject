#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load("CHESTER_P_FREESTYLE.mp4"); //test video
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();
    
    videoEcho.setup(0.3f, 0.9f, 10); //300 ms delay
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    videoEcho.update(video);
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoEcho.apply(video, 0,0, ofGetWidth(), ofGetHeight());
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

