#include "vPair.h"

vPair::vPair(Vertex * a, Vertex * b)
{
	this->a = a;
	this->b = b;
	this->get_compatibility();
}

void vPair::get_compatibility()
{
	compatibility = 0;
}
