#ifndef __Point__h_
#define __Point__h_

#include <iostream>

class Point{
public:
	//Point();
	Point(const float& xcoord, const float& ycoord, const float& zcoord);
	Point(const float& xcoord, const float& ycoord); //Constructor for 2d point
	
	//accessor
	float getx()const;
	float gety()const;
	float getz()const;

	void printpoint() const;
	
private:
	float x;
	float y;
	float z;
};

#endif