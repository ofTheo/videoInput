#ifndef _SIMPLE_APP
#define _SIMPLE_APP

#include <stdio.h>
#include "glfw.h"

#define 	PI 3.141592654
#include <math.h>

class simpleApp{
	
	public:
		simpleApp();
		void printYo();
		virtual void idle();
		virtual void init();
		virtual void draw();
		virtual void keyDown  (char c);
		virtual void mouseMove( float x, float y );
		virtual void mouseDrag( float x, float y );
		virtual void mouseDown( float x, float y, int button );
		virtual void mouseUp  ( float x, float y, int button );
		
		
		void setupScreen();
};

#endif	// _SIMPLE_APP