#ifndef _TRIANGLE_APP

#include <stdio.h>
#include "glfw.h"
#include "simpleApp.h"
#include "imageTexture.h"
#include "videoInput.h"
#include "uuids.h"

class triangleApp : public simpleApp{
	
	public:
		triangleApp();
		virtual void idle();
		virtual void init();
		virtual void draw();
		virtual void keyDown  (char c);
		virtual void mouseMove( float x, float y );
		virtual void mouseDrag( float x, float y );
		virtual void mouseDown( float x, float y, int button );
		virtual void mouseUp  ( float x, float y, int button );
		

		imageTexture * IT;
		imageTexture * IT2;
		videoInput     VI;

		unsigned char * frame;
		unsigned char * frame2;


		
};

#endif	// _triangle_APP