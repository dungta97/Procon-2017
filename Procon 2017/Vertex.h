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
	Vertex* next();
	Vertex* prev();
	void move(geometric::Point v);
};

class vPair
{
public:
	Vertex *a, *b;
	int compatibility;
	vPair(Vertex *a, Vertex *b);
	Piece* merged_piece;
	void get_compatibility();
};