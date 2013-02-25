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

	// implement my own custom mapping system for switching between the display states etc
	int currentDisplay = 0;
	display::DisplayType displayTypeMap[3] = {display::GRAYSCALE, display::POINT, display::WIREFRAME};

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

		// change each time
		float delta = 10.0;

		// rotate counter clockwise / clockwise etc --- around the z axis
		if (key == GLUT_KEY_LEFT)
			rotation[1] -= delta;

		if (key == GLUT_KEY_RIGHT)
			rotation[1] += delta;

		// rotate about the x axis this is into and out of the screen
		if (key == GLUT_KEY_UP) 
			rotation[0] += delta;

		if (key == GLUT_KEY_DOWN)
			rotation[0] -= delta;

		// set up the rotation of the camera about the x axis -- this is the equivalent of swinging the camera around the on the horizontal axis	
		if (key == 107) {//k key -- vim key mappings! -- rotate left
			
			// make sure we don't need a reset etc
			if (currentDisplay == 0) currentDisplay = 2;
			else --currentDisplay;//if not, just subtract one from the current
			
		} 
		// now listen for the j key to move left
		if (key == 106) {

			if(currentDisplay == 2) currentDisplay = 0;
			else ++currentDisplay;
		}

		// set the global display type to properly change according to our display type map as declared before
		displayType = displayTypeMap[currentDisplay];

		glutPostRedisplay();
		
	}
}
