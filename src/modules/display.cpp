#include "modules/display.hpp"

namespace display {


	// draw points instead of lines. These can be edited later to make them smoother etc
	void drawPoints() {

		// initialize points
		glBegin(GL_POINTS);	
		// initialize the point size etc	
		glPointSize(30.0);//set the point size for each dot drawn

		// cache a color array
		float color;

		// loop through each element and draw the correct point
		for (int x = int(heightField->getWidth()) - 1; x >= 0; --x) {

			// loop through each y value
			for (int y = int(heightField->getHeight()) -1; y >= 0; --y) {

				// grab the proper color from the heightfield
				color = heightField->getGrayscaleColor(x,y);

				// now that the color has been determined, draw it out
				glColor3f(color, color, color);

				// grab the vertice and draw it on screen	
				glVertex3fv(heightField->getVertex(x,y));//draw the proper vertex on screen	
			}
		} //end of the y for loop

		glEnd();//end the points drawing
	}

	void drawWireframe() {

		// cache height / width etc of this element
		int height = int(heightField->getHeight()),
			width = int(heightField->getWidth());	


		// make sure that we are drawing a white wireframe
		glColor3f(1,1,1);

		// want to loop through each row, stopping one from the bottom
		for (int y = height - WIREFRAME_DENSITY -1; y >= WIREFRAME_DENSITY; y = y-WIREFRAME_DENSITY ) {
			// we want to circle for each element in the next for loop and counter-clockwise add our vertices to the point
			for (int x = WIREFRAME_DENSITY + 1; x < width - WIREFRAME_DENSITY; x = x + WIREFRAME_DENSITY) {

				// draw out the top loops
				glBegin(GL_LINE_LOOP);

					glVertex3f(x,y,heightField->getPoint(x,y));
					glVertex3f(x-WIREFRAME_DENSITY, y, heightField->getPoint(x-WIREFRAME_DENSITY,y));
					glVertex3f(x-WIREFRAME_DENSITY, y+ WIREFRAME_DENSITY, heightField->getPoint(x-WIREFRAME_DENSITY,y+WIREFRAME_DENSITY));	

				glEnd();
			}
		}
	}

	void grayscaleWorker(int x, int y) {

		// responsible for drawing out and initializing an individual point for this drawing etc
		int z = heightField->getPoint(x,y);
		float color = heightField->getGrayscaleColor(x,y);

		// actually draw out the element and change the points accordingly
		glColor3f(color, color, color);
		glVertex3f(x,y,z);
	}	

	void drawGrayscale() {

		// cache the height / width elements for this particular looping system
		int height = heightField->getHeight(),
			width = heightField->getWidth(),
			tempZ;//this is a temporary z to help save heightfield accesses

		// cache a color variable so that we can dynamically change the vertex each time
		float tempColor;

		// start a matrix to help us if we need any transformations
		glPushMatrix();

			for (int y = height - 2; y >= 1; --y) {

				for (int x = 1; x < width - 2; ++x) {

					// initialize the drawing of the top triangle strip
					glBegin(GL_TRIANGLE_STRIP);

						// initialize the drawing of each of the different elements
						grayscaleWorker(x-1, y);
						grayscaleWorker(x-1, y+1);
						grayscaleWorker(x,y);
						grayscaleWorker(x,y+1);
						grayscaleWorker(x+1, y+1);
						grayscaleWorker(x+1, y);

					glEnd();

					// initialize the drawing of the bottom strip
					glBegin(GL_TRIANGLE_STRIP);

						grayscaleWorker(x-1, y);
						grayscaleWorker(x-1, y-1);
						grayscaleWorker(x,y);
						grayscaleWorker(x,y-1);
						grayscaleWorker(x+1, y-1);
						grayscaleWorker(x+1, y);

					glEnd();
				}	
			}

		glPopMatrix();

	}

	void drawColor() {

		// only for temporary testing etc for the drawing elements ettcc..

		// will be responsible for drawing the element in colors etc

	}
}