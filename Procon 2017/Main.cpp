﻿#include <iostream>
#include "State.h"
#include "InputReader.h"
using namespace std;

int main(void) {
	State initial = readInput("input.txt");
	for each (Piece piece in initial.pieces)
	{
		for each (Vertex vertex in piece.vertices)
		{
			cout << vertex.point.x << " " << vertex.point.y << " " << vertex.angle << endl;
		}
		cout << endl;
	}
	getchar();
}