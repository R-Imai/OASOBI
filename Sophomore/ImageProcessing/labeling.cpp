#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;

int X[500], Y[500];
int Label[450][450] = {};
int cnt=0;
int label_num = 0;
unsigned long Xsum, Ysum;
//cv::Mat src_img = cv::imread("circle.jpg", 1);
//cv::Mat nomal_img = cv::imread("circle.jpg", 1);
//cv::Mat gray_img = cv::imread("circle.jpg", 0);

//cv::Mat src_img = cv::imread("test_easy.jpg", 1);
//cv::Mat nomal_img = cv::imread("test_easy.jpg", 1);
//cv::Mat gray_img = cv::imread("test_easy.jpg", 0);

//cv::Mat src_img = cv::imread("coloful.jpg", 1);
//cv::Mat nomal_img = cv::imread("coloful.jpg", 1);
//cv::Mat gray_img = cv::imread("coloful.jpg", 0);

cv::Mat src_img = cv::imread("RImai.jpg", 1);
cv::Mat nomal_img = cv::imread("Rimai.jpg", 1);
cv::Mat gray_img = cv::imread("RImai.jpg", 0);
void Mouse(int event, int x, int y, int flags, void *param = NULL)
{
	cv::Mat bin_img;
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		cv::threshold(gray_img, bin_img, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
		cv::Vec3b* ptr = bin_img.ptr<cv::Vec3b>(y);
		cv::Vec3b bgr = ptr[x];
		int blight = bin_img.at<unsigned char>(y, x);
		printf("%d	", Label[x][y]);
		printf("(%d,%d):BGR=(%d,%d,%d):inten=%d \n", x, y, bgr[0], bgr[1], bgr[2],blight);
		break;


	}
}

void outline(int point_x, int point_y,cv::Mat img,int num){//複数認識させるためにカウンタの導入とX,Yを二次元配列にする。
	int x = point_x, y = point_y;
	int n=0;
	int sw=0,fg=0;
	int list[8] = { 4, 5, 6, 7, 0, 1, 2, 3 };
	while (x != point_x||y != point_y||sw==0){

		//printf("%d,%d	n=%d	\n", x, y,n);
		switch (n)
		{
		case 0:
			if (img.at<unsigned char>(y+1, x-1)==0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				x = x - 1;
				y = y + 1;
			}
			break;
		case 1:
			if (img.at<unsigned char>(y+1, x) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				y = y + 1;
			}
			break;
		case 2:
			if (img.at<unsigned char>(y+1, x+1) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				x = x + 1;
				y = y + 1;
			}
			break;
		case 3:
			if (img.at<unsigned char>(y, x+1) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				x = x + 1;
			}
			break;
		case 4:
			if (img.at<unsigned char>(y-1, x+1) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				x = x + 1;
				y = y - 1;
			}
			break;
		case 5:
			if (img.at<unsigned char>(y-1, x) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				y = y - 1;
			}
			break;
		case 6:
			if (img.at<unsigned char>(y-1, x-1) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				x = x - 1;
				y = y - 1;
			}
			break;
		case 7:
			if (img.at<unsigned char>(y, x-1) == 0){
				fg = 1;
				X[cnt] = x;
				Y[cnt] = y;
				x = x - 1;
			}
			break;
		}
		
		if (fg == 1&&Label[x][y]==0){
				Label[x][y] = num;
				//cout << num << "\n";
			n = list[n]+1;
			if (n == 8){
				n = 0;
			}
			cnt++;
			fg = 0;
			sw = 1;
		}
		else{
			n=n+1;
			if (n == 8){
				fg = 0;
				n = 0;
			}
		}

	}


}

//void find_point(cv::Mat img){
//	int blight = 0, b = 0;
//	for (int y = 0; y < img.rows; y++) {
//		cv::Vec3b* ptr = img.ptr<cv::Vec3b>(y);
//
//		for (int x = 0; x < img.cols; x++) {
//			int blight = img.at<unsigned char>(y, x);
//			if (blight == 0 && Label[x][y] == 0){
//				outline(x, y, img);
//				b = 1;
//				break;
//			}
//		}
//		if (b){
//			break;
//		}
//	}
//}

void paint(int num,cv::Mat img){
	int list[500] = {};
	int fg = 0;
	int point[450][2] = { {}, {} };
	for (int y = 0; y < src_img.rows; y++) {
		for (int x = 0; x < src_img.cols; x++) {
			if (point[y][0]==0){
				if (Label[x][y] == num){
					point[y][0] = x;
				}
			}
			if (Label[x][y] == num){
				point[y][1] = x;
			}
		}
	}
	for (int y = 0; y < src_img.rows; y++){
		if (point[y][0] != 0 && point[y][0] != point[y][1] ){
			for (int i = point[y][0]; i <= point[y][1]; i++){
				if (img.at<unsigned char>(y, i) == 0&&Label[i][y]==0){
					Label[i][y] = num;
					//cout << num << "\n";
				}
			}
		}
	}
}

int getDivnum(int num){
	int judNum = 0;
	for (int i = 2; i < 100; i++){
		if (num < pow(num, 3)){
			judNum = i;
			break;
		}
	}
	return judNum;
}

