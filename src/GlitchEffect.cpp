#include "GlitchEffect.hpp"

GlitchEffect::GlitchEffect() {
    glitchInterval = 20;  // Trigger glitches every 20 frames
    frameCounter = 0;
    glitchStrength = 50;  // increased strength of the glitch
    glitchProbability = 0.9f;  //probability of glitching
}

void GlitchEffect::setup(int _glitchInterval, float _glitchStrength, float _glitchProbability) {
    glitchInterval = _glitchInterval;
    glitchStrength = _glitchStrength;
    glitchProbability = _glitchProbability;
}

void GlitchEffect::update(ofVideoPlayer &video) {
    frameCounter++;

    // randomly triggers a glitch effect every x frames
    if (frameCounter % glitchInterval == 0) {
        if (ofRandom(1.0f) < glitchProbability) {
            applyGlitch(video, 0, 0, video.getWidth(), video.getHeight());
        }
    }
}

void GlitchEffect::apply(ofVideoPlayer &video, float x, float y, float width, float height) {
    ofSetColor(255);
    video.draw(x, y, width, height); // Draw the video normally

    applyGlitch(video, x, y, width, height); // apply glitch on top of the video
}

void GlitchEffect::applyGlitch(ofVideoPlayer &video, float x, float y, float width, float height) {
    //random offset to create the glitch effect
    int numGlitches = 2;  // number of glitch strips
    for (int i = 0; i < numGlitches; i++) {
        // random vertical position and displacement amount
        int offsetY = ofRandom(0, video.getHeight());
        int displacement = ofRandom(-glitchStrength, glitchStrength);
        
        // creates a rectangle from the video to displace and draw it
        ofPixels pixels = video.getPixels();
        ofImage glitchImage;
        glitchImage.setFromPixels(pixels);
        
        // Simulate a glitch by shifting part of the image horizontally
        glitchImage.getTexture().bind();
        ofSetColor(255, 255, 255, 255);
        glitchImage.getTexture().drawSubsection(x, y + offsetY, width, height, displacement, 0);  // horizontal displacement
        glitchImage.getTexture().unbind();
    }
}
