#ifndef IMAGE_HPP
#define IMAGE_HPP

/*
	Image namespace is responsible for handling all image related entities
	This namespace will handle loading in image data, taking screenshots and most interaction with pic library
*/	
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>


// initialized in the main.cpp when we load in the correct image and load it with pic library
extern Pic * currentImage;

namespace image {

	void saveScreenshot (char * filename);
	
}

#endif