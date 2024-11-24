#include "MotionBlur.hpp"
#include <cmath>  // For sqrt and pow functions - which is used to calcultae euclidean distance between colours

MotionBlur::MotionBlur(){
    blendFactor = 0.9f;  // determines how much of the current frame blends into the accumulation buffer
    stretchAmount = 0.2f;  // threshold to decide when to apply stretching effects based on motion intensity.
}

void MotionBlur::setup(float _blendFactor, float _stretchAmount){
    blendFactor = _blendFactor;
    stretchAmount = _stretchAmount;
    
    // Allocate an accumulation buffer
    accumulationBuffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    accumulationBuffer.begin();
    ofClear(0, 0, 0, 0); // Clear the buffer
    accumulationBuffer.end();
}

float MotionBlur::colorDistance(const ofColor &color1, const ofColor &color2) {
    // Calculate the Euclidean distance between two colors
    float rDiff = color1.r - color2.r;
    float gDiff = color1.g - color2.g;
    float bDiff = color1.b - color2.b;
    
    return sqrt(rDiff * rDiff + gDiff * gDiff + bDiff * bDiff);
    
    //this function is used to calculate the euclidean distance between colours in the RGB space - measureing how different 2 colours are which helps detect the motion between frames.
}

void MotionBlur::update(ofVideoPlayer &video){
    // fetch the current frame's pixels
    ofPixels currentPixels = video.getPixels();
    
    if (previousFramePixels.getWidth() != 0) {
        // if there's a prev frame, calculate the pixel difference (motion)
        int width = currentPixels.getWidth();
        int height = currentPixels.getHeight();
        
        // Iterate through each pixel - x,y - in the current frame and calculate the RGB distance to detect motion
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                ofColor currentColor = currentPixels.getColor(x, y);
                ofColor previousColor = previousFramePixels.getColor(x, y);
                
                // Calculate the Euclidean distance between the two colors
                float distance = colorDistance(currentColor, previousColor);
                
                // Stretch based on distance (motion detection)
                if (distance > stretchAmount) {
                    // Apply some stretching effect if the distance is large enough (motion detected)
                    float stretch = ofMap(distance, 0, 255, 0, stretchAmount);
                    
        
                }
            }
        }
    }
    
    // Store the current frame as the previous frame for the next update
    previousFramePixels = currentPixels;
    
    // Update the accumulation buffer with the current frame
    accumulationBuffer.begin();
    ofSetColor(255);
    video.draw(0, 0);
    accumulationBuffer.end();
}

void MotionBlur::apply(ofVideoPlayer &video, float x, float y, float width, float height){
    // Draw the accumulated motion blur from the buffer
    ofSetColor(255);
    accumulationBuffer.draw(x, y, width, height);
}

void MotionBlur::clear(){
    // Clear the accumulation buffer
    accumulationBuffer.begin();
    ofClear(0, 0, 0, 0);
    accumulationBuffer.end();
}
