#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

#include "application_state.hpp"

namespace application {

	void init();	
	void display();
}

#endif 	