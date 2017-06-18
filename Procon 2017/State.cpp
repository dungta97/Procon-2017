#include "State.h"

void State::push(Piece &piece)
{
	pieces.push_back(piece);
}

State::State(int N)
{
	pieces = vector<Piece>(N);
}