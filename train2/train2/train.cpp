#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int ac, char** av)
{
	Mat img; //������ ĸ���ϰ� ������ ����
	VideoCapture cap("train (1).mp4");//������ ù ������ ĸ��
	Mat img_hsv;//ĸ���� ������ hsv�������� �ٲ� ������ ����

	cap >> img;//ĸ���� ���� ����

	cvtColor(img, img_hsv, COLOR_BGR2HSV);//img�� ���Ե� ���� hsv �������� ��ȯ�� img_hsv�� ����

	Mat mask;//img_hsv���� ������ ���� ���� ���� ����

	Scalar lower_color = Scalar(0, 0, 20);//���� ���� ����
	Scalar upper_color = Scalar(33, 14, 100);//ū ���� ����

	inRange(img_hsv, lower_color, upper_color, mask);//img_hsv�� ���� ������� ū ������� ���� ������ mask�� ����

	imshow("img", img);//���� ���� ���
	imshow("mask", mask);// ���� ������ ���� ���
	
	waitKey(0);
	return 0;
}