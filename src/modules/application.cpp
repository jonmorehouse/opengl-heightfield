#include "modules/application.hpp"

namespace application {

	void init() {


		idle();		
	}

	// implement idle function -- responsible for working with the image on a consistent basis to continually ensure its integrity
	void idle() {

		// initialize the most basic image
		for (int y = currentImage->ny; y >= 0; y--) {

			// draw out each row of pixels
			glDrawPixels(currentImage->nx, currentImage->ny, GL_RGB, GL_UNSIGNED_BYTE, currentImage->pix);	
		}	
	}	


	// display is for drawing out the elements using our scaled frame etc
	void display() {

		// rotate, scaling and translation should take place before this code in the future
		// draw a quick cube around the origin of the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
		glClearColor(000.0, 0.0, 0.0, 1.0);

		init();

		glutSwapBuffers();
	}

}