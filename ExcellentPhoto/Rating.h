#pragma once
class Rating
{

private:
	float lightingRating;
	float faceRating;
	float overalRating;

public:
	Rating();
	~Rating();

	float getLigthingRating();
	float getFaceRating();
	float getOverallRating();

	void setLigthingRating(float rating);
	void setFaceRating(float rating);
	void setOverallRating(float rating);
};

