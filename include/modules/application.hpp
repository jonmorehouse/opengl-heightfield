#ifndef APPLICATION_HPP
#define APPLICATION_HPP

// initialize our other namespace functions for heightfield data and the display methods that will actually display our imagery
#include "classes/height_field.hpp"
#include "modules/display.hpp"

// initialize standard libraries needed if they were not already included
#include <stdlib.h>
#include <math.h>

// gl libraries
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

// height field object is the data that drives the program
extern HeightField * heightField;//set up and initialized in our main init function
// grab the current type of display for rendering
// extern DisplayType displayType;
// grab the current window dimensions
extern int windowHeight;
extern int windowWidth;
// current translations for the model view
extern float rotation[3];// set up and initialized in main file
extern float translation[3];// set up and initialized in main file
extern float scale[3];// set up and initialized in main file
extern float cameraRotation[2];//grab the camera rotation from the main function. This will rotate the point of view 
extern float cameraDistance;//this is how far away the camera is -- ie the radius of the sphere of view

// access our current application display type from main.cpp function
// this will also be edited in the interaction namespace by responses from our glut loop
extern display::DisplayType displayType;


// 
namespace application {

	// initialize image and basics of the application here
	void init();	
	// idle function called when nothing happening on machine
	void idle();
	// display is what is shown each time
	void display();

	// display controller is responsible for abstracting away the calls to our display elements
	void displayController();

	// display resizer -- responsible for applying resizing elements for each piece
	void displayResizer();//responsible for getting element size and then transforming etc based on that

}

#endif 	