//
//  MotionBlur.hpp
//  ccProject3
//
//  Created by Latifah Dickson on 16/11/2024.
//

#pragma once

#include "ofMain.h"
#include "ofVideoPlayer.h"

class MotionBlur {
public:
    MotionBlur();  // Constructor to initialize the effect
    
    void setup(float _blendFactor, float _stretchAmount);
    void update(ofVideoPlayer &video);
    void apply(ofVideoPlayer &video, float x, float y, float width, float height);
    float colorDistance(const ofColor &color1, const ofColor &color2);
    void clear();
    
private:
    float blendFactor;
    float stretchAmount; 
    ofPixels previousFramePixels;
    ofFbo accumulationBuffer;
};
