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
					/*cout << i << ' ' << j << ' ' << m << ' ' << n << endl;
					Piece *to_flip;
					if (!pieces[i].is_frame)
						to_flip = &pieces[i];
					else
						to_flip = &pieces[j];
					to_flip->flip();
					cout << "flip done" << endl;
					pieces[i].print();
					cout << endl;
					pieces[j].print();
					push_vpair(res, &(pieces[i].vertices[m]), &(pieces[j].vertices[n]));
					to_flip->flip();*/
				}
		}
}
