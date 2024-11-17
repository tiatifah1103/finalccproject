//
//  MotionBlur.hpp
//  ccProject3
//
//  Created by Latifah Dickson on 16/11/2024.
//

#pragma once
#include "ofMain.h"


class MotionBlur {
public:
    
    MotionBlur();
    
    void setup(float _blendFactor);
    void update(ofVideoPlayer &video);
    void apply(ofVideoPlayer &video, float x, float y, float width, float height);
    void clear();
    
private:
    ofFbo accumulationBuffer; // Frame buffer for storing accumulated frames
    float blendFactor;  // Controls the smoothness of the blur
};
