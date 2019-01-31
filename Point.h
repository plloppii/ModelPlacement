#include <iostream>

class Point{
public:
	Point(const float& xcoord, const float& ycoord, const float& zcoord);

	void printpoint() const;
	
private:
	float x;
	float y;
	float z;
};