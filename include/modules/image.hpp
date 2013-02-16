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
#include "application_state.hpp"


namespace image {

	void saveScreenshot (char * filename);

	
	

}

#endif