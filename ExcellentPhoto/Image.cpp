#include "Image.h"


Image::Image()
{
}

Image::~Image()
{
}

std::string Image::getPath(){
	return path;
}

std::string Image::getExtension(){
	return extension;
}

Rating Image::getRating(){
	return rating;
}

void Image::setPath(std::string path){
	this->path = path;
}

void Image::setRating(Rating rating){
	this->rating = rating;
}