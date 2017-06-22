#pragma once
#include "Geometric.h"

class Piece;
class Vertex
{
public:
	geometric::Point point;
	Piece *parent;
	int id;
	double angle;
	Vertex(const geometric::Point& point, Piece *parent, int id);
	void compute_angle(const Vertex &before, const Vertex &after);
};
