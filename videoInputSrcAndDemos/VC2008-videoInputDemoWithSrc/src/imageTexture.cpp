
#include "imageTexture.h"



imageTexture::imageTexture(int w, int h, int internalGlDataType){

	tex_w = w;
	tex_h = h;
	
	tex_u = 1.0f;
	tex_t = 1.0f;

	// if w, h are not powers of 2 you will not see anything.
	// create the named texture:
		
	myTex = new GLuint[1];
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // not necessary, I think
	glGenTextures(1, myTex);   // could be more then one, but for now, just one
	
	glEnable(GL_TEXTURE_2D);
	
		glBindTexture(GL_TEXTURE_2D, myTex[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, internalGlDataType, tex_w, tex_h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);  // init to black...
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	glDisable(GL_TEXTURE_2D);
	

}




void imageTexture::loadImageData(unsigned char * data, int w, int h, int glDataType){

	if ( w > tex_w || h > tex_h) {
		printf("image data too big - bailing \n");
		return;
	}
	
	
	//compute new tex co-ords based on the ratio of data's w, h to texture w,h;
	
	tex_t = (float)w / (float)tex_w;
	tex_u = (float)h / (float)tex_h;
	
	// update the texture image:
	
	glEnable(GL_TEXTURE_2D);
	
		glBindTexture(GL_TEXTURE_2D, myTex[0]);
 		glTexSubImage2D(GL_TEXTURE_2D,0,0,0,w,h,glDataType,GL_UNSIGNED_BYTE,data);	
	
	glDisable(GL_TEXTURE_2D);
}

//=================================================================================
void imageTexture::renderTexture(int x, int y, int w, int h){


	glEnable(GL_TEXTURE_2D);
	
	// bind the texture
	glBindTexture( GL_TEXTURE_2D, myTex[0] );
	
		float px0 = x  ;		// up to you to get the aspect ratio right
		float py0 = y  ;
		float px1 = x+w;
		float py1 = y+h;
		
		glBegin( GL_QUADS );
			glTexCoord2f(0.0,0.0);					glVertex3f(px0, py0,0);
			glTexCoord2f(tex_t,0.0);				glVertex3f(px1, py0,0);
			glTexCoord2f(tex_t,tex_u);				glVertex3f(px1, py1,0);
			glTexCoord2f(0.0,tex_u);				glVertex3f(px0, py1,0);
		glEnd();
		
	glDisable(GL_TEXTURE_2D);

}

//=================================================================================
void imageTexture::renderTextureWithBox(int x, int y, int w, int h, float r, float g, float b, int border){


	
	// bind the texture
	
		float px0 = x  ;		// up to you to get the aspect ratio right
		float py0 = y  ;
		float px1 = x+w;
		float py1 = y+h;
		
		glColor3f(r,g,b);
		glBegin( GL_QUADS );
			glVertex3f(px0-border, py0-border,0);
			glVertex3f(px1+border, py0-border,0);
			glVertex3f(px1+border, py1+border,0);
			glVertex3f(px0-border, py1+border,0);
		glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, myTex[0] );
				
		glBegin( GL_QUADS );
			glTexCoord2f(0.0,0.0);					glVertex3f(px0, py0,0);
			glTexCoord2f(tex_t,0.0);				glVertex3f(px1, py0,0);
			glTexCoord2f(tex_t,tex_u);				glVertex3f(px1, py1,0);
			glTexCoord2f(0.0,tex_u);				glVertex3f(px0, py1,0);
		glEnd();
		
	glDisable(GL_TEXTURE_2D);

}

