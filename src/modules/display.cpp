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




	}

}