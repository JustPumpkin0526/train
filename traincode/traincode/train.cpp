#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap("train (2).mp4");

    Mat img;
    Mat gray_img;
    cap >> img;

    cvtColor(img, gray_img, COLOR_RGB2GRAY);

    Mat img_gaus;
    GaussianBlur(gray_img, img_gaus, Size(), 1, 1);

    Mat img_canny;
    Canny(img_gaus, img_canny, 20, 100);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(img_canny, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    double maxLength = 0;
    Rect longestBox;
    for (const auto& contour : contours) {
        double length = arcLength(contour, true);
        if (length > maxLength) {
            maxLength = length;
            longestBox = boundingRect(contour);
        }
    }

    Mat result;
    cvtColor(img_canny, result, COLOR_GRAY2BGR);
    if (maxLength > 0) {
        rectangle(result, longestBox, Scalar(0, 255, 0), 2);
    }

    imshow("result", result);

    waitKey(0);

    return 0;
}








