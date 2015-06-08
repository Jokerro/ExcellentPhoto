#include "Rectangle.h"


Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int initialX, int initialY, int initialWidth, int initialHeight){
	x = initialX;
	y = initialY;
	width = initialWidth;
	height = initialHeight;
}

Rectangle::~Rectangle()
{
}

int Rectangle::getX(){
	return x;
}

int Rectangle::getY(){
	return y;
}

int Rectangle::getHeight(){
	return height;
}

int Rectangle::getWidth(){
	return width;
}
