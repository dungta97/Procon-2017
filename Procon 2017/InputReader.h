#pragma once
#include <string>
#include <queue>
#include "Piece.h"
#include "State.h"
using namespace std;

class InputReader
{
public:
	static queue<int> input;
	static void getInputString(string str)
	{
		string w = "";
		str += ' ';
		for each (char c in str)
		{
			if ((c != ' ') && (c != ':') && (c != '\n'))
				w += c;
			else if (w == "")
				continue;
			else
			{
				input.push(stoi(w));
				w = "";
			}
		}
	}
	static int read()
	{
		int res = input.front();
		input.pop();
		return res;
	}
};

queue<int> InputReader::input;

State readInput(char* fileName)
{
	ifstream inp(fileName);
	string s;
	getline(inp, s);
	InputReader::getInputString(s);
	int N = InputReader::read();
	State res(N + 1);
	for (int I = 0; I < N + 1; I++)
	{
		int n = InputReader::read();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			x = InputReader::read();
			y = InputReader::read();
			res.pieces[I].push(x, y);
		}
	}
	return res;
}