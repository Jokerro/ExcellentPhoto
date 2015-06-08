#pragma once
#include <vector>
#include <ios>
#include "Image.h"

#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\video\video.hpp>.
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

class FaceAnalyzer
{
private:
	std::vector<cv::Rect> facesList;
	std::vector<std::vector<cv::Rect>> listOfEyesList;
	Image image;
	float rating;
	cv::CascadeClassifier faceCascade;
	cv::CascadeClassifier eyesCascade;
	cv::Mat mathImageRepresent;
	cv::Mat grayMathImageRepresent;

	void DetectFaces();
	void DetectEyes(int faceIndex);
	void CalculateRating();
	int CountDetectedEyes();

public:
	FaceAnalyzer();
	~FaceAnalyzer();

	void Analysis();
	float GetRating();
	std::vector<cv::Rect> GetFacesList();
	std::vector<std::vector<cv::Rect>> GetListOfEyesList();
	void SetImage(Image image);
	void SetFaceCascadeClassifier(std::string path);
	void SetEyesCascadeClassifier(std::string path);
};

