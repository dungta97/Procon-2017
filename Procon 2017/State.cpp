#include "State.h"

void State::push(Piece &piece)
{
	piece.id = (int)pieces.size() + 1;
	pieces.push_back(piece);
}