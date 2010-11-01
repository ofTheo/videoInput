#include "simpleApp.h"

simpleApp::simpleApp(){

}

void simpleApp::idle(){

}

void simpleApp::init(){

}


void simpleApp::draw(){
	
}

void simpleApp::keyDown  (char c){

}

void simpleApp::mouseMove( float x, float y ){

}

void simpleApp::mouseDrag( float x, float y ){

}

void simpleApp::mouseDown( float x, float y, int button ){

}

void simpleApp::mouseUp  ( float x, float y, int button ){

}


void simpleApp::printYo(){
	
}


void simpleApp::setupScreen(){
	
	int w, h;
	
	glfwGetWindowSize( &w, &h );
	float halfFov, theTan, screenFov, aspect;
	
	screenFov = 60.0f;
	
	float eyeX = (float)w / 2.0;
	float eyeY = (float)h / 2.0;
	halfFov = PI * screenFov / 360.0;
	theTan = tanf(halfFov);
	float dist = eyeY / theTan;
	float nearDist = dist / 10.0;	// near / far clip plane
	float farDist = dist * 10.0;
	aspect = (float)w/(float)h;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(screenFov, aspect, nearDist, farDist);
	gluLookAt(eyeX, eyeY, dist, 
	eyeX, eyeY, 0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	

	
}


	

/*
	simpleApp	: 	openFullscreen;
						coordSystem;
						swap();
						

*/

