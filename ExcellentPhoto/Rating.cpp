#include "Rating.h"


Rating::Rating()
{
}


Rating::~Rating()
{
}

float Rating::getFaceRating(){
	return faceRating;
}

float Rating::getLigthingRating(){
	return lightingRating;
}

float Rating::getOverallRating(){
	return overalRating;
}

void Rating::setFaceRating(float rating){
	faceRating = rating;
}

void Rating::setLigthingRating(float rating){
	lightingRating = rating;
}

void Rating::setOverallRating(float rating){
	overalRating = rating;
}