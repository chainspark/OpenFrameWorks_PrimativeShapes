#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		bool showGui;

		ofxPanel gui;
		ofxColorSlider backgroundcolor;

		ofxGuiGroup gui_primative;
		ofxIntSlider iteration_primative;
		ofxFloatSlider spacing_primative;
		ofxFloatSlider twist_primative;
		ofxFloatSlider shiftY, rotate;
		ofxVec2Slider scale;
		ofxColorSlider color_triangle,color_circle;
		ofxToggle filled, triangle,circle;

		ofxGuiGroup matrix_pattern;
		ofxIntSlider countY;
		ofxFloatSlider stepY, twistY, pinchY;
		void matrixPattern();


		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void stripePattern_primative(ofColor color, float linewidth, float spacing, float twist, int iterations);

		void exit();

		
};
