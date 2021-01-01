#include "ofMain.h"
#include "ofApp.h"
#include <iostream>
//========================================================================
int main( ){

	std::cout <<"Keyboard commands" << std::endl
		<< " z : Toggle Gui Panel" << std::endl
	<< " s : Save parameters to .xml file" << std::endl
	<< " l : Load parameters from .xml file" << std::endl
		<< "Enter : Save screenshot " << std::endl;

	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
