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
	for each (Piece piece in initial.pieces)
	{
		for each (Vertex vertex in piece.vertexs)
		{
			cout << vertex.x << " " << vertex.y << endl;
		}
		cout << endl;
	}
	while (1);
}