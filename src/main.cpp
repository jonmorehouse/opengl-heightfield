#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

// frame variables
float rotation[3] = {1.0, 0.0, 0.0}, 
  translation[3] = {0.0, 0.0, 0.0},
  scale[3] = {0.9, 0.9, 0.9};

// window variables etc
int windowHeight = 600, 
  windowWidth = 600;

// include application code base / namespaces
#include "modules/interaction.hpp"
#include "modules/image.hpp"
#include "modules/application.hpp"
#include "classes/height_field.hpp"

// height field holder for this application
HeightField * heightField = NULL;

// grab the jpeg data from a file and then initialize a height field object
// this can be optimized later to help with other file types
void heightFieldInit(char * filename) {

  // initialize images etc
  Pic * image = jpeg_read(filename, NULL);

  // ensure that the file could be read etc
  if (!image) {

    printf("Error reading %s.\n", filename);
    exit(1);

  }

  // initialize all of our points etc
  unsigned int height = image->nx,
    width = image->ny,
    intensity;//current pixel intensity from 0 to 256

  // set up the height field object for global use
  heightField = new HeightField(height, width, GRAYSCALE);

  // need to add all of the proper points from this point forward 
  for (unsigned int y = 0; y < height; y++) {

    for (unsigned int x = 0; x < width; x++) {

      // grab the pixel intensity for each piece of the image 
      intensity = image->pix[y * width * 1 + x];

      // add the proper point into the height field object
      heightField->addPoint(x, y, intensity);
    }
  }

  delete image;
}

int main (int argc, char ** argv) {

  if (argc < 2) {

    // Print error message
    printf("Usage: %s example.jpg\n", argv[0]);
    exit(1);

  }

  heightFieldInit(argv[1]);//initialize the image etc

  // lets initialize the heightfield object to help with our data



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
  glutSpecialFunc(interaction::keyPress);//enable the keypress handling

  // glutMotionFunc(interaction::mousedrag);
  // glutPassiveMotionFunc(interaction::mouseidle);
  // glutMouseFunc(interaction::mousebutton);

  // enable 3d buffering / z-buffer
  glEnable(GL_DEPTH_TEST);
  // now enter the main glut loop 
  glutMainLoop();

     
  // image::saveScreenshot("./test.jpf");

}