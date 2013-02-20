#include "modules/interaction.hpp"

namespace interaction {

	// initialize the control state etc
	CONTROLSTATE g_ControlState;
		
	int g_iMenuId,
		// store the mouse position (x,y) as [x,y]
		g_vMousePos[2] = {0,0},	
		// store the mouse buttons each time to determine what is stored etc
		g_iLeftMouseButton = 0,
		g_iMiddleMouseButton = 0,
		g_iRightMouseButton = 0;

	void mouseidle(int x, int y) {
	  g_vMousePos[0] = x;
	  g_vMousePos[1] = y;
	}

	void mousebutton(int button, int state, int x, int y) {

	  switch (button)
	  {
	    case GLUT_LEFT_BUTTON:
	      g_iLeftMouseButton = (state==GLUT_DOWN);
	      break;
	    case GLUT_MIDDLE_BUTTON:
	      g_iMiddleMouseButton = (state==GLUT_DOWN);
	      break;
	    case GLUT_RIGHT_BUTTON:
	      g_iRightMouseButton = (state==GLUT_DOWN);
	      break;
	  }
	 
	  switch(glutGetModifiers())
	  {
	    case GLUT_ACTIVE_CTRL:
	      g_ControlState = TRANSLATE;
	      break;
	    case GLUT_ACTIVE_SHIFT:
	      g_ControlState = SCALE;
	      break;
	    default:
	      g_ControlState = ROTATE;
	      break;
	  }

	  g_vMousePos[0] = x;
	  g_vMousePos[1] = y;
	}

	// mouse drag changes mouse drags into information about scaling / rotation etc
	void mousedrag(int x, int y) {

	  int vMouseDelta[2] = {x-g_vMousePos[0], y-g_vMousePos[1]};
	  
	  switch (g_ControlState)
	  {
	    case TRANSLATE:  
	      if (g_iLeftMouseButton)
	      {
	        translation[0] += vMouseDelta[0]*0.01;
			translation[1] -= vMouseDelta[1]*0.01;
	      }
	      if (g_iMiddleMouseButton)
	      {
			translation[2] += vMouseDelta[1]*0.01;
	      }
	      break;
	    case ROTATE:
	      if (g_iLeftMouseButton)
	      {
	        rotation[0] += vMouseDelta[1];
	        rotation[1] += vMouseDelta[0];
	      }
	      if (g_iMiddleMouseButton)
	      {
	        rotation[2] += vMouseDelta[1];
	      }
	      break;
	    case SCALE:
	      if (g_iLeftMouseButton)
	      {
	        scale[0] *= 1.0+vMouseDelta[0]*0.01;
	        scale[1] *= 1.0-vMouseDelta[1]*0.01;
	      }
	      if (g_iMiddleMouseButton)
	      {
	        scale[2] *= 1.0-vMouseDelta[1]*0.01;
	      }
	      break;
	  }
	  g_vMousePos[0] = x;
	  g_vMousePos[1] = y;
	}


	void menufunc(int value) {
	  switch (value)
	  	{
	    case 0:
	      exit(0);
	      break;
	  }
	}


	// initialize all the menu functionality
	void init() {

		g_iMenuId = glutCreateMenu(menufunc);
		glutSetMenu(g_iMenuId);
		glutAddMenuEntry("Quit", 0);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}

	void keyPress(int key, int x, int y) {

		float delta = 10.0;

		if (key == GLUT_KEY_LEFT)
			rotation[1] -= delta;

		if (key == GLUT_KEY_RIGHT)
			rotation[1] += delta;

		if (key == GLUT_KEY_UP) 
			rotation[0] += delta;

		if (key == GLUT_KEY_DOWN)
			rotation[0] -= delta;

		glutPostRedisplay();
		
	}
}
