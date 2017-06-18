#pragma once
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Vertex.h"
using namespace cv;
using namespace std;

class Piece
{
public:
	vector<Vertex> vertexs;
	bool exist;
	Piece *child_1, *child_2;

	Piece() 
	{
		this->exist = true;
		child_1 = child_2 = nullptr;
	}
	
	void push(int x, int y)
	{
		vertexs.push_back(Vertex(x, y, this, (int)vertexs.size()));
	}
};
