#pragma once
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

class Piece
{
public:
	vector<Point> vertex;
	bool exist;
	int id_child_1, id_child_2;

	Piece() 
	{
		this->exist = true;
		id_child_1 = id_child_2 = -1;
	}
};

