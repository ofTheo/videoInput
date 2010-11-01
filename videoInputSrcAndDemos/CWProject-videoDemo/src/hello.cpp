#include <stdio.h>
#include "glfw.h"
#include "triangleApp.h"
#include "windows.h"



triangleApp TAPP;
	 

void GLFWCALL keyfun( int key, int action )
{
    if( action != GLFW_PRESS )
    {
        return;
    }

    switch( key )
    {
	    case GLFW_KEY_ESC:
        	printf( "ESC => quit program\n" );
        	break;    	
       
    }

	TAPP.keyDown(key);

    fflush( stdout );
}







int main( void )
{


    int     width, height, running, frames, x, y;
    double  t, t0, fps;
    char    titlestr[ 200 ];
	

    // Initialise GLFW
    glfwInit();

    // Open OpenGL window    
    if (!glfwOpenWindow(1024,768,    // Open window
    24, 24, 24,                                // Red, green, and blue bits for color buffer
    24,                                        // Bits for alpha buffer
    24,                                        // Bits for depth buffer (Z-buffer)
    24,                                        // Bits for stencil buffer
    GLFW_WINDOW)){
        glfwTerminate();
        return 0;
    }
    
    
    glfwSetKeyCallback( keyfun );
    TAPP.init();
    glfwEnable( GLFW_STICKY_KEYS );
    // Disable vertical sync (on cards that support it)
    glfwSwapInterval( 1 );

    // Main loop
    running = GL_TRUE;
    frames = 0;
    t0 = glfwGetTime();
    while( running ){
    
        // Get time and mouse position
        t = glfwGetTime();
        glfwGetMousePos( &x, &y );
        
        // Calculate and display FPS (frames per second)
        if( (t-t0) > 1.0 || frames == 0 )
        {
            fps = (double)frames / (t-t0);
            sprintf( titlestr, "videoInput Demo App (%.1f FPS)", fps );
            glfwSetWindowTitle( titlestr );
            t0 = t;
            frames = 0;
        }
        frames ++;
        TAPP.idle();
		 
		
        // Get window size (may be different than the requested size)
        glfwGetWindowSize( &width, &height );
        height = height > 0 ? height : 1;
        // Set viewport
        glViewport( 0, 0, width, height );
        // Clear color buffer
        glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        glClear( GL_COLOR_BUFFER_BIT );

		  TAPP.draw();			
        // Swap buffers
        glfwSwapBuffers();
		
        // Check if the ESC key was pressed or the window was closed
        running = !glfwGetKey( GLFW_KEY_ESC ) &&
                  glfwGetWindowParam( GLFW_OPENED );
    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
