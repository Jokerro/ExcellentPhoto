#pragma once
class Rectangle
{
private:
	int x;
	int y;
	int width;
	int height;

public:
	Rectangle();
	Rectangle(int initialX, int initialY, int initialWidth, int initialHeight);
	~Rectangle();

	int getX();
	int getY();
	int getWidth();
	int getHeight();
};

