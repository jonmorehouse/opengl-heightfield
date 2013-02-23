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

		// initialize our matrix for the final viewing using projection
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();


		// fov angle, aspect ratio = width / height, near z, far z
		gluPerspective(15.0f, windowWidth / windowHeight, 0.01, 500.0);

		// start editing the modelview -- not the scenary
		glMatrixMode(GL_MODELVIEW);

			glLoadIdentity();

		// reset the matrix to a default state before rotating scaling etc
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
			// clear the colors and make the background black
			glClearColor(0.0, 0.0, 0.0, 1.0);
			// glLoadIdentity();//reset the modelview matrix
					
			// reset the rotation of all axes to 0,0,0
			glTranslatef(translation[0], translation[1], translation[2]);

			// http://www.opengl.org/sdk/docs/man2/xhtml/gluLookAt.xml
			// gluLookAt(0,0,0, 10*sin(10), 10*cos(cameraRotation[0]), 0, 0,1,0);

			// gluLookAt(cameraDistance * cos(cameraRotation[1] / 6.28), cameraDistance, cameraDistance * sin(cameraRotation[1] / 6.28), 0, 0, 50, 0, 1, 0);

			// set up the proper scale each time!
			glScalef(scale[0], scale[1], scale[2]);

			// set up the proper rotations
			glRotatef(rotation[0], 1.0, 0.0,0.0);
			glRotatef(rotation[1], 0.0, 1.0,0.0);
			glRotatef(rotation[2], 0.0, 0.0,1.0);

			// draw out each of the polygons needed for this object
			// now need to call the proper draw elements
			displayController();//this is responsible for initializing the correct display methods
		
		// glPopMatrix();
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
		glRotatef(90.0, 1.0, 1.0, 1.0);

		// scale our image for a second
		// glScalef(0.5, 0.5, 0:.5);

		display::drawCube();
		/*
		// checkout our current display type and then call the correct display from the display namespace
		if (displayType == display::GRAYSCALE)
			display::drawGrayscale();

		else if (displayType == display::WIREFRAME)
			display::drawWireframe();

		else if (displayType == display::POINT)
			display::drawPoints();

		else if (displayType == display::COLOR)
			display::drawColor();
		*/
		// initialize any other elements etc	
		glPopMatrix();//stop the z/y reversing here

	}

}