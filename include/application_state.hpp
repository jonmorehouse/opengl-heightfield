#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

// the idea of this namespace is to allow for an easy place to store global data for this application without polluting the global namespace unless we want to
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

namespace application_state {
	
	/* state of the world */
	float g_vLandRotate[3] = {0.0, 0.0, 0.0};
	float g_vLandTranslate[3] = {0.0, 0.0, 0.0};
	float g_vLandScale[3] = {1.0, 1.0, 1.0};

}

#endif