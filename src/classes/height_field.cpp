#include "classes/height_field.hpp"

HeightField::HeightField(unsigned int height, unsigned int width, FieldType type) : height(height), width(width), type(type) {

	// size of the array
	this->size = height * width;// in the future, when we want to work with things other than grayscale images, we can assume that 
	this->data = new unsigned int[size];//this is the data to store the correct points
	this->maxZ = 0;//initialize the maximum z value for now
	this->minZ = 255;//initialize the minimum value for z

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

	// make sure that we don't need to reset the current z value
	if (z > this->maxZ) this->maxZ = z;

	// make sure that this is not less than the current minium z value
	if (z < this->minZ) this->minZ = z;
	
}

// grab a vertex array from a certain position
GLfloat * HeightField::getVertex(unsigned int x, unsigned int y) {

	// grab the actual index using our algorithm
	unsigned int index = this->getIndex(x,y);

	// now return the actual vertex
	return this->vertices[index];

}

unsigned int HeightField::getPoint(unsigned int x, unsigned int y) {

	return this->data[this->getIndex(x,y)];

}

unsigned int HeightField::getHeight() {

	return this->height;
}


unsigned int HeightField::getWidth() {

	return this->width;
}

unsigned int HeightField::getMaxZ() {

	return this->maxZ;

}

unsigned int HeightField::getMinZ() {

	return this->minZ;

}

// get the index for the particular element in the array
inline unsigned int HeightField::getIndex(unsigned int x, unsigned int y) {

	unsigned int index = (y * this->width) + x;

	return index;
}

// get the grayscale color etc
float HeightField::getGrayscaleColor(unsigned int x, unsigned int y) {

	float delta = this->maxZ - this->minZ;


	return float(this->getPoint(x,y)) / delta;
}

// get the rgb color -- this is for color elements etc
void HeightField::getRGBColor(unsigned int x, unsigned int y, float color[3]) {




}