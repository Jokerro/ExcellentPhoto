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
	faceAnalyzer.SetImage(this->image);
	faceAnalyzer.Analysis();
	float faceAnalyzerRating = faceAnalyzer.GetRating();
	Rating imageRating;
	imageRating.SetFaceRating(faceAnalyzerRating);
	imageRating.SetOverallRating(faceAnalyzerRating);
	this->image.SetRating(imageRating);
}

Image ImageAnalyzer::GetImage(){
	return image;
}

void ImageAnalyzer::SetImage(Image image){
	this->image = image;
}

void ImageAnalyzer::SetCustomFaceCascadeClassifier(std::string cascadeClassifierPath){
	faceAnalyzer.SetFaceCascadeClassifier(cascadeClassifierPath);
}

void ImageAnalyzer::SetCustomEyesCascadeClassifier(std::string cascadeClassifierPath){
	faceAnalyzer.SetEyesCascadeClassifier(cascadeClassifierPath);
}