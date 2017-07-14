#pragma once
#include <vector>
#include "Vertex.h"
using namespace std;

class Piece
{
public:
	vector<Vertex> vertices;
	bool exist;
	bool is_frame;
	Piece *child_1, *child_2;

	Piece();
	void push(int x, int y);
	void compute_angles();
	void move(geometric::Point v);
	bool rotate(double angle, geometric::Point center);
	void print();
	void clone(Piece &newpiece);
};
