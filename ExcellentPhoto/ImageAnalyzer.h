#pragma once
#include "ColorAnalyzer.h"
#include "FaceAnalyzer.h"
#include "Image.h"

class ImageAnalyzer
{
private:
	Image image;
	ColorAnalyzer colorAnalyzer;
	FaceAnalyzer faceAnalyzer;

public:
	ImageAnalyzer();
	~ImageAnalyzer();

	void AnalysisImage();
	void ColorAnalysis();
	void FaceAnalysis();
	Image GetImage();
	void SetImage(Image image);
};

