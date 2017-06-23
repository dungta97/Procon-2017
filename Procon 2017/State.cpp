#include "State.h"

void State::push(Piece &piece)
{
	pieces.push_back(piece);
}

State::State(int N)
{
	pieces = vector<Piece>(N);
}

vector<vPair>* State::get_vPairs()
{
	vector<vPair> res;
	for (int i = 0; i < pieces.size(); i++)
		for (int j = i + 1; j < pieces.size(); j++)
		{
			for each (Vertex i_vertex in pieces[i].vertices)
				for each (Vertex j_vertex in pieces[j].vertices)
				{
					vPair tmp(&i_vertex, &j_vertex);
					res.push_back(tmp);
				}
		}
	return &res;
}
