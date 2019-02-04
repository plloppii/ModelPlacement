#include "Point.h"

//3D point
Point::Point(const float& xcoord, const float& ycoord, const float& zcoord)
	:x(xcoord), y(ycoord), z(zcoord)
{}	

//2D point
Point::Point(const float& xcoord, const float& ycoord)
	:x(xcoord), y(ycoord), z(0)
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