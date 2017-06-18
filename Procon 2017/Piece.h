#pragma once
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

class Piece
{
public:
	vector<Point> vertex;
	bool exist;
	Piece *child_1, *child_2;

	Piece() 
	{
		this->exist = true;
		child_1 = child_2 = nullptr;
	}
};
