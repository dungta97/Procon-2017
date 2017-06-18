#include "Piece.h"

Piece::Piece()
{
	this->exist = true;
	child_1 = child_2 = nullptr;
}

void Piece::push(int x, int y)
{
	vertices.push_back(Vertex(x, y, this, (int)vertices.size()));
}