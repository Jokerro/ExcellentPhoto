
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\video\video.hpp>.
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <boost\filesystem.hpp>
#include <boost\property_tree\json_parser.hpp>

using namespace std;
using namespace cv;
using namespace boost::filesystem;

void checkPhoto(const char*, const char*);

int main(int argc, char* argv[])
{
	path mainFolder(argv[0]);

	if (argc >= 3){

		std::vector<string> processingRequests;

		for (int i = 1; i < argc-1; i++){
			string request(argv[i]);
			processingRequests.push_back(request);
		}
		
		path p(argv[argc - 1]);
		try
		{
			if (exists(p))    // does p actually exist?
			{
				if (is_regular_file(p))        // is p a regular file?   
					checkPhoto(p.string().c_str(), mainFolder.branch_path().string().c_str());

				else if (is_directory(p))      // is p a directory?
				{
					cout << p << " is a directory containing:\n";

					typedef vector<path> vec;             // store paths,
					vec v;                                // so we can sort them later

					copy(directory_iterator(p), directory_iterator(), back_inserter(v));

					sort(v.begin(), v.end());             // sort, since directory iteration
					// is not ordered on some file systems
					
					for (vec::const_iterator it(v.begin()); it != v.end(); ++it)
					{

						if (it->extension() == ".jpg")
							checkPhoto(it->string().c_str(), mainFolder.branch_path().string().c_str());
					}
				}

				else
					cout << p << " exists, but is neither a regular file nor a directory\n";
			}
			else
				cout << p << " does not exist\n";
		}

		catch (const filesystem_error& ex)
		{
			cout << ex.what() << '\n';
		}

	}
	system("pause");
	return 0;
}

void checkPhoto(const char* fileName, const char* settingsDir){

	IplImage* image = cvLoadImage(fileName, 1);
	IplImage* src = 0;
	src = cvCloneImage(image);
	//printf("[i] image: %s\n", fileName);
	assert(src != 0);
	
	String face_cascade_name = settingsDir;
	face_cascade_name += "\\haarcascade_frontalface_alt.xml";
	String eyes_cascade_name = settingsDir;
	eyes_cascade_name += "\\parojos.xml";
	std::cout << face_cascade_name;
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;

	if (!face_cascade.load(face_cascade_name)){ printf("--(!)Error face_cascade loading\n"); system("pause"); return; };
	if (!eyes_cascade.load(eyes_cascade_name)){ printf("--(!)Error eyes_cascade loading\n"); system("pause"); return; };
	
	int peoples = 0;
	int closedEyes = 0;

	Mat frame1 = image;
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame1, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(80, 80));
	
	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(frame1, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(0, 0, 0), 4, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;

		//-- In each face, detect eyes
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(35, 16));

		for (size_t j = 0; j < eyes.size(); j++)
		{

			Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
			int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
			circle(frame1, center, radius, Scalar(255, 0, 0), 4, 8, 0);
		}
		if (eyes.size() >= 1){
		 
			peoples++;

		}
		else
		{
			closedEyes++;
		}
	}
	boost::property_tree::ptree json, json2;
	json2.put<std::string>("result", "1");
	json.put("peoples", peoples);
	json.put("closedEyes", closedEyes);
	json.put("mark", peoples-closedEyes/2.0);
	json2.put_child("resultArray", json);
	std::stringstream ss;
	boost::property_tree::write_json(ss, json2);
	cout << ss.str();


	
	cvSaveImage(fileName, image);


	cvReleaseImage(&image);
	cvReleaseImage(&src);

}