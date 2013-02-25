#include "classes/height_field.hpp" //responsible for handling all data that needs to persist throughout the application
#include "modules/image.hpp" //useful for user interaction etc
#include "modules/interaction.hpp" //responsible for handling user interaction
#include "modules/application.hpp" // responsible for controlling the drawing of elements 
#include "modules/display.hpp" //responsible for drawing out the actual map elements

// include application code base / namespaces
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

// rotate the object rectangle -- this is done after the camera look up
float rotation[3] = {0.0, 0.0, 0.0}, 
  // current translation of the current object
  translation[3] = {0.0, 0.0, -300.0},
  // scale of the actual object
  scale[3] = {0.9, 0.9, 1},
  // this is the scalar that we will multiply by the rotation element
  cameraDistance = 50.0,
  // we want to be able to rotate the camera around the x axis to go above and beyond or around the y element
  cameraRotation[2] = {0.0, 0.0};


// window variables etc
int windowHeight = 600, 
  windowWidth = 600;

// wireframe density
const int WIREFRAME_DENSITY = 10;//helps for wireframe densitys to ensure that we are not drawing a blob of lines

// display type is changed through the interaction namespace and is useful for helping us describe what type of displaying we want
display::DisplayType displayType = display::GRAYSCALE;//initialize the type of application we are going to draw out

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

  glutMotionFunc(interaction::mousedrag);
  glutPassiveMotionFunc(interaction::mouseidle);
  glutMouseFunc(interaction::mousebutton);

  // enable 3d buffering / z-buffer
  glEnable(GL_DEPTH_TEST);
  // enable point size for this particular program
  // glEnable(GL_PROGRAM_POINT_SIZE);

  // going to assume that we are using the default reshape function
  // just need our viewport set to 0,0,w,h
  // now enter the main glut loop 
  glutMainLoop();
     
  // image::saveScreenshot("./test.jpf");

}