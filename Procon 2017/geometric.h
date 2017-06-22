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
	};

	double compute_angle(const Point& A, const Point& O, const Point& B);
}