
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\video\video.hpp>.
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
	String face_cascade_name = "haarcascade_frontalface_alt.xml";
	String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	if (!face_cascade.load(face_cascade_name)){ printf("--(!)Error loading\n"); return -1; };
	if (!eyes_cascade.load(eyes_cascade_name)){ printf("--(!)Error loading\n"); return -1; };


	// получаем любую подключённую камеру
	CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
	assert(capture);

	
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280); 
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960); 

	// узнаем ширину и высоту кадра
	double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	printf("[i] %.0f x %.0f\n", width, height);

	IplImage* frame = 0;

	cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);

	printf("[i] press Enter for capture image and Esc for quit!\n\n");

	int counter = 0;
	char filename[512];

	while (true){
		// получаем кадр
		frame = cvQueryFrame(capture);




		Mat frame1 = cvQueryFrame(capture);
		std::vector<Rect> faces;
		Mat frame_gray;

		cvtColor(frame1, frame_gray, CV_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);

		//-- Detect faces
		face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(80, 80));

		for (size_t i = 0; i < faces.size(); i++)
		{
			Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
			ellipse(frame1, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

			Mat faceROI = frame_gray(faces[i]);
			std::vector<Rect> eyes;

			//-- In each face, detect eyes
			eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));

			for (size_t j = 0; j < eyes.size(); j++)
			{
				Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				circle(frame1, center, radius, Scalar(255, 0, 0), 4, 8, 0);
			}
		}


		// показываем
		cvShowImage("capture", frame);

		char c = cvWaitKey(33);
		if (c == 27) { // нажата ESC
			break;
		}
		else if (c == 13) { // Enter
			// сохраняем кадр в файл
			sprintf(filename, "Image%d.jpg", counter);
			printf("[i] capture... %s\n", filename);
			cvSaveImage(filename, frame);
			counter++;
		}
	}
	// освобождаем ресурсы
	cvReleaseCapture(&capture);
	cvDestroyWindow("capture");
	return 0;
}