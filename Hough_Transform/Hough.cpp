#include<opencv.hpp>;

using namespace cv;
using namespace std;

//Text 1
/*int main() {
	Mat dst;
	Mat src = imread("E:\\dignal picture\\lena.jpg");
	double angle = -10;
	double scale = 1;
	Point2f center(src.cols/2.0,src.rows/2.0);
	Mat rot = getRotationMatrix2D(center,angle,scale);
	Rect bbox = RotatedRect(center, src.size(), angle).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	warpAffine(src, dst, rot, bbox.size());
	imshow("dst", dst);

	waitKey(0);
}*/

//Text 2
/*int main() {

	Mat dst;
	Mat src;
	Mat canny;
	 src = imread("E:\\dignal picture\\Hough_TEXT.png",1);
	 Canny(src, canny, 70, 210);
	
	 vector<cv::Vec2f>lines;
	 HoughLines(canny, lines, 1, CV_PI / 180, 100);
	 vector<Vec2f>::iterator it = lines.begin();
	 for (;it != lines.end();++it) {
		 float rho = (*it)[0], theta = (*it)[1];
		 Point pt1, pt2;
		 double a = cos(theta);
		 double b = sin(theta);
		 double x0 = a * rho;
		 double y0 = b * rho;
		 pt1.x = saturate_cast<int>(x0 + 1000 * (-b));
		 pt1.y = saturate_cast<int>(y0 + 1000 * (a));
		 pt2.x = saturate_cast<int>(x0 - 1000 * (-b));
		 pt2.y = saturate_cast<int>(y0 - 1000 * (a));
		 line(src, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	 }
	 imshow("result", src);
	 waitKey(0);
}*/

//Text 3
int main() {
	Mat src,canny;

	src = imread("E:\\dignal picture\\Hough_TEXT.png", 1);

	Canny(src, canny, 70, 210);

	vector<cv::Vec4i>lines;
	HoughLinesP(canny, lines, 1, CV_PI / 180, 20,3,10);
	vector<Vec4i>::iterator it = lines.begin();
	for (;it != lines.end();++it) {
		Point pt1, pt2;
		int x1 = (*it)[0];
		int y1 = (*it)[1];
		int x2 = (*it)[2];
		int y2 = (*it)[3];
		pt1.x = x1;
		pt1.y = y1;
		pt2.x = x2;
		pt2.y = y2;
		line(src, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	}

	imshow("result", src);
	waitKey(0);
}