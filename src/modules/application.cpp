#include "modules/application.hpp"

namespace application {

	void init() {

		//glut initialization data goes here
		// anything that needs to be initialized in the main loop can be inserted here to help offset application load
	}

	// implement idle function -- responsible for working with the image on a consistent basis to continually ensure its integrity
	void idle() {

		// initialize other idle functionality here -- this could be a casual rotation or some sort of randomization of the translations etc
		glutPostRedisplay();//run the display segment again to update any changes that we may have
	}

	// display is for drawing out the elements using our scaled frame etc
	void display() {

		// rotate, scaling and translation should take place before this code in the future
		// draw a quick cube around the origin of the screen
		glViewport(0,0, 600, 600);	

		// start editing the modelview -- not the scenary
		glMatrixMode(GL_MODELVIEW);

			glLoadIdentity();

			// reset the matrix to a default state before rotating scaling etc
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
			// clear the colors and make the background black
			glClearColor(0.0, 0.0, 0.0, 1.0);

			// reset the rotation of all axes to 0,0,0
			glTranslatef(translation[0], translation[1], translation[2]);

			// set up the proper scale each time!
			glScalef(scale[0], scale[1], scale[2]);


			// draw out each of the polygons needed for this object
			// now need to call the proper draw elements
			displayController();//this is responsible for initializing the correct display methods
					
		// initialize the gl_projection matrix -- this is useful for setting up perspective etc ...
		// initialize our matrix for the final viewing using projection ... 
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// fov angle, aspect ratio = width / height, near z, far z
		gluPerspective(10.0f, windowWidth / windowHeight, 0.01, 1000.0);

		// swap the buffers and bring the second one out from hiding
		glutSwapBuffers();

	}

	// display controller is where special cases in the future can go
	void displayController() {

		// push a matrix to rotate our element so that z will actually be drawn as y so we don't have to worry about this!
		glPushMatrix();

		// by rotating around the x axis by 90.0
		// when we draw a z value, it will look like a y value and we don't need to worry about that particular case
		// multiply the current matrix by 90, but only around the x axis
		glTranslatef(0,0,-100);
		glScalef(0.1,0.1,0.1);

		// set up the proper rotations
		glRotatef(rotation[0], 1.0, 0.0,0.0);
		glRotatef(rotation[1], 0.0, 1.0,0.0);
		glRotatef(rotation[2], 0.0, 0.0,1.0);
		
		// scale our image for a second
		// checkout our current display type and then call the correct display from the display namespace
		if (displayType == display::GRAYSCALE)
			display::drawGrayscale();

		else if (displayType == display::WIREFRAME)
			display::drawWireframe();

		else if (displayType == display::POINT)
			display::drawPoints();

		else if (displayType == display::COLOR)
			display::drawColor();

		// initialize any other elements etc	
		glPopMatrix();//stop the z/y reversing here

	}

}