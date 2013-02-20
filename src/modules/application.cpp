#include "modules/application.hpp"

namespace application {

	void init() {
		// glutSwapBuffers();
		// idle();		
	}

	// implement idle function -- responsible for working with the image on a consistent basis to continually ensure its integrity
	void idle() {

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

		// initialize our perspective
		// fov angle, aspect ratio = width / height, near z, far z
		// gluPerspective(15.0f, 1.0f, 1.0f, 300.0f);
		gluPerspective(15.0f, windowWidth / windowHeight, 0.01, 1000.0);

		// Had some problems with the code above making my objects disappear
		// note the 45.0 degrees is the angularion == which helps with the perspective to hit the eyes ...
		// the second parameter is the aspect ratio which is the pixel dimensions
		// the third parameter is the near z element. This is where the z viewport starts
			// since the viewport is relative to this, transformations should be reversed. IE: to show up, the z cannot be > -1.0
			// if the object is < -10.0 it will also fall off the back of the element


		// reset the matrix to a default state before rotating scaling etc
		glMatrixMode(GL_MODELVIEW);	
		glPushMatrix();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
			// clear the colors and make the background black
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glLoadIdentity();//reset the modelview matrix
				
			// reset the rotation of all axes to 0,0,0
			glTranslatef(translation[0], translation[1], translation[2]);

			// set up the proper rotations
			glRotatef(rotation[0], 1.0, 0.0,0.0);
			glRotatef(rotation[1], 0.0, 1.0,0.0);
			glRotatef(rotation[2], 0.0, 0.0,1.0);

			// set up the proper scale each time!
			glScalef(scale[0], scale[1], scale[2]);

			// draw out each of the polygons needed for this object
			// drawPolygons();//loops through and draws out each polygons		
			drawPolygon(2,2);

		glPopMatrix();
		// swap the buffers and bring the second one out from hiding
		glutSwapBuffers();
	}

	// responsible for calling the correct function given input based upon the current displayType;
	// responsible for drawing the polygons for each individual piece of our application
	void drawPolygons() {

		for (int x = 1, xMax = heightField->getWidth() -1; x < xMax; x++) {

			for (int y = 1, yMax = heightField->getHeight() -1; y < yMax; y++)	 {

				// draw out the proper polygon for this particular point
				drawPolygon(x, y);
			}
		}
	}

	// draw polygon assumes that there is a left point, and a right point!
	void drawPolygon(unsigned int x, unsigned int y) {

		GLfloat color[3] = {1.0,1.0, 1.0};
		// need to add in the individual vertices for this object
			
		// draw 1->2 vertex / plane
		glBegin(GL_POLYGON);

			glColor3f(0.5, 0.5, 0.5);
			// glVertex3f(x, y-1, heightField->getPoint(x, y-1));
			// glVertex3f(x, y, heightField->getPoint(x, y));
			// glVertex3f(x-1, y, heightField->getPoint(x-1, y));

			glVertex3f(-10,-10,0);
			glVertex3f(-10, 10, 0);
			glVertex3f(10, 10, 0);
			glVertex3f(10, -10, 0);

		glEnd();

		glBegin(GL_POLYGON);

			glColor3f(5, 5, 5);



			glVertex3f(-10, -10, 0);
			glVertex3f(-5, -5, 10);
			glVertex3f(10,10,0);

		glEnd();
	}


}