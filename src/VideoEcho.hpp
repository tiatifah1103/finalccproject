//
//  VideoEcho.hpp
//  ccProject3
//
//  Created by Latifah Dickson on 15/11/2024.
//

#pragma once
#include "ofMain.h"

class VideoEcho {
public:
    VideoEcho();
    void setup (float delayTime, float fadeFactor, int maxFrames);
    void update(ofVideoPlayer& video);
    void apply(ofVideoPlayer& video, float x, float y, float width, float height);
    void clearFrames();
    
private:
    float delayTime; //time delat between echoes in secs
    float fadeFactor; //echo fades with each frame
    vector<ofPixels> previousFrames; //stores prev frames for echo effect
    int maxFrames; // mac num of frames for echo
};
