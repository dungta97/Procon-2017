#include "Piece.h"

Piece::Piece()
{
	this->exist = true;
	child_1 = child_2 = nullptr;
}

void Piece::push(int x, int y)
{
	vertices.push_back(Vertex(geometric::Point(x, y), this, (int)vertices.size()));
}

void Piece::compute_angles()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		int before = int((i - 1 + vertices.size()) % vertices.size());
		int after = int((i + 1) % vertices.size());
		vertices[i].compute_angle(vertices[before], vertices[after]);
	}
}

void Piece::move(geometric::Point v)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i].move(v);
	}
}

bool Piece::rotate(double angle, geometric::Point center)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (!vertices[i].rotate(angle, center))
			return false;
	}
	return true;
}

void Piece::print()
{
	for each (Vertex vertex in vertices)
	{
		vertex.print();
		cout << endl;
	}
}
