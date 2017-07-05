#include <iostream>
#include "State.h"
#include "InputReader.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iomanip> 
using namespace std;
using namespace cv;
vector<Point> toVectorPoint(vector<Vertex>& vertex,int ratio) {
	vector<Point> vtmp;
	vtmp.clear();
	for each (Vertex v in vertex)
	{
		vtmp.push_back(Point(v.point.x*ratio, v.point.y*ratio));
	}
	return vtmp;
}
vector<Piece> findPolygon(Mat& realImg){
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
int main(void) {
    /* Export pieces image from data
	State initial = readInput("input.txt");
	int kc = 50;
	for (int i=0;i<initial.pieces.size()-1;i++)
	{
		Piece p = initial.pieces.at(i);
		vector<Point> vtmp;
		vtmp.clear();
		for each (Vertex v in p.vertices)
		{
			cout << "(" << v.point.x << "," << v.point.y << ") ";
			vtmp.push_back(Point(v.point.x*kc, v.point.y*kc));
		}
		Rect bound=boundingRect(vtmp);
		vector<vector<Point>> a;
		a.clear();
		vector<Point> pnt;
		a.push_back(pnt);
		for each (Point point in vtmp)
		{
			a.at(0).push_back(Point(point.x - bound.x, point.y - bound.y));
		}
		Mat matPiece = Mat(bound.height, bound.width, CV_8UC3, Scalar(255, 255, 255));
		//fillPoly(matPiece, vtmp, Scalar(0, 0, 255));
		fillPoly(matPiece, a, Scalar(0, 0, 255));
		imshow("t", matPiece);
		imwrite(to_string(i) + ".png", matPiece);
		waitKey();
		cout << endl;
	}*/
	State initial = readInput("result.txt");
	int kc = 50;
	Rect bound = boundingRect(toVectorPoint(initial.pieces.back().vertices,kc));
	Mat matResult = Mat(bound.height, bound.width, CV_8UC3, Scalar(255, 255, 255));
	/*sort pieces*/
	Piece tmpPiece;
	for (int i = 0; i < initial.pieces.size() - 2; i++)
		for (int j = i + 1; j < initial.pieces.size() - 1; j++) {
			vector<Point> a, b;
			a.clear();
			b.clear();
			a = toVectorPoint(initial.pieces.at(i).vertices, 1);
			b = toVectorPoint(initial.pieces.at(j).vertices, 1);
			Rect ba = boundingRect(a);
			Rect bb = boundingRect(b);
			if ((ba.x + ba.y) > (bb.x + bb.y)) {
				tmpPiece = initial.pieces.at(i);
				initial.pieces.at(i) = initial.pieces.at(j);
				initial.pieces.at(j) = tmpPiece;
			}
		}
	/*draw the result*/
	for (int i = 0; i < initial.pieces.size() - 1; i++)
	{
		Piece p = initial.pieces.at(i);
		polylines(matResult, toVectorPoint(initial.pieces.at(i).vertices,kc), true, Scalar(0, 0, 255));
	}
	int idx = 0;
	double eps = 5;
	Mat realImg = imread("Capture.png");
	vector<Piece> realPieces=findPolygon(realImg);
	do {
		Piece considerPiece;
		initial.pieces.at(idx).clone(considerPiece);
		int numVertex = considerPiece.vertices.size();
		Mat resDisplay = matResult.clone();
		Mat realImgDisp = realImg.clone();
		polylines(resDisplay, toVectorPoint(considerPiece.vertices, kc), true, Scalar(0, 255, 0),2);
		imshow("Result!!!", resDisplay);
		for (size_t i = 0; i < realPieces.size(); i++)
		{
			double s = 0;
			bool fit = false,
				 flip =false;
			if (realPieces.at(i).vertices.size()== numVertex) {
				for (size_t j = 0; j <numVertex; j++)
				{
					s=realPieces.at(i).vertices.at(j).angle - considerPiece.vertices.at(0).angle;
					if (abs(s) < eps) {
						bool kt = true;
						for (size_t k = 1; k < numVertex; k++)
						{
							double t =realPieces.at(i).vertices.at((j + k) % numVertex).angle - considerPiece.vertices.at(k).angle;
							s += t;
							if (abs(t) > eps) {
								kt = false;
								break;
							}
						}
						if (kt && (abs(s / numVertex) < eps / numVertex)) fit = true;
						else {
							kt = true;
							s = realPieces.at(i).vertices.at(j).angle - considerPiece.vertices.at(0).angle;
							for (size_t k = 1; k < numVertex; k++)
							{
								double t = realPieces.at(i).vertices.at((j - k + numVertex) % numVertex).angle - considerPiece.vertices.at(k).angle;
								s += t;
								if (abs(t) > eps) {
									kt = false;
									break;
								}
							}
							if (kt && (abs(s / numVertex) < eps / numVertex)) {
								fit = true;
								flip=true;
							}
						}
					}
					if (fit) break;
				}
			}
			if (fit) {
				cout << setprecision(14)<< fixed <<s<<endl;
				if(flip)
				polylines(realImgDisp, toVectorPoint(realPieces.at(i).vertices, 1), true, Scalar(0, 255, 0), 3);
				else
				polylines(realImgDisp, toVectorPoint(realPieces.at(i).vertices, 1), true, Scalar(255, 0, 0), 3);

			}
		}
		resize(realImgDisp, realImgDisp, realImgDisp.size() / 2);
		imshow("capture", realImgDisp);
		waitKey();
		idx = (idx + 1) % (initial.pieces.size() - 1);
	} while (1);

}
