#include <iostream>
#include "State.h"
#include "InputReader.h"
using namespace std;

int main(void) {
	State initial = readInput("test_input.txt");

	vector<vPair> vpairs;
	initial.get_vPairs(vpairs);
	cout << "count: " << vpairs.size() << endl;
	for each (vPair vpair in vpairs)
	{
		vpair.a->print();
		vpair.b->print();
		cout << vpair.compatibility << endl;
		vpair.result.print();
	}
	getchar();
}