#include <iostream>
#include <vector>
#include "Point.h"

class Triangle{
public:
	Triangle(const Point& norm, const Point& vertex1, const Point& vertex2, const Point& vertex3);

	void printtri() const;

private:
	Point normal;
	Point v1;
	Point v2;
	Point v3;


};