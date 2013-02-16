#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

extern float g_vLandRotate[3];
extern float g_vLandTranslate[3];
extern float g_vLandScale[3];

namespace application {

	void init();	
	void display();
}

#endif 	