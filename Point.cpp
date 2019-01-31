#include "Point.h"

Point::Point(const float& xcoord, const float& ycoord, const float& zcoord)
	:x(xcoord), y(ycoord), z(zcoord)
{}	

float Point::getx()const{
	return x;
}
float Point::gety()const{
	return y;
}
float Point::getz()const{
	return z;
}

void Point::printpoint()const{
	std::cout<<x<<","<<y<<","<<z<<" ";
}