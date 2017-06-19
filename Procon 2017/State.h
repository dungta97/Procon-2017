#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class State
{
public:
	vector<Piece> pieces;
	void push(Piece &piece);
	State(int N);
};