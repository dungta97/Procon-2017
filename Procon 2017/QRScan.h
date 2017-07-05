#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "zbar.h"
#include <iostream>
using namespace std;
using namespace cv;
using namespace zbar;
namespace qrscan {
	vector<String> ScanQR(VideoCapture& cap);
}




