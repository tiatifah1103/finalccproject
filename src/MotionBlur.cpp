//
//  MotionBlur.cpp
//  ccProject3
//
//  Created by Latifah Dickson on 16/11/2024.
//

#include "MotionBlur.hpp"

MotionBlur::MotionBlur(){
    blendFactor = 0.2f;
}

void MotionBlur::setup(float _blendFactor){
    blendFactor = _blendFactor;
    
    accumulationBuffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);;
    
    accumulationBuffer.begin();
    ofClear(0, 0, 0, 0);
    accumulationBuffer.end();
    
}

void MotionBlur::update(ofVideoPlayer &video){
    accumulationBuffer.begin();
    
    //translucent black rectangle to fade from previous frame
    
    ofSetColor(0, 0, 0, 255 * (1.0f - blendFactor));
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //draws current video frame on top with full opacity
    ofSetColor(255);
    video.draw(0,0, ofGetWidth(), ofGetHeight());
    
    accumulationBuffer.end();
}

void MotionBlur::apply(ofVideoPlayer &video, float x, float y, float width, float height){
    //draws blurred result from the accumulation buffer
    ofSetColor(255);
    accumulationBuffer.draw(x,y,width,height);
}

void MotionBlur::clear(){
    accumulationBuffer.begin();
    ofClear(0,0,0,0);
    accumulationBuffer.end();
}
