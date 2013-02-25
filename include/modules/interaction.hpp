#ifndef INTERACTION_HPP 
#define INTERACTION_HPP
/*

	Interaction namespace is used for the utilities useful for handling user interaction with the application
	We will handle events that occur here and will properly offset them to other modules etc in other namespaces
	We will handle menu options etc here	

*/

// initialize our proper libraries for this application
#include "classes/height_field.hpp"	
#include "modules/display.hpp"
// initialize the standard gl libraries if they are not currently active
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

// initialize the heightfields and other elements that are declared externally etc... check the main.cpp file
extern HeightField * heightField;//set up and initialized in our main init function
extern float rotation[3];// set up and initialized in main file
extern float translation[3];// set up and initialized in main file
extern float scale[3];// set up and initialized in main file
extern float cameraRotation[2];//load the current camera rotation for the point of view
extern display::DisplayType displayType;//initialized in the main function this is what controls the wireframe, grayscale and points element and any further modes
	// note the displayMap and currentDisplay that are encapsulated in this namespace for controlling the current view
extern unsigned int wireframeDensity;//this is the wireframe density

namespace interaction {

	// initialize a type to help us determine which controlstate the user currently is in
	typedef enum {ROTATE, TRANSLATE, SCALE}	CONTROLSTATE;
	
	// initialize some integers for various menu options etc
	extern int g_iMenuId,
		g_vMousePos[2],
		g_iLeftMouseButton,
		g_iMiddleMouseButton,
		g_iRightMouseButton;

	extern int currentDisplay;//what the current display element consists of! 
	extern display::DisplayType displayTypeMap[3];//this is a mapper of the currently available display types



	// mouse idle is useful for when the mouse is just sitting somewhere
	void mouseidle(int x, int y); 

	// mouse button will be used to handle button clicks from glut
	void mousebutton(int button, int state, int x, int y); 

	// implement a basic mousedrag listener
	// convert mouse drags into information about rotation / translation / scaling
	void mousedrag(int x, int y); 
	
	// basic menu functionality
	void menufunc(int value);

	// enable the keypress functionality etc
	void keyPress(int key, int x, int y);

	// initialize the menu
	void init();//initialize the menu

}

#endif