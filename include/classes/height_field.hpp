/*
	Height Field data structure
	The purpose of this class is to help keep our height field data seperate from any input images
	For now, it only supports GRAYSCALE Images but in the future, we will help it support images that can be different types	
	The goal of this is to help with the maunsigned inteneance and creation of height fields from any type of image input
	When drawing, the goal is to create an object like this and loop through both x / y and create triangles from these
	By getting the Z from this object
	This object can be optimized to store images later on
*/
#ifndef HEIGHT_FIELD_HPP
#define HEIGHT_FIELD_HPP

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

typedef enum {

	GRAYSCALE

} FieldType;

class HeightField {

	public: // constructors / destructors
		HeightField(unsigned int height, unsigned int width, FieldType type);
		~HeightField();		

	public: //access functions
		void addPoint(unsigned int x, unsigned int y, unsigned int z);//add a point to this height map
		unsigned int getPoint(unsigned int x, unsigned int y);//return a single point's z value
		unsigned int getHeight();//returns the height of the image
		unsigned int getWidth();//returns the width
		unsigned int getMaxZ();//returns the maxZ
		unsigned int getMinZ();//returns the minZ
		float getGrayscaleRatio();//returns the grayscale ratio for the color elements
		GLfloat * getVertex(unsigned int x, unsigned int y);//grab a particular element

	private://variables

		FieldType type;
		unsigned int width;//width of the element
		unsigned int height;//height of the map
		unsigned int maxZ;//maximum z field
		unsigned int minZ;//minimum z field 
		unsigned int size;//this is the size of the array that we are working with		
		unsigned int * data;//this is the data that we are storing for this particular image
		GLfloat (*vertices)[3];//this is an array of all the vertices we need for now

	private://unsigned ints

		// allow for quick index finding. This will make it easier to map our data structures to future elements
		unsigned int getIndex(unsigned int x, unsigned int y);//get the proper index for this data structure


};

#endif