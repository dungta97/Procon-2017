#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm> 
#include "QRScan.h"
#include "Piece.h"
using namespace std;
using namespace cv;

vector<String> resQR; //kết quả quét qrcode;
VideoCapture cap;
int main(void) {
	cap.open("video.mp4");
	resQR=ScanQR(cap);
}