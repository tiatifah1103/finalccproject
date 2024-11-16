#pragma once

#include "ofMain.h"
#include "VideoEcho.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		
    
    ofVideoPlayer video;
    VideoEcho videoEcho;

    //test commit
    //test commit 2
};
