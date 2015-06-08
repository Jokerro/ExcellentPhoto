#include "FaceAnalyzer.h"


FaceAnalyzer::FaceAnalyzer()
{
	faceCascade.load("haarcascade_frontalface_alt.xml");
	eyesCascade.load("parojos.xml");
	rating = 0;
}

FaceAnalyzer::~FaceAnalyzer()
{
}

float FaceAnalyzer::GetRating(){
	return this->rating;
}

std::vector<cv::Rect> FaceAnalyzer::GetFacesList(){
	return this->facesList;
}

std::vector<std::vector<cv::Rect>> FaceAnalyzer::GetListOfEyesList(){
	return this->listOfEyesList;
}

void FaceAnalyzer::SetImage(Image image){
	this->image = image;
}

void FaceAnalyzer::SetFaceCascadeClassifier(std::string path){
	if (!faceCascade.load(path)){
		throw &std::ios::fail;
	}
}

void FaceAnalyzer::SetEyesCascadeClassifier(std::string path){
	if (!eyesCascade.load(path)){
		throw &std::ios::fail;
	}
}

void FaceAnalyzer::Analysis(){
	using namespace cv;

	std::string imagePath = image.GetPath();
	IplImage* image = cvLoadImage(imagePath.c_str(), 1);
	if (image == 0){
		throw &std::ios::fail;
	}
	mathImageRepresent = image;
	cvtColor(mathImageRepresent, grayMathImageRepresent, CV_BGR2GRAY);
	equalizeHist(grayMathImageRepresent, grayMathImageRepresent);
	DetectFaces();
	cvSaveImage(imagePath.c_str(), image);
	cvReleaseImage(&image);
	CalculateRating();
}


void FaceAnalyzer::DetectFaces(){
	using namespace cv;
	
	faceCascade.detectMultiScale(grayMathImageRepresent, GetFacesList(), 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(80, 80));
	for (size_t i = 0; i < facesList.size(); i++){
		Point center(facesList[i].x + facesList[i].width*0.5, facesList[i].y + facesList[i].height*0.5);
		ellipse(mathImageRepresent, center, Size(facesList[i].width*0.5, facesList[i].height*0.5), 0, 0, 360, Scalar(0, 0, 0), 4, 8, 0);
		DetectEyes(i);
	}
}

void FaceAnalyzer::DetectEyes(int faceIndex){
	cv::Mat faceROI = grayMathImageRepresent(facesList[faceIndex]);
	std::vector<cv::Rect> eyesList;
	eyesCascade.detectMultiScale(faceROI, eyesList, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(35, 16));
	for (size_t j = 0; j < eyesList.size(); j++){
		cv::Point center(facesList[faceIndex].x + eyesList[j].x + eyesList[j].width*0.5, facesList[faceIndex].y + eyesList[j].y + eyesList[j].height*0.5);
		int radius = cvRound((eyesList[j].width + eyesList[j].height)*0.25);
		circle(mathImageRepresent, center, radius, cv::Scalar(255, 0, 0), 4, 8, 0);
	}
	this->listOfEyesList.push_back(eyesList);
}

void FaceAnalyzer::CalculateRating(){
	int facesCount = 1;
	int eyesCount = CountDetectedEyes();
	this->rating = (float)facesCount / (float)eyesCount;
}

int FaceAnalyzer::CountDetectedEyes(){
	int result = 0;
	for each (std::vector<cv::Rect> eyesList in this->listOfEyesList){
		result += eyesList.size();
	}
	return result;
}