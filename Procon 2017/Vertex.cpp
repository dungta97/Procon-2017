#include "Vertex.h"
#include "Piece.h"

Vertex::Vertex(const geometric::Point& point, Piece *parent, int id)
{
	this->point = point;
	this->parent = parent;
	this->id = id;
}

void Vertex::compute_angle(const Vertex &before, const Vertex &after)
{
	angle = geometric::compute_angle(before.point, this->point, after.point);
}

vPair::vPair(Vertex * a, Vertex * b)
{
	this->a = a;
	this->b = b;
	this->get_compatibility();
}

void vPair::get_compatibility()
{
	compatibility = 0;
}

Vertex* Vertex::next()
{
	return &(parent->vertices[(id + 1) % parent->vertices.size()]);
}

Vertex* Vertex::prev()
{
	return &(parent->vertices[(id - 1 + parent->vertices.size()) % parent->vertices.size()]);
}