int main(int argc, char *argv[])
{
	long sum[3] = { 0, 0, 0 };
	int point[2];
	int b = 0;
	int hist_g[256];
	int max=0;
	double r;
	int label;
	int R, G, B, divNum;
	int element;

	for (int i = 0; i < 256; i++){
		hist_g[i] = 0;
	}

	cv::Mat hist_img(cv::Size(256, 700), CV_8UC3, cv::Scalar::all(255));
	cv::Mat Label_img(cv::Size(450, 450), CV_8UC3, cv::Scalar::all(255));
	
	if (!gray_img.data) return -1;

	// 固定の閾値処理
	cv::Mat bin_img, bininv_img;
	cv::Mat v_img, h_img, b_img;
	cv::Mat dst_img = ~src_img;
	cv::flip(src_img, v_img, 0); // 水平軸で反転（垂直反転）
	cv::flip(src_img, h_img, 1); // 垂直軸で反転（水平反転）
	cv::flip(src_img, b_img, -1); // 両方の軸で反転
	// 入力画像，出力画像，閾値，maxVal，閾値処理手法
	cv::threshold(gray_img, bin_img, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::threshold(gray_img, bininv_img, 0, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);
	// 適応的な閾値処理
	cv::Mat adaptive_img;
	// 入力画像，出力画像，maxVal，閾値決定手法，閾値処理手法，blockSize，C
	cv::adaptiveThreshold(gray_img, adaptive_img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 7, 8);

			for (int y = 0; y < gray_img.rows; y++) {//ヒストグラム作成の準備
				// ポインタの取得
				cv::Vec3b* ptr = gray_img.ptr<cv::Vec3b>(y);
				for (int x = 0; x < gray_img.cols; x++) {
					int blight = gray_img.at<unsigned char>(y, x);
					cv::Vec3b bgr = ptr[x];
					hist_g[blight]++;
				}
			}

			for (int y = 0; y < bin_img.rows; y++) {
				cv::Vec3b* ptr = bin_img.ptr<cv::Vec3b>(y);
				for (int x = 0; x < bin_img.cols; x++) {
					int blight = bin_img.at<unsigned char>(y, x);
					if (blight == 0 && Label[x][y]==0 /*&& label_num<=2*/){
						label_num++;
						//point[0] = x;
						//point[1] = y;
						outline(x, y, bin_img,label_num);
						paint(label_num,bin_img);
						
					}
				}
			}


			/*for (int y = 0; y < bin_img.rows; y++) {
				for (int x = 0; x < bin_img.cols; x++) {
					if (Label[x][y] > label_num){
						cout << Label[x][y] << "\n";
					}
				}
			}*/
			

				for (int n = 0; n < 255; n++) {
					cv::line(hist_img, cv::Point(n, 700), cv::Point(n, 700-hist_g[255-n]/2), cv::Scalar(200, 0, 0), 1, 8);
					}





	// 結果画像表示
	cv::namedWindow("nomal image", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::namedWindow("effect image", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::namedWindow("hist", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);

	//cv::circle(src_img, cv::Point(200, 250), 120, cv::Scalar(0, 200, 0), 2, 8);
	/*for (int k = 0; k < cnt; k++){
		Ysum += Y[k];
		Xsum += X[k];
		cv::Vec3b* ptr = src_img.ptr<cv::Vec3b>(Y[k]);
		ptr[X[k]] = cv::Vec3b(0, 0, 255);
	}*/
	for (int y = 0; y < src_img.rows; y++) {
		cv::Vec3b* ptr = Label_img.ptr<cv::Vec3b>(y);
		for (int x = 0; x < src_img.cols; x++) {
			label = Label[x][y];
			if (label != 0 && label <= label_num){
				divNum = getDivnum(label_num);
				element = 256 / divNum - 1;
				G = label % divNum * element;
				B = (label / divNum) % divNum * element;
				R = (label / divNum / divNum) % divNum * element;
				//cout << R << "," << G << "," << B << "\n";
				ptr[x] = cv::Vec3b(B, G, R);
			}
			/*switch (Label[x][y]){
			case 1:
				ptr[x] = cv::Vec3b(255, 0, 0);
				break;

			case 2:
				ptr[x] = cv::Vec3b(0, 255, 0);
				break;

			case 3:
				ptr[x] = cv::Vec3b(0, 0, 255);
				break;

			case 4:
				ptr[x] = cv::Vec3b(0, 255, 255);
				break;

			case 5:
				ptr[x] = cv::Vec3b(255, 255, 0);
				break;

			case 6:
				ptr[x] = cv::Vec3b(255, 0, 255);
				break;

			case 7:
				ptr[x] = cv::Vec3b(127, 127, 127);
				break;
			}*/

		}
	}
	printf("%d\n", label_num);

	Ysum = Ysum / cnt;
	Xsum = Xsum / cnt;

	r = (Ysum - Y[0])*(Ysum - Y[0]) + (Xsum - X[0])*(Xsum - X[0]);
	r = sqrt(r);

	//cv::circle(src_img, cv::Point(Xsum, Ysum), r, cv::Scalar(0, 0, 200), 2, 8);

	cv::imshow("nomal image", src_img);
	cv::imshow("effect image", bin_img);
	cv::imshow("hist", hist_img);
	cv::imshow("pallete", Label_img);
	//imwrite("RImai_color.jpg", Label_img);
	//printf("%d",cnt);
	cvSetMouseCallback("nomal image", Mouse);
	cvSetMouseCallback("effect image", Mouse);

	cv::waitKey(0);
}