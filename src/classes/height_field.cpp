#include "classes/height_field.hpp"

HeightField::HeightField(unsigned int height, unsigned int width, FieldType type) : height(height), width(width), type(type) {

	// size of the array
	this->size = height * width;// in the future, when we want to work with things other than grayscale images, we can assume that 
	this->data = new unsigned int[size];//this is the data to store the correct points
}

HeightField::~HeightField() {

	delete this->data;//release the data!
}

void HeightField::addPoint(unsigned int x, unsigned int y, unsigned int z) {

	this->data[this->getIndex(x,y)] = z;//
}

unsigned int HeightField::getPoint(unsigned int x, unsigned int y, unsigned int z) {

	return this->data[this->getIndex(x,y)];

}

inline unsigned int HeightField::getIndex(unsigned int x, unsigned int y) {

	unsigned int index = (y * this->width) + x;
	
	return index;
}


