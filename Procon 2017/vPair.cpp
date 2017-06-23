#include "vPair.h"
#include <algorithm>
using namespace std;

vPair::vPair(Vertex * a, Vertex * b)
{
	this->a = a;
	this->b = b;
	compatibility = 0;
}
