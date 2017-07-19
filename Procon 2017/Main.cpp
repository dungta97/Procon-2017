#include <iostream>
#include "State.h"
#include "InputReader.h"
#include "QRScan.h"
using namespace std;

State state;

void show_me(int root)
{
	cout << root << endl;
	int child_1 = state.pieces[root].child_1;
	int child_2 = state.pieces[root].child_2;
	cout << child_1 << " " << child_2 << endl;
	if (child_1 != -1)
	{
		show_me(child_1);
		show_me(child_2);
		imshow("child 1", geometric::drawPiece(state.pieces[child_1], 30));
		imshow("child 2", geometric::drawPiece(state.pieces[child_2], 30));
		imshow("result", geometric::drawPiece(state.pieces[root], 30));
		waitKey();
	}
}

void trace_result()
{
	int root;
	for (int i = 0; i < state.pieces.size(); i++)
		if (state.pieces[i].exist)
		{
			root = i;
			break;
		}
	show_me(root);
}

void backtrack(int depth)
{
	cout << depth << endl;
	if (depth == InputReader::N)
		trace_result();
	vector<vPair> vpairs;
	state.get_vPairs(vpairs);
	if (vpairs.empty()) return;
	std::sort(vpairs.begin(), vpairs.end(), compare_func);
	for (int i = 0; i < vpairs.size(); i++)
	{
		state.push(vpairs[i].result);
		state.pieces.back().exist = true;
		state.pieces[vpairs[i].result.child_1].exist = false;
		state.pieces[vpairs[i].result.child_2].exist = false;
		backtrack(depth + 1);
		state.pieces.back().exist = false;
		state.pieces[state.pieces.back().child_1].exist = true;
		state.pieces[state.pieces.back().child_2].exist = true;
		state.pieces.pop_back();
	}
}

int main(void) {
	VideoCapture cap;
	cap.open("http://192.168.100.4:8080/video");
	vector<String> vs=ScanQR(cap);
	cout << vs[0] << endl;
	String res = "";
	int idx = -1,n=0;
	for (int i = 0;i < vs.size();i++) {
		String tmp=vs[i].substr(0, vs[i].find_first_of(":"));
		int a = stoi(tmp);
		n += a;
		if (a != std::count(vs[i].begin(), vs[i].end(), ':')) idx = i;
		else {
			res += vs[i].substr(vs[i].find_first_of(":"), vs[i].length());
		}
	}
	res += vs[idx].substr(vs[idx].find_first_of(":"), vs[idx].length());
	res = to_string(n) + res;
	state = readInput(res);
	backtrack(0);
	getchar();
}