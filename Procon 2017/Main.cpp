#include <iostream>
#include "State.h"
#include "InputReader.h"
using namespace std;

int main(void) {
	State initial = readInput("test_input.txt");

	/*vector<vPair> vpairs;
	initial.get_vPairs(vpairs);
	cout << "count: " << vpairs.size() << endl;
	for each (vPair vpair in vpairs)
	{
		cout << vpair.a->point.x << " " << vpair.a->point.y << " " << vpair.b->point.x << " " << vpair.b->point.y << " " << vpair.compatibility << endl;
	}*/
	cout << geometric::check_polygon_intersect(initial.pieces[0], initial.pieces[1]);
	getchar();
}