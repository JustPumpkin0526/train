#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int ac, char** av)
{
	Mat img;
	VideoCapture cap("train (1).mp4");
	Mat img_hsv;

	cap >> img;

	cvtColor(img, img_hsv, COLOR_BGR2HSV);

	Mat mask;

	Scalar lower_color = Scalar(0, 0, 20);
	Scalar upper_color = Scalar(33, 14, 100);

	inRange(img_hsv, lower_color, upper_color, mask);

	imshow("img", img);
	imshow("mask", mask);
	waitKey(0);
	return 0;
}