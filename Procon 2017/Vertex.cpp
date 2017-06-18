#include "Vertex.h"
#include "Geometric.h"

Vertex::Vertex(int x, int y, Piece *parent, int id)
{
	this->x = x;
	this->y = y;
	this->parent = parent;
	this->id = id;
}

void Vertex::compute_angle(const Vertex &before, const Vertex &after)
{
	angle = geometric::compute_angle(before, *this, after);
}