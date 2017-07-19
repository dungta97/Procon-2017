#include <iostream>
#include "State.h"
#include "InputReader.h"
#include "QRScan.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iomanip> 
using namespace std;
using namespace cv;
State state;

/*vector<cv::Point> toVectorPoint(vector<Vertex>& vertex, int ratio) {
	vector<cv::Point> vtmp;
	vtmp.clear();
	for each (Vertex v in vertex)
	{
		vtmp.push_back(cv::Point(v.point.x*ratio, v.point.y*ratio));
	}
	return vtmp;
}*/

vector<Piece> findPolygon(Mat& realImg) {
	vector<Piece> res;
	vector<vector<Point>> contour;
	Mat thres, display;
	cvtColor(realImg, thres, CV_BGR2GRAY);
	threshold(thres, thres, 50, 255, CV_THRESH_BINARY_INV);
	findContours(thres, contour, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
	for (size_t i = 0; i < contour.size(); i++)
	{
		Piece piece;
		vector<Point> poly;
		approxPolyDP(contour[i], poly, 5, true);
		for each (Point p in poly)
		{
			piece.push(p.x, p.y);
		}
		piece.compute_angles();
		res.push_back(piece);
		/*polylines(realImg, poly, true, Scalar(0, 0, 255), 2);
		resize(realImg, display, thres.size() / 2);
		imshow("thres", display);*/
	}
	/*polylines(realImg, res, true, Scalar(0, 0, 255), 2);
	resize(realImg, realImg, thres.size() / 2);
	imshow("thres", realImg);*/
	return res;
}
Mat findMatchPiece(Mat& realImg,Piece& piece) {
	vector<Piece> realPieces = findPolygon(realImg);
		int numVertex = piece.vertices.size();
		int eps = 7;
		Mat realImgDisp = realImg.clone();
		for (size_t i = 0; i < realPieces.size(); i++)
		{
			double s = 0;
			bool fit = false,
				flip = false;
			if (realPieces.at(i).vertices.size() == numVertex) {
				for (size_t j = 0; j <numVertex; j++)
				{
					s = realPieces.at(i).vertices.at(j).angle - piece.vertices.at(0).angle;
					if (abs(s) < eps) {
						bool kt = true;
						for (size_t k = 1; k < numVertex; k++)
						{
							double t = realPieces.at(i).vertices.at((j + k) % numVertex).angle - piece.vertices.at(k).angle;
							s += t;
							if (abs(t) > eps) {
								kt = false;
								break;
							}
						}
						if (kt && (abs(s / numVertex) < eps / numVertex)) fit = true;
						else {
							kt = true;
							s = realPieces.at(i).vertices.at(j).angle - piece.vertices.at(0).angle;
							for (size_t k = 1; k < numVertex; k++)
							{
								double t = realPieces.at(i).vertices.at((j - k + numVertex) % numVertex).angle - piece.vertices.at(k).angle;
								s += t;
								if (abs(t) > eps) {
									kt = false;
									break;
								}
							}
							if (kt && (abs(s / numVertex) < eps / numVertex)) {
								fit = true;
								flip = true;
							}
						}
					}
					if (fit) break;
				}
			}
			if (fit) {
				cout << setprecision(14) << fixed << s << endl;
				if (flip) {
					for (int j = 0;j < realPieces.at(i).vertices.size();i++) {
						line(realImgDisp, Point(realPieces.at(i).vertices[j].point.x, realPieces.at(i).vertices[j].point.y), Point(realPieces.at(i).vertices[(j + 1) % numVertex].point.x, realPieces.at(i).vertices[(j + 1) % numVertex].point.y), Scalar(0, 255, 0),3);
					}
				}
					//polylines(realImgDisp, toVectorPoint(realPieces.at(i).vertices, 1), true, Scalar(0, 255, 0), 3);
				else {
					for (int j = 0;j < realPieces.at(i).vertices.size();i++) {
						line(realImgDisp, Point(realPieces.at(i).vertices[j].point.x, realPieces.at(i).vertices[j].point.y), Point(realPieces.at(i).vertices[(j + 1) % numVertex].point.x, realPieces.at(i).vertices[(j + 1) % numVertex].point.y), Scalar(0, 0, 255), 3);
					}
				}
					//polylines(realImgDisp, toVectorPoint(realPieces.at(i).vertices, 1), true, Scalar(255, 0, 0), 3);
			}
		}
		return realImgDisp;
}
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
		Mat a=imread("")
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
	/*VideoCapture cap;
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
	res = to_string(n) + res;*/
	state = readInput("input.txt");
	backtrack(0);
	getchar();
}