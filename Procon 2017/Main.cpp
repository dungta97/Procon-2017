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
	cout << initial.pieces[0].rotate(1, geometric::Point(0, 0)) << endl;
	initial.pieces[0].print();
	getchar();
}