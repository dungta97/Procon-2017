#pragma once

class Piece;
class Vertex
{
public:
	int x, y;
	Piece *parent;
	int id;
	Vertex(int x, int y, Piece *parent, int id);
};
