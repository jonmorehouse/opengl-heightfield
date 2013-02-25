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


	void drawGrayscale() {

		/*
			Declare a bottom color, declare a top color
			We are simply connecting triangles between elements
			Need to scale the z element between all three -- ie: multiply z by a range to find the element
			Need to scale it based upon how far in between we are
		*/	
		// glBegin(GL_TRIANGLE);
		int height = int(heightField->getHeight()),
			width = int(heightField->getWidth());

		float ratio = 255 / (heightField->getMaxZ() - heightField->getMinZ()),
			tempZ,//z for the current point
			tempColor;//color for the individual element

		// for each row, connect the current point to the point below it and the point to the caddy-corner right of it	
		// also need to consider the premises of when we are at the top of the image
		for (int y = height - 2; y >= 1; --y) {

			// loop through the x-axis to draw points
			for (int x = 1; x < width - 2; ++x ) {

				// connect the current point to the left most point
				glVertex3f(x,y,heightField->getPoint(x,y));
				glVertex3f(x-1, y, heightField->getPoint(x-1, y));
				glVertex3f(x-1, y-1, heightField->getPoint(x-1, y-1));

				// 
			}
		}	

	}

	void drawWireframe() {

		// cache height / width etc of this element
		int height = int(heightField->getHeight()),
			width = int(heightField->getWidth());	

		// want to loop through each row, stopping one from the bottom
		for (int y = height -2; y >= 0; --y) {

			// we want to circle for each element in the next for loop and counter-clockwise add our vertices to the point
			for (int x = 0; x < width - 2; ++x ) {

				glColor3f(255,255,255);

				// http://en.wikipedia.org/wiki/Triangle_strip -- for reference on the element
				// 
				glBegin(GL_LINES);
					glVertex3fv(heightField->getVertex(x, y+1));//add the left corner point -- point 1
					glVertex3fv(heightField->getVertex(x, y));//add the current point -- point 2
				glEnd();
				// 
				glBegin(GL_LINES);	
					glVertex3fv(heightField->getVertex(x+1, y+1));//add the next point -- point 3
					glVertex3fv(heightField->getVertex(x+1, y));//add the 4th point -- point 4
				glEnd();

				// 
				glBegin(GL_LINES);
					glVertex3fv(heightField->getVertex(x, y+1));//add the left corner point -- point 1
					glVertex3fv(heightField->getVertex(x+1, y+1));//add the next point -- point 3
				glEnd();

				glBegin(GL_LINES);
					glVertex3fv(heightField->getVertex(x, y));//add the current point -- point 2
					glVertex3fv(heightField->getVertex(x+1, y));//add the 4th point -- point 4
				glEnd();					
			}
		}
	}

	void drawColor() {

		glPushMatrix();
			glColor3f(0.5,0.5,0.5);
			glScalef(10,10,0);
			glBegin(GL_POLYGON);
				
				glVertex3f(0,0,0);
				glVertex3f(5,0,0);
				glVertex3f(5,5,0);
				glVertex3f(0,5,0);

			glEnd();	

		glPopMatrix();


	}

}