#include "Geometric.h"
#include <math.h>
#include <algorithm>
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

bool geometric::Point::operator==(const Point &other)
{
	return (x == other.x) && (y == other.y);
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

bool geometric::Point::rotate(double angle, Point center)
{
	Point tmp = *this - center;

	double c = cos(angle);
	double s = sin(angle);

	double xnew = tmp.x * c - tmp.y * s;
	double ynew = tmp.x * s + tmp.y * c;

	if (!equal(xnew, round(xnew)) || !equal(ynew, round(ynew))) return false;

	x = round(xnew) + center.x;
	y = round(ynew) + center.y;
	return true;
}

void geometric::Point::print()
{
	cout << x << " " << y << " ";
}

int geometric::orientation(const Point& A, const Point& O, const Point& B)
{
	// result: < 0 if clockwise, > 0 if counter clockwise, == 0 if collinear.
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double geometric::compute_angle(Point A, Point O, Point B)
{
	if ((A == O) || (B == O)) return 0;
	geometric::Point vOA = A - O;
	geometric::Point vOB = B - O;
	double dOA = vOA.length();
	double dOB = vOB.length();
	double res = acos((vOA * vOB) / (dOA * dOB));

	int c = geometric::orientation(A, O, B);
	if (c > 0) res = 2 * PI - res;
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

bool geometric::equal(double d, double e)
{
	return abs(d - e) < 1e-6;
}