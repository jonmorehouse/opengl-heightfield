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

		// want to loop through and draw each triangle with vertices
		// we want to use the z-coordinate to get the proper color
		glBegin(GL_TRIANGLE_STRIP);
		
		// cache the unsigned integers of the heightfield dimensions as unsigned integers because its not good practice to loop through and unsigned integer
		int height = int(heightField->getHeight()),
			width = int(heightField->getWidth());

		// loop through starting at the top row
		for (int y = height - 2; y >= 0; --y) {

			// will go through and set the color of each vertex before drawing it out
			// the color on the height field will be representative of its color intensity / z value
			for (int x = 0; x < width - 2; ++x ) {

				// set
				glVertex3fv(heightField->getVertex(x, y+1));//add the left corner point -- point 1
				glVertex3fv(heightField->getVertex(x, y));//add the current point -- point 2
				glVertex3fv(heightField->getVertex(x+1, y+1));//add the next point -- point 3
				glVertex3fv(heightField->getVertex(x+1, y));//add the 4th point -- point 4
			}
		}

		glEnd();	

	}

	void drawWireframe() {

		// use gl_line_strip here instead of this....
		// want to display by strip here to allow for quick processing of each of the polygons that we need
		// allow a quick strip of polygons to be drawn
		glBegin(GL_TRIANGLE_STRIP);	
		// set the triangle strip up for front-facing drawing to allow for clockwise
		glPolygonMode( GL_FRONT, GL_LINE );

		// cache height / width etc of this element
		int height = int(heightField->getHeight()),
			width = int(heightField->getWidth());	

		// want to loop through each row, stopping one from the bottom
		for (int y = height -2; y >= 0; --y) {

			// we want to circle for each element in the next for loop and counter-clockwise add our vertices to the point
			for (int x = 0; x < width - 2; ++x ) {

				// http://en.wikipedia.org/wiki/Triangle_strip -- for reference on the element
				glVertex3fv(heightField->getVertex(x, y+1));//add the left corner point -- point 1
				glVertex3fv(heightField->getVertex(x, y));//add the current point -- point 2
				glVertex3fv(heightField->getVertex(x+1, y+1));//add the next point -- point 3
				glVertex3fv(heightField->getVertex(x+1, y));//add the 4th point -- point 4
			}
		}

		// end the triangle strip	
		glEnd();
		glDisable(GL_POLYGON_OFFSET_LINE);
	}

	void drawColor() {

		// this is just a test element for now
		glBegin(GL_TRIANGLE_STRIP);

		glPolygonMode( GL_FRONT, GL_LINE );
		glPolygonMode(GL_BACK, GL_LINE);
		glDisable( GL_CULL_FACE );
		glColor3f(255.0, 255.0, 255.0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 4.0);
		glVertex3f(4.0, 0.0, 4.0);
		glVertex3f(4.0, 0.0, 0.0);
		glVertex3f(0.0,0.0,0.0);

		glEnd();

	}

}