#include <iostream>

class Point{
public:
	Point(const float& xcoord, const float& ycoord, const float& zcoord);

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