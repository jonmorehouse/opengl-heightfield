/*
  CSCI 480 Computer Graphics
  Assignment 1: Height Fields
  C++ starter code
*/

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

/* see <your pic directory>/pic.h for type Pic */
Pic * g_pHeightData;

// declare our local variables for this application
float g_vLandRotate[3] = {0.0, 0.0, 0.0};
float g_vLandTranslate[3] = {0.0, 0.0, 0.0};
float g_vLandScale[3] = {0.0, 0.0, 0.0};

// include our application namespaces
#include "modules/interaction.hpp"
#include "modules/image.hpp"
#include "modules/application.hpp"

void doIdle() {
  /* do some stuff... */

  /* make the screen update */
  glutPostRedisplay();
}



int main (int argc, char ** argv) {

  return 0;

  // if (argc<2)
  // {  
  //   printf ("usage: %s heightfield.jpg\n", argv[0]);
  //   exit(1);
  // }

  // g_pHeightData = jpeg_read(argv[1], NULL);
  // if (!g_pHeightData)
  // {
  //   printf ("error reading %s.\n", argv[1]);
  //   exit(1);
  // }

  // glutInit(&argc,argv);
  
  // /*
  //   create a window here..should be double buffered and use depth testing
  
  //   the code past here will segfault if you don't have a window set up....
  //   replace the exit once you add those calls.
  // */
  // exit(0);

  // /* tells glut to use a particular display function to redraw */
  // glutDisplayFunc(display);
  
  // /* allow the user to quit using the right mouse button menu */
  // g_iMenuId = glutCreateMenu(menufunc);
  // glutSetMenu(g_iMenuId);
  // glutAddMenuEntry("Quit",0);
  // glutAttachMenu(GLUT_RIGHT_BUTTON);
  
  // /* replace with any animate code */
  // glutIdleFunc(doIdle);

  // /* callback for mouse drags */
  // glutMotionFunc(mousedrag);
  // /* callback for idle mouse movement */
  // glutPassiveMotionFunc(mouseidle);
  // /* callback for mouse button changes */
  // glutMouseFunc(mousebutton);

  // /* do initialization */
  // myinit();

  // glutMainLoop();
  // return(0);
}
