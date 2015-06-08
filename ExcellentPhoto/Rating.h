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

	float GetLigthingRating();
	float GetFaceRating();
	float GetOverallRating();

	void SetLigthingRating(float rating);
	void SetFaceRating(float rating);
	void SetOverallRating(float rating);
};

