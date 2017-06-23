#include "Geometric.h"
#include <math.h>
#include <algorithm>
#define PI 3.14159265358979323846
using namespace std;

geometric::Point geometric::Point::operator+(const Point& other)
{
	return geometric::Point(this->x + other.x, this->y + other.y);
}

geometric::Point geometric::Point::operator-(const Point& other)
{
	return geometric::Point(this->x - other.x, this->y - other.y);
}

int geometric::Point::operator*(const Point& other)
{
	return this->x * other.x + this->y * other.y;
}

double geometric::Point::length()
{
	return sqrt(x * x + y * y);
}

geometric::Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int geometric::orientation(const Point& A, const Point& O, const Point& B)
{
	// result: < 0 if clockwise, > 0 if counter clockwise, == 0 if collinear.
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double geometric::compute_angle(Point A, Point O, Point B)
{
	geometric::Point vOA = A - O;
	geometric::Point vOB = B - O;
	double dOA = vOA.length();
	double dOB = vOB.length();
	double res = acos((vOA * vOB) / (dOA * dOB));
	res = res * 360 / 2 / PI;

	int c = geometric::orientation(A, O, B);
	if (c > 0) res = 360 - res;
	return res;
}

bool geometric::onSegment(Point p, Point q, Point r)
{
	// return true if q lies on line segment pr
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}
