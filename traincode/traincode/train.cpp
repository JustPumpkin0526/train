#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap("train (1).mp4");

    Mat src;
    Mat dst;
    cap >> src;

    cvtColor(src, dst, COLOR_RGB2GRAY);

    Mat dst_gaus;
    GaussianBlur(dst, dst_gaus, Size(), 1, 1);

    Mat dst_canny;
    Canny(dst_gaus, dst_canny, 20, 100);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dst_canny, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

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
    cvtColor(dst_canny, result, COLOR_GRAY2BGR);
    if (maxLength > 0) {
        rectangle(result, longestBox, Scalar(0, 255, 0), 2);
    }

    imshow("dst_gaus", result);

    waitKey(0);

    return 0;
}