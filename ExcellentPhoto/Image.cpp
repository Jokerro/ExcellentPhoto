#include "Image.h"


Image::Image()
{
}

Image::~Image()
{
}

std::string Image::GetPath(){
	return path.string;
}

std::string Image::GetExtension(){
	return extension;
}

Rating Image::GetRating(){
	return rating;
}

void Image::SetPath(boost::filesystem::path path){
	this->path = path;
	this->extension = path.extension;
}

void Image::SetRating(Rating rating){
	this->rating = rating;
}