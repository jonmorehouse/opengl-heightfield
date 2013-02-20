#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

// declare some global variables 
Pic * currentImage = NULL;//null until defined later in our function

// frame variables
float g_vLandRotate[3] = {1.0, 0.0, 0.0}, 
  g_vLandTranslate[3] = {0.0, 0.0, 0.0},
  g_vLandScale[3] = {0.0, 0.0, 0.0};

// window variables etc
int windowHeight = 600, 
  windowWidth = 600;


// include application code base / namespaces
#include "modules/interaction.hpp"
#include "modules/image.hpp"
#include "modules/application.hpp"

int main (int argc, char ** argv) {

  if (argc < 2) {

    // Print error message
    printf("Usage: %s example.jpg\n", argv[0]);
    exit(1);

  }

  // create a new *pic with allocated elements
  currentImage = jpeg_read(argv[1], NULL);
  
  // check the validity of the image
  if (!currentImage) {

    printf("Error reading %s.\n", argv[1]);
    exit(1);
  }

  // set up the initializer function for glut
  glutInit(&argc, argv);

  // initialize double buffer element
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

  // set up the window size 
  glutInitWindowSize(windowWidth, windowHeight);

  // set the window position
  glutInitWindowPosition(100, 100);
  // name the window etc ... 
  glutCreateWindow("Assignment 1: Height Field");

  // set up the main display function
  glutDisplayFunc(application::display);

  // set the various callbacks for the interaction with opengl
  glutIdleFunc(application::idle);
  // glutMotionFunc(interaction::mousedrag);
  // glutPassiveMotionFunc(interaction::mouseidle);
  // glutMouseFunc(interaction::mousebutton);

  glEnable(GL_DEPTH_TEST);
  // now enter the main glut loop 
  glutMainLoop();

  // 
  // image::saveScreenshot("./test.jpf");

}
