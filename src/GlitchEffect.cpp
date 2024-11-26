#include "GlitchEffect.hpp"

GlitchEffect::GlitchEffect() {
    glitchInterval = 20;  // triggers the glitches every 20 frames
    frameCounter = 0;
    glitchStrength = 50;  // increases strength of the glitch
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
    int numGlitches = 2;  // Number of glitch strips

    for (int i = 0; i < numGlitches; i++) {
        // Random vertical position within the video
        int offsetY = ofRandom(0, video.getHeight() - 1);  // Ensure offset is within the bounds

        int offsetX = ofRandom(0, video.getHeight() - 1);  // Ensure offset is within the bounds
        // Random size for the glitch rectangle, ranging from a small section to the entire video
        float glitchWidth = ofRandom(width * 0.1, width);  // Random width between 10% and 100% of the video width
        float glitchHeight = ofRandom(height * 0.1, height);  // Random height between 10% and 100% of the video height

        // Random horizontal displacement amount
        int displacement = ofRandom(-glitchStrength, glitchStrength);

        // Create a rectangle from the video to displace and draw it
        ofPixels pixels = video.getPixels();
        ofImage glitchImage;
        glitchImage.setFromPixels(pixels);
        
        
        //colour channel effect
        bool applyColorEffect = (ofRandom(1.0f) > 0.5f);  // 50% chance of applying the effect

              if (applyColorEffect) {
                  // modifies the colour channels of the pixels in the glitchImage
                  for (int y = 0; y < glitchImage.getHeight(); y++) {
                      for (int x = 0; x < glitchImage.getWidth(); x++) {
                          ofColor color = glitchImage.getColor(x, y);

                          //channel mix
                          color.r = ofClamp(color.g, 0, 255);  // Swap red with green
                          color.g = ofClamp(color.b, 0, 255);  // Swap green with blue
                          color.b = ofClamp(color.r, 0, 255);  // Swap blue with red

                          glitchImage.setColor(x, y, color);
                      }
                  }
                  glitchImage.update();  // Update the image with the modified colours
              }

        // Bind the texture for drawing
        glitchImage.getTexture().bind();
        ofSetColor(255, 255, 255, 255);

        // Draw the original section of the video in its original position
        glitchImage.getTexture().drawSubsection(x, y + offsetY, glitchWidth, glitchHeight, x, offsetY);

        // Draw the displaced version on top to create the glitch effect
        glitchImage.getTexture().drawSubsection(x + displacement, y + offsetY, glitchWidth, glitchHeight, x, offsetY);
        
        // Unbind the texture
        glitchImage.getTexture().unbind();
    }
}
