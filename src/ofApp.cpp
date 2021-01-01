#include "ofApp.h"
#include <string>


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Blank Canvas");
	ofSetWindowShape(720, 720);
	ofSetFrameRate(60);
	ofBackground(ofColor::black);

	showGui = true;

	gui.setup("Parameters","Settings.xml");
	gui.add(backgroundcolor.setup("backgroundcolor", ofColor::black, ofColor(0, 0, 0, 0), ofColor::white));
	gui.add(triangle.setup("primative: triangle", true));
	gui.add(circle.setup("primative: circle", false));

	gui_primative.setup("Primative Shape Parameters");
	gui_primative.add(iteration_primative.setup("Iteration", 50, 0, 200));
	gui_primative.add(spacing_primative.setup("Spacing", 20, 0, 200));
	gui_primative.add(twist_primative.setup("Twist", 5, -45, 45));
	gui_primative.add(rotate.setup("Twist Primatives", 0.0, -18.0, 180.0));
	gui_primative.add(shiftY.setup("Vertical Step", 0.0, -500.0, 500.0));
	gui_primative.add(scale.setup("scale", ofVec2f(6, 6), ofVec2f(0, 0), ofVec2f(20, 20)));
	gui_primative.add(color_triangle.setup("color triangle",ofColor::ivory,ofColor(0,0,0,0),ofColor::white));
	gui_primative.add(color_circle.setup("color circle", ofColor::ivory, ofColor(0, 0, 0, 0), ofColor::white));
	gui_primative.add(filled.setup("filled", false));

	matrix_pattern.setup("Matrix pattern");
	matrix_pattern.add(countY.setup("Pattern Repeat Count", 0, 0, 50));
	matrix_pattern.add(stepY.setup("Vertical step", 20, 0, 200));
	matrix_pattern.add(twistY.setup("Twist Repetations", 0, -30, 30));
	matrix_pattern.add(pinchY.setup("Pinch", 0, 0, 1));

	gui.add(&gui_primative);
	gui.add(&matrix_pattern);

	gui.loadFromFile("get_last_setting.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(backgroundcolor);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//--- 

	if (filled) {
		ofFill();
		matrixPattern();
	}
	else {
		ofNoFill();
		matrixPattern();
	}
	//--
	
	ofPopMatrix();
	if (showGui) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'z') showGui = !showGui;
	if (key == OF_KEY_RETURN) {
		std::string filename;
		std::cout <<"Enter name for the screenshot" <<std::endl;
		std::getline(std::cin, filename);
		ofSaveScreen(filename+".png");
		std::cout << filename+".png" +" "+"Saved Succesfully" << std::endl;
	}
	if (key == 's') {
		ofFileDialogResult res;
		res = ofSystemSaveDialog("preset.xml", "Saving Preset");
		if (res.bSuccess) gui.saveToFile(res.filePath);
	}
	if (key == 'l') {
		ofFileDialogResult res;
		res = ofSystemLoadDialog("Loading Preset");
		if (res.bSuccess) gui.loadFromFile(res.filePath);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::stripePattern_primative(ofColor color, float linewidth, float spacing, float twist, int iterations)
{
	ofSetColor(color);
	ofSetLineWidth(linewidth);
	for (int i = -iterations + 1; i < iterations; i++) {
		ofPushMatrix();
		ofTranslate(i * spacing, 0);
		ofRotateDeg(i * twist);
		ofTranslate(0, shiftY);
		ofRotate(rotate);
		ofScale(scale->x, scale->y);
		if (circle) ofCircle(0,0,30);
		if(triangle) ofTriangle(0, 0, -30, 70, 30, 70);
		ofPopMatrix();
	}
}

void ofApp::matrixPattern()
{
	for (int y = -countY; y <= countY; y++) {
		ofPushMatrix();
		//---------------------
		if (countY > 0) {
			float scl = ofMap(y, -countY, countY, 1 - pinchY, 1);
			ofScale(scl, scl);
		}
		ofTranslate(0, y * stepY);
		ofRotate(y * twistY);
		if (circle)	stripePattern_primative(color_circle, 1.0, spacing_primative, twist_primative, iteration_primative);
		ofPopMatrix();
		ofPushMatrix();
		if (triangle)	stripePattern_primative(color_triangle, 1.0, spacing_primative, twist_primative, iteration_primative);
		//---------------------
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit() {
	gui.saveToFile("get_last_setting.xml");
}
