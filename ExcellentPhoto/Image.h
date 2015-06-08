#pragma once
#include <iostream>
#include <boost\filesystem.hpp>
#include "Rating.h"

class Image
{
private:
	boost::filesystem::path path;
	std::string extension;
	Rating rating;

public:
	Image();
	~Image();

	std::string GetPath();
	std::string GetExtension();
	Rating GetRating();
	void SetPath(boost::filesystem::path imagePath);
	void SetRating(Rating imageRating);
};

