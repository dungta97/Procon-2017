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

void push_vpair(vector<vPair>& res, Vertex *a, Vertex *b)
{
	res.push_back(vPair(a, b));
	if ((a->angle + b->angle) != 2 * PI)
		res.push_back(vPair(b, a));
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
					push_vpair(res, &(pieces[i].vertices[m]), &(pieces[j].vertices[n]));

					if (!pieces[i].is_frame)
					{
						Piece flip = pieces[i].flip();
						push_vpair(res, &flip.vertices[flip.vertices.size() - 1 - m], &(pieces[j].vertices[n]));
						res.back().result.child_1 = &pieces[i];
					}
					else
					{
						Piece flip = pieces[j].flip();
						push_vpair(res, &(pieces[i].vertices[m]), &flip.vertices[flip.vertices.size() - 1 - n]);
						res.back().result.child_2 = &pieces[j];
					}
				}
		}
}
