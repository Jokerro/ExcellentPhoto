#pragma once
#include "Image.h"

class ColorAnalyzer
{
private:
	int colorBalance;
	float rating;
	Image image;

public:
	ColorAnalyzer();
	~ColorAnalyzer();

	void Analysis();
	float GetRating();
	int GetColorBalance();
	void SetImage(Image image);
};

