#include "Geometric.h"

geometric::Point geometric::Point::operator+(const geometric::Point& other)
{
	return geometric::Point(this->x + other.x, this->y + other.y);
}

geometric::Point geometric::Point::operator-(const geometric::Point& other)
{
	return geometric::Point(this->x - other.x, this->y - other.y);
}

geometric::Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

double geometric::compute_angle(const geometric::Point& A, const geometric::Point& O, const geometric::Point& B)
{
	return 3;
}