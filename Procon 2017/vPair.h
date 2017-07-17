#pragma once
#include "Piece.h"

class vPair
{
public:
	Vertex *a, *b;
	int compatibility;
	Piece result;

	vPair(Vertex *a, Vertex *b);
	Piece* merged_piece;
	void get_compatibility();
};