#include "classes/height_field.hpp"

HeightField::HeightField(unsigned int height, unsigned int width, FieldType type) : height(height), width(width), type(type) {

	// size of the array
	this->size = height * width;// in the future, when we want to work with things other than grayscale images, we can assume that 
	this->data = new unsigned int[size];//this is the data to store the correct points

	// initialize all elements
	this->vertices = new GLfloat[size][3];

}

HeightField::~HeightField() {

	delete this->data;//release the data!
	delete this->vertices;//release all vertices
}

void HeightField::addPoint(unsigned int x, unsigned int y, unsigned int z) {

	// grab the index according to our algorithm
	unsigned int index = this->getIndex(x,y);

	// store the information in the global array -- useful for height information -- may be used later though
	this->data[index] = z;//

	// store the vertex information!
	this->vertices[index][0] = x;
	this->vertices[index][1] = y;
	this->vertices[index][2] = z;


}

// GLfloat[3] HeightField::getVertex(unsigned int x, unsigned int y) {



// }

unsigned int HeightField::getPoint(unsigned int x, unsigned int y) {

	return this->data[this->getIndex(x,y)];

}

unsigned int HeightField::getHeight() {

	return this->height;


}


unsigned int HeightField::getWidth() {

	return this->width;

}

inline unsigned int HeightField::getIndex(unsigned int x, unsigned int y) {

	unsigned int index = (y * this->width) + x;
	
	return index;
}


