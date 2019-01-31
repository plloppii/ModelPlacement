#include "Point.h"

Point::Point(const float& xcoord, const float& ycoord, const float& zcoord)
	:x(xcoord), y(ycoord), z(zcoord)
{}	

void Point::printpoint()const{
	std::cout<<x<<","<<y<<","<<z<<" ";
}