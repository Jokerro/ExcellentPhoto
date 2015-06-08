#pragma once
#include <iostream>
#include "Rating.h"

class Image
{
private:
	std::string path;
	std::string extension;
	Rating rating;

public:
	Image();
	~Image();

	std::string getPath();
	std::string getExtension();
	Rating getRating();
	void setPath(std::string imagePath);
	void setRating(Rating imageRating);
};

