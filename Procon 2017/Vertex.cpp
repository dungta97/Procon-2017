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
	Piece& a = *(this->a->parent);
	Piece b = *(this->b->parent);
	b.move(this->a->point - this->b->point);
}

Vertex* Vertex::next()
{
	return &(parent->vertices[(id + 1) % parent->vertices.size()]);
}

Vertex* Vertex::prev()
{
	return &(parent->vertices[(id - 1 + parent->vertices.size()) % parent->vertices.size()]);
}

void Vertex::move(geometric::Point v)
{
	point = point + v;
}