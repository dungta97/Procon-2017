#include "Geometric.h"
#include <math.h>
#define PI 3.14159265358979323846

geometric::Point geometric::Point::operator+(const geometric::Point& other)
{
	return geometric::Point(this->x + other.x, this->y + other.y);
}

geometric::Point geometric::Point::operator-(const geometric::Point& other)
{
	return geometric::Point(this->x - other.x, this->y - other.y);
}

int geometric::Point::operator*(const Point& other)
{
	return this->x * other.x + this->y * other.y;
}

double geometric::Point::length()
{
	return sqrt(x*x + y*y);
}

geometric::Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

double geometric::compute_angle(geometric::Point A, geometric::Point O, geometric::Point B)
{
	geometric::Point vOA = A - O;
	geometric::Point vOB = B - O;
	double dOA = vOA.length();
	double dOB = vOB.length();
	double res = acos((vOA * vOB) / (dOA * dOB));
	res = res * 360 / 2 / PI;

	int c = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
	if (c > 0) res = 360 - res;
	return res;
}