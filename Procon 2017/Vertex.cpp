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
	Piece tmp_piece = *(this->b->parent);
	for (int i = 0; i < tmp_piece.vertices.size(); i++)
	{
		tmp_piece.vertices[i].parent = &tmp_piece;
	}
	Vertex *b = &tmp_piece.vertices[this->b->id];
	tmp_piece.move(this->a->point - this->b->point);

	geometric::Point
		A = this->a->next()->point,
		O = this->a->point,
		B = b->prev()->point;
	if (!b->parent->rotate(geometric::compute_angle(A, O, B), O))
	{
		compatibility = -1;
		return;
	}
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

bool Vertex::rotate(double angle, geometric::Point center)
{
	return point.rotate(angle, center);
}

void Vertex::print()
{
	point.print();
}
