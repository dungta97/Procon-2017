#include "Vertex.h"
#include "Piece.h"
#include <algorithm>

#define CANT_ROTATE -1
#define INTERSECT -2

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

int try_get_cmp(Vertex& a, Vertex& b, Vertex& _b, Vertex& a_)
{
	geometric::Point
		A = a.point,
		_B = _b.point,
		A_ = a_.point;

	if (!b.parent->rotate(geometric::compute_angle(A_, A, _B), A))
		return CANT_ROTATE;
	if (geometric::check_polygon_intersect(*a.parent, *b.parent))
		return INTERSECT;
	if (!geometric::equal(a.angle + b.angle, 2 * PI)) return 0;

	int cmp = 0;
	Vertex *pa = &a, *pb = &b;
	for (int i = 0; i < min(a.parent->vertices.size(), b.parent->vertices.size()); i++)
	{
		if (pa->point == pb->point) cmp++;
		pa = pa->prev();
		pb = pb->next();
	}
	return cmp;
}

void vPair::get_compatibility()
{
	compatibility = 0;
	Piece tmp_piece_a, tmp_piece_b;
	this->a->parent->clone(tmp_piece_a);
	this->b->parent->clone(tmp_piece_b);

	Vertex *a = &tmp_piece_a.vertices[this->a->id];
	Vertex *b = &tmp_piece_b.vertices[this->b->id];

	tmp_piece_b.move(this->a->point - this->b->point);

	compatibility = try_get_cmp(*a, *b, *b->prev(), *a->next());
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
