#include "ImageAnalyzer.h"


ImageAnalyzer::ImageAnalyzer()
{
}

ImageAnalyzer::~ImageAnalyzer()
{
}

void ImageAnalyzer::AnalysisImage(){

}

void ImageAnalyzer::ColorAnalysis(){

}

void ImageAnalyzer::FaceAnalysis(){

}

Image ImageAnalyzer::GetImage(){
	return image;
}

void ImageAnalyzer::SetImage(Image image){
	this->image = image;
}