#include "FaceAnalyzer.h"


FaceAnalyzer::FaceAnalyzer()
{
}

FaceAnalyzer::~FaceAnalyzer()
{
}

void FaceAnalyzer::Analysis(){

}

float FaceAnalyzer::GetRating(){
	return rating;
}

std::vector<Rectangle> FaceAnalyzer::GetFacesList(){
	return facesList;
}

std::vector<Rectangle> FaceAnalyzer::GetEyesList(){
	return eyesList;
}

void FaceAnalyzer::SetImage(Image image){
	this->image = image;
}