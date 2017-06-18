#include <iostream>
#include <fstream>
#include "geometric.h"
#include "QRScan.h"
#include "Piece.h"
#include "State.h"
#include "InputReader.h"
using namespace std;

int main(void) {
	State initial = readInput("input.txt");
	for each (Piece p in initial.pieces)
	{
		for each (Point v in p.vertex)
		{
			cout << v.x << " " << v.y << endl;
		}
		cout << endl;
	}
	while (1);
}