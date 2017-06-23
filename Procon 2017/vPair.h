#pragma once
#include "Piece.h"

class vPair
{
public:
	Vertex *a, *b;
	int compatibility;
	vPair(Vertex *a, Vertex *b);
	void get_compatibility();
};