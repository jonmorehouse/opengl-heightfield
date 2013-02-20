#include "modules/application.hpp"

namespace application {


	void init() {
		// glutSwapBuffers();
		// idle();		
	}

	// implement idle function -- responsible for working with the image on a consistent basis to continually ensure its integrity
	void idle() {


		g_vLandRotate[0] += 2.0;
		// g_vLandRotate[1] += 1.0;	
		// g_vLandRotate[2] += 2.0;

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
		glPushMatrix();
		glLoadIdentity();
		
		// reset the rotation of all axes to 0,0,0
		glTranslatef(0.0,0.0,0.0);
		glRotatef(20.0, 1.0, 0.0, 0.0);
		glRotatef(20.0, 0.0, 1.0, 0.0);
		glRotatef(20.0, 0.0, 0.0, 1.0);

		glScalef(2.0, 2.0, 2.0);

		// now lets draw our image
		glRasterPos2i(0,0);
		

		glPopMatrix();
		// swap the buffers and bring the second one out from hiding
		glutSwapBuffers();
	}

}