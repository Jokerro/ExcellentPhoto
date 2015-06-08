#pragma once
#include <vector>
#include "Rectangle.h"
#include "Image.h"

class FaceAnalyzer
{
private:
	std::vector<Rectangle> facesList;
	std::vector<Rectangle> eyesList;
	Image image;
	float rating;

public:
	FaceAnalyzer();
	~FaceAnalyzer();

	void Analysis();
	float GetRating();
	std::vector<Rectangle> GetFacesList();
	std::vector<Rectangle> GetEyesList();
	void GetImage(Image image);
};

