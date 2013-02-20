#include "modules/display.hpp"

namespace display {


	// draw points instead of lines. These can be edited later to make them smoother etc
	void drawPoints() {

		// initialize points
		glBegin(GL_POINTS);	

		glPointSize(30.0);//set the point size for each dot drawn

		// loop through each element and draw the correct point
		for (int x = int(heightField->getWidth()) - 1; x >= 0; --x) {

			// loop through each y value
			for (int y = int(heightField->getHeight()) -1; y >= 0; --y) {

				// grab the vertice and draw it on screen	
				glVertex3fv(heightField->getVertex(x,y));//draw the proper vertex on screen	
			}
		} //end of the y for loop

		glEnd();//end the points drawing
	}


	void drawGrayscale() {



	}

	void drawWireframe() {

		// want to display by strip here to allow for quick processing of each of the polygons that we need
		// allow a quick strip of polygons to be drawn
		glBegin(GL_TRIANGLE_STRIP);	

		// set the triangle strip up for front-facing drawing to allow for clockwise
		glFrontFace(GL_CW);
		// want to loop through each row, stopping one from the bottom
		for (int y = int(heightField->getHeight()) -1; y >= 1; y--) {

			// we want to circle for each element in the next for loop and counter-clockwise add our vertices to the point


		}



		glEnd();

	}

}