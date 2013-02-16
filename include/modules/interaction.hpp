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

extern float g_vLandRotate[3];
extern float g_vLandTranslate[3];
extern float g_vLandScale[3];

namespace interaction {

	// initialize a type to help us determine which controlstate the user currently is in
	typedef enum {ROTATE, TRANSLATE, SCALE}	CONTROLSTATE;
	
	// initialize some integers for various menu options etc
	extern int g_iMenuId,
		g_vMousePos[2],
		g_iLeftMouseButton,
		g_iMiddleMouseButton,
		g_iRightMouseButton;

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