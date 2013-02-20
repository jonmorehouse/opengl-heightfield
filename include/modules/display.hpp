#ifndef DISPLAY_HPP
#define DISPLAY_HPP

// require project libraries
#include "classes/height_field.hpp"

// require the proper libraries
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

namespace display {

	typedef enum {

		GRAYSCALE,
		WIREFRAME,
		POINT,
		
	} DisplayType;

	// draw points is useful for drawing the map by simply drawing out elements
	void drawPoints();

	// draw out grayscale gradient for this particular element
	void drawGrayscale();

	// void draw wireframe of the mesh etc
	void drawWireFrame();

}

#endif