#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int ac, char** av)
{
	Mat img; //영상을 캡쳐하고 대입할 변수
	VideoCapture cap("train (1).mp4");//영상의 첫 프레임 캡쳐
	Mat img_hsv;//캡쳐한 영상을 hsv색상으로 바꿔 대입할 변수

	cap >> img;//캡쳐한 영상 대입

	cvtColor(img, img_hsv, COLOR_BGR2HSV);//img에 대입된 영상 hsv 색상으로 전환해 img_hsv로 대입

	Mat mask;//img_hsv에서 추출한 색상 영상 대입 변수

	Scalar lower_color = Scalar(0, 0, 20);//작은 색상 범위
	Scalar upper_color = Scalar(33, 14, 100);//큰 색상 범위

	inRange(img_hsv, lower_color, upper_color, mask);//img_hsv에 작은 색상부터 큰 색상까지 색을 추출해 mask에 대입

	imshow("img", img);//원본 영상 출력
	imshow("mask", mask);// 색상 추출한 영상 출력
	
	waitKey(0);
	return 0;
}