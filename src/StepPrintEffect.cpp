#include "StepPrintEffect.hpp"

StepPrinting::StepPrinting() {
    stepInterval = 20;         // Interval to capture every 10th frame
    frameCounter = 0;
    maxStoredFrames = 1;       // Adjust to see more frames in sequence
}

void StepPrinting::setup(int _stepInterval) {
    stepInterval = _stepInterval;
    storedFrames.clear();
}

void StepPrinting::update(ofVideoPlayer &video) {
    frameCounter++;

    // Check if the video is loaded and has valid pixels
    if (video.isLoaded() && video.getPixels().isAllocated()) {
        // Capture frame at the specified interval
        if (frameCounter % stepInterval == 0) {
            ofImage frame;
            frame.setFromPixels(video.getPixels());

            // Store the new frame and ensure the vector size is managed
            storedFrames.push_back(frame);
            if (storedFrames.size() > maxStoredFrames) {
                storedFrames.erase(storedFrames.begin());
            }

            // Debugging output
            ofLog() << "Captured frame. Total stored frames: " << storedFrames.size();
        }
    }
}

void StepPrinting::apply(ofVideoPlayer &video, float x, float y, float width, float height) {
//    ofSetColor(255);
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
//
//
//    // Draw each stored frame in the sequence
//    for (const auto& frame : storedFrames) {
//        frame.draw(x, y, width, height);
//    }
//    
//    ofDisableBlendMode();
//    ofSetColor(255);
    
    // Draw each stored frame with decreasing opacity
      for (int i = 0; i < storedFrames.size(); ++i) {
          float opacity = 255 * (1.0f - float(i) / maxStoredFrames); // Fade effect
          ofSetColor(255, 255, 255, opacity);
          storedFrames[i].draw(x, y, width, height);
      }

      ofSetColor(255); // Reset to full opacity after drawing

}

void StepPrinting::clear() {
    storedFrames.clear();
}
