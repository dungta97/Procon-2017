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
	geometric::Point 
		a1(3, 2),
		b1(5, 2),
		a2(3, 3),
		b2(0, 0);
	cout << geometric::intersect(a1, b1, a2, b2);
	getchar();
}