#ifndef INTERACTION_HPP 
#define INTERACTION_HPP
/*

	Interaction namespace is used for the utilities useful for handling user interaction with the application
	We will handle events that occur here and will properly offset them to other modules etc in other namespaces
	We will handle menu options etc here	

*/

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>
#include "application_state.hpp"

namespace interaction {

	// initialize a type to help us determine which controlstate the user currently is in
	typedef enum {ROTATE, TRANSLATE, SCALE}	CONTROLSTATE;
	
	// initialize some integers for various menu options etc
	int g_iMenuId,
		// store the mouse position (x,y) as [x,y]
		g_vMousePos[2] = {0,0},	
		// store the mouse buttons each time to determine what is stored etc
		g_iLeftMouseButton = 0,
		g_iMiddleMouseButton = 0,
		g_iRightMouseButton = 0;
			

	// function definitions that will be used here
	void mouseidle(int x, int y); 

	// mouse button will be used to handle button clicks from glut
	void mousebutton(int button, int state, int x, int y); 

	// implement a basic mousedrag listener
	// convert mouse drags into information about rotation / translation / scaling
	void mousedrag(int x, int y); 

	
	// basic menu functionality
	void menufunc(int value);
}

#endif