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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
		// clear the colors and make the background black
		glClearColor(0.0, 0.0, 0.0, 1.0);

		// reset the matrix to a default state before rotating scaling etc
		glMatrixMode(GL_PROJECTION);	
		glPushMatrix();

			// clear teh screen
			glLoadIdentity();
			
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

			// glScalef(scale[0], scale[1], scale[2]);
	
			glColor3f(0.5, 0.5, 0.5);
			// glVertex3f(x, y-1, heightField->getPoint(x, y-1));
			// glVertex3f(x, y, heightField->getPoint(x, y));
			// glVertex3f(x-1, y, heightField->getPoint(x-1, y));

			glVertex3f(0,0,0);
			glVertex3f(0,4.0/100,0);
			glVertex3f(4.0/100,4.0/100,0);
			glVertex3f(4.0/100,0,0);

		glEnd();
	}

	// initialize the view perspective
	void viewPerspective() {

		float ymax, xmax;
		float temp, temp2, temp3, temp4;
		ymax = znear * tanf(15.0 * 3.14 / 360.0);
		//ymin = -ymax;
		//xmin = -ymax * aspectRatio;
		xmax = ymax * aspectRatio;
		glhFrustumf2(matrix, -xmax, xmax, -ymax, ymax, znear, zfar);

	}

}