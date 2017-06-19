#pragma once

class Piece;
class Vertex
{
public:
	int x, y;
	Piece *parent;
	int id;
	double angle;
	Vertex(int x, int y, Piece *parent, int id);
	void compute_angle(const Vertex &before, const Vertex &after);
};
