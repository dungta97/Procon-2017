#include "State.h"
#include <iostream>
using namespace std;

void State::push(Piece &piece)
{
	pieces.push_back(piece);
}

State::State(int N)
{
	pieces = vector<Piece>(N);
}

void State::get_vPairs(vector<vPair>& res)
{
	res.clear();
	for (int i = 0; i < pieces.size(); i++)
		for (int j = i + 1; j < pieces.size(); j++)
		{
			for (int m = 0; m < pieces[i].vertices.size(); m ++)
				for (int n = 0; n < pieces[j].vertices.size(); n++)
				{
					res.push_back(vPair(&(pieces[i].vertices[m]), &(pieces[j].vertices[n])));
				}
		}
}
