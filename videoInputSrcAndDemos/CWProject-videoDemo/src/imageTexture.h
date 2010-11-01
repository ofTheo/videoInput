#ifndef _IMAGE_TEXTURE_H_
#define _IMAGE_TEXTURE_H_

#include "glfw.h" //gl shit
#include <stdio.h>


class imageTexture {


	public :
		
		imageTexture(int w, int h, int internalGlDataType);	 
		// if w, h are not powers of 2 you will not see anything.
		
		void loadImageData(unsigned char * data, int w, int h, int glDataType); 
		// w,h here MUST be <= initial w,h
		
		void renderTexture(int x, int y, int w, int h);
	
		void renderTextureWithBox(int x, int y, int w, int h, float r, float g, float b, int border);
	
		float tex_t, tex_u;   

	private:		
		int tex_w, tex_h;
		GLuint * myTex;

}; 

#endif
