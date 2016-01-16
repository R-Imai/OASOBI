/*--------------------------------------------------------------------------------------------------------------
*	Name:		edgeDetection.cpp
*	Author:		R.Imai
*	Created:	2016 / 01 / 15
*	Last Date:	2016 / 01 / 16
*	Note:
*
*--------------------------------------------------------------------------------------------------------------*/

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;



int X[450], Y[450];
int cnt = 0;
int label[450][450];
int count = 1;
int mask[3][3] = { { -1, -1, -1 }, { -1, 8, -1 }, { -1, -1, -1 } };

void Mouse(int event, int x, int y, int flags, void *param = NULL)
{
	cv::Mat bin_img;
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		break;


	}
}


cv::Vec3b getBGR(cv::Mat img, int x, int y){
	return img.at<cv::Vec3b>(y, x);
}



int main(int argc, char *argv[])
{

	int B, G, R;
	int threshold = 80;
	cv::Vec3b bgr;
	cv::VideoCapture cap(0);
	cv::Mat originImg;// = cv::imread("robo.jpg", 1);

	while (cv::waitKey(1) != 'q'){
		cap >> originImg;
		if (originImg.empty()) continue;

		double scale = 4.0;
		cv::Mat smallImg(cv::saturate_cast<int>(originImg.rows / scale), cv::saturate_cast<int>(originImg.cols / scale), CV_8UC1);
		// èàóùéûä‘íZèkÇÃÇΩÇﬂÇ…âÊëúÇèkè¨
		cv::resize(originImg, smallImg, smallImg.size(), 0, 0, cv::INTER_LINEAR);

		cv::Mat smallWhite(cv::Size(smallImg.cols, smallImg.rows), CV_8UC3, cv::Scalar::all(255));
		cv::Mat whiteImg(cv::Size(originImg.cols, originImg.rows), CV_8UC3, cv::Scalar::all(255));
		cv::Mat paletteImg(cv::Size(originImg.cols, originImg.rows), CV_8UC3, cv::Scalar::all(255));
		for (int y = 1; y < smallImg.rows - 1; y++) {
			cv::Vec3b* ptr = smallWhite.ptr<cv::Vec3b>(y);
			cv::Vec3b* pal = paletteImg.ptr<cv::Vec3b>(y);
			for (int x = 1; x < smallImg.cols - 1; x++) {
				B = 0;
				G = 0;
				R = 0;
				for (int i = 0; i < 3; i++){
					for (int j = 0; j < 3; j++){
						bgr = getBGR(smallImg, x - 1 + i, y - 1 + j);
						B += bgr[0] * mask[i][j];
						G += bgr[1] * mask[i][j];
						R += bgr[2] * mask[i][j];
					}
				}
				if (B > threshold){
					B = 255;
				}
				if (G > threshold){
					G = 255;
				}
				if (R > threshold){
					R = 255;
				}
				if (B != 255 || G != 255 || R != 255){
					B = 0;
					G = 0;
					R = 0;
				}
				ptr[x] = cv::Vec3b(B, G, R);
				pal[x] = cv::Vec3b(getBGR(smallImg, x, y)[0], 0, 0);
			}
		}

		cv::resize(smallWhite, whiteImg, whiteImg.size(), 0, 0, cv::INTER_LINEAR);

		cv::imshow("nomal image", originImg);
		cv::imshow("edging image", whiteImg);
		//cv::imshow("palette image", paletteImg);
		cvSetMouseCallback("nomal image", Mouse);
	}
}