//
//  GlitchEffect.hpp
//  ccProject3
//
//  Created by Latifah Dickson on 17/11/2024.
//

#pragma once
#include "ofMain.h"

class GlitchEffect{
public:
    
    GlitchEffect();
    void setup (int _glitchInterval, float _glitchStrength, float _glitchProbability);
    void update(ofVideoPlayer &video);
    void apply(ofVideoPlayer &video, float x, float y, float width, float height);
    void applyGlitch(ofVideoPlayer &video, float x, float y, float width, float height);
    

private:
    
    int glitchInterval;
    int frameCounter;
    int glitchStrength;
    float glitchProbability = 0.1f;
};
