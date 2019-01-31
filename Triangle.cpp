#include <iostream>
#include <vector>
#include "Triangle.h"


Triangle::Triangle(const Point& norm, const Point& vertex1, const Point& vertex2, const Point& vertex3)
		:normal(norm), v1(vertex1), v2(vertex2), v3(vertex3)
	{}

void Triangle::printtri() const{
	std::cout<< "N:";
	normal.printpoint();
	std::cout<< " V1: ";
	v1.printpoint();
	std::cout<< " V2: ";
	v2.printpoint();
	std::cout<< " V3: ";
	v3.printpoint();
	std::cout<<std::endl;
}