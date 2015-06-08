#include "Rating.h"


Rating::Rating()
{
}


Rating::~Rating()
{
}

float Rating::GetFaceRating(){
	return faceRating;
}

float Rating::GetLigthingRating(){
	return lightingRating;
}

float Rating::GetOverallRating(){
	return overalRating;
}

void Rating::SetFaceRating(float rating){
	faceRating = rating;
}

void Rating::SetLigthingRating(float rating){
	lightingRating = rating;
}

void Rating::SetOverallRating(float rating){
	overalRating = rating;
}