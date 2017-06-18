#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"  
#include "QRScan.h"
using namespace std;
using namespace cv;

vector<String> resQR; //kết quả quét qrcode;
VideoCapture cap;
int main(void) {
	cap.open("http://192.168.1.118:8080/video?x.mjpeg");
	if (!cap.isOpened()) return 0;
	resQR=ScanQR(cap);
	
}