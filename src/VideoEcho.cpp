//
//  VideoEcho.cpp
//  ccProject3
//
//  Created by Latifah Dickson on 15/11/2024.
//

#include "VideoEcho.hpp"

VideoEcho::VideoEcho(){
    delayTime = 0.2f;
    fadeFactor = 0.2f;
    maxFrames = 5;

}

void VideoEcho::setup(float _delayTime, float _fadeFactor, int _maxFrames){
    delayTime = _delayTime; // controls how much of a time gap there is between each stored frame
    fadeFactor = _fadeFactor; // controls how much each successive echo frame fades out
    maxFrames = _maxFrames;
}

void VideoEcho::update(ofVideoPlayer &video){
    
    ofPixels currentPixels = video.getPixels();
    
    if (previousFrames.size() >= maxFrames) {
        previousFrames.erase(previousFrames.begin());
    }
    
    previousFrames.push_back(currentPixels);
}

void VideoEcho::apply(ofVideoPlayer &video, float x, float y, float width, float height){
    //draws current frame with the previous frames w/ decreasing opacity to simulate the echo
    //each stored frame gets drawn with a progressively lower opacity based on the fadeFactor
    
    float opacity = 255.0f;
    int numFrames = previousFrames.size();
    
    
    //draws current frame
    video.draw(x,y,width,height);
    
    for (int i = numFrames - 1; i >= 0; i--){
        opacity *= fadeFactor;
        ofSetColor(255, 255, 255, opacity);
        ofImage echoImage;
        echoImage.setFromPixels(previousFrames[i]);
        echoImage.draw(x,y, width, height);
    }
    
    
}

void VideoEcho::clearFrames(){
    previousFrames.clear();
}
