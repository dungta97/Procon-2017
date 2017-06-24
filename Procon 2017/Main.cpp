#include <iostream>
#include "State.h"
#include "InputReader.h"
using namespace std;

int main(void) {
	State initial = readInput("input.txt");
	for each (Piece piece in initial.pieces)
	{
		Vertex* v = &piece.vertices[0];
		for (int i = 0; i < piece.vertices.size(); i++)
		{
			cout << v->point.x << " " << v->point.y << " " << v->id << endl;
			v = v->next();
		}
		cout << endl;
	}
	/*vector<vPair> vpairs;
	initial.get_vPairs(vpairs);
	cout << "count: " << vpairs.size();
	for each (vPair vpair in vpairs)
	{
		cout << vpair.a->point.x << " " << vpair.a->point.y << " " << vpair.b->point.x << " " << vpair.b->point.y << endl;
	}*/
	getchar();
}