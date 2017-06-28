#pragma once
#define PI 3.14159265358979323846
#include <iostream>
using namespace std;

namespace geometric
{
	class Point
	{
	public:
		int x, y;
		Point(int x = 0, int y = 0);
		Point operator+(const Point&);
		Point operator-(const Point&);
		int operator*(const Point&);
		bool operator==(const Point&);
		double length();
		bool rotate(double angle, Point center);
		void print();
	};

	int orientation(const Point& A, const Point& O, const Point& B);
	double compute_angle(Point A, Point O, Point B);
	bool onSegment(Point p, Point q, Point r);
	bool equal(double d, double e);
}