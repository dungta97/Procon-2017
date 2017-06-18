#include "Vertex.h"

Vertex::Vertex(int x, int y, Piece *parent, int id)
{
	this->x = x;
	this->y = y;
	this->parent = parent;
	this->id = id;
}