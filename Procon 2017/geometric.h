#pragma once

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
		double length();
	};

	double compute_angle(Point A, Point O, Point B);
}