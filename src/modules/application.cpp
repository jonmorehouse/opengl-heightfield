#include "modules/application.hpp"

namespace application {

	void init() {

		// clear gl colors on the screen to black
		glClearColor(0.0, 0.0, 0.0, 0.0);

	}

	// implement idle function -- responsible for working with the image on a consistent basis to continually ensure its integrity
	void idle() {

		// force refresh of the screen
		glutPostRedisplay();	

	}	


	// display is for drawing out the elements using our scaled frame etc
	void display() {

		// rotate, scaling and translation should take place before this code in the future
		// draw a quick cube around the origin of the screen
		glBegin(GL_POLYGON);

		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.5, -0.5, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(0.5, -0.5, 0.0);

		glEnd();

	}

}