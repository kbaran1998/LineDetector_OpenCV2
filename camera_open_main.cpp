#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;
using namespace cv;



int main(int argc, char ** argv) {
	
	if (argc < 2) {
		cout << "Usage: "<<argv[0]<<" <address_file>.txt" << endl;
		return -1;
	}
	std::ifstream file(argv[1]);

	std::string address_found = "";
	std::string address = "";
	int line_file_read = 0;
	while(std::getline(file, address_found)) {
		std::cout << "Address found: " << address_found << " ;" << "\n";
		if (line_file_read < 1) {
			address = address_found;
			line_file_read++;
		}
	}

	VideoCapture cap;
	
	cap.open(address +"/video?x.mjpeg");
	
	if (!cap.isOpened()) {
		cout << "Could NOT open camera on address: "<< address << endl;
		return -1;
	}

	namedWindow(address ,CV_WINDOW_AUTOSIZE);

	Mat frame, interMediateRes, gray_scale;
	bool exit = false;
	bool canReadFrame;
	while(!exit) {
		
		canReadFrame = cap.read(frame);
		if(!canReadFrame) {
			cout<<"Could not open camera! Lost connection!"<<endl;
           		exit != exit;
       		}

		Canny(frame, interMediateRes, 50, 200, 3);
		cvtColor(interMediateRes, gray_scale, CV_GRAY2BGR);
		vector<Vec4i> lines;
		HoughLinesP(interMediateRes, lines, 1, CV_PI/180, 80, 30, 10);
		for(size_t i = 0; i < lines.size(); i++) {
			line(frame, Point(lines[i][0], lines[i][1]),
			Point(lines[i][2], lines[i][3]), Scalar(0,0,255), 3, 8 );
		}

		rotate(frame, frame, ROTATE_90_CLOCKWISE);
		imshow("ip",frame);

		if(waitKey(30) == 27) {
			cout<<"Bye!" <<endl;
           		exit = true;
		}
	}
	cap.release();
	return 0;
}
