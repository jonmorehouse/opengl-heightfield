#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>
#include "modules/image.hpp"
#include "classes/height_field.hpp"

extern HeightField * heightField;//set up and initialized in our main init function
extern float rotation[3];// set up and initialized in main file
extern float translation[3];// set up and initialized in main file
extern float scale[3];// set up and initialized in main file

namespace application {

	// initialize image and basics of the application here
	void init();	
	// idle function called when nothing happening on machine
	void idle();
	// display is what is shown each time
	void display();

	// draw out all the polygons -- responsible for drawing out with the proper elements etc
	void drawPolygons();//draws out the individual polygons

	// draw an individual polygon -- will be a plainly formatted drawPolygon
	void drawPolygon(unsigned int x, unsigned int y);

	// responsible for drawing a single plane given a particular element
	void drawPlane(unsigned int x, unsigned int y);
}

#endif 	