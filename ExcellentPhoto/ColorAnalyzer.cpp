#include "ColorAnalyzer.h"


ColorAnalyzer::ColorAnalyzer()
{
}

ColorAnalyzer::~ColorAnalyzer()
{
}

void ColorAnalyzer::Analysis(){

}

float ColorAnalyzer::GetRating(){
	return rating;
}

int ColorAnalyzer::GetColorBalance(){
	return colorBalance;
}

void ColorAnalyzer::GetImage(Image image){
	this->image = image;
}