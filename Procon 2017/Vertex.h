#pragma once
#include "Piece.h"
class Piece;
class Vertex
{
public:
	int x, y;
	Piece *parent;
	int id;
	Vertex(int x, int y, Piece *parent, int id)
	{
		this->x = x;
		this->y = y;
		this->parent = parent;
		this->id = id;
	}
};
