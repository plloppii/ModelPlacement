#include <iostream>
#include <vector>
#include "Triangle.h"

class Model{

  public:
    Model();
    Model(float x1, float x2,float y1, float y2,float z1, float z2);
    Triangle extracttriangles(std::ifstream& instring);
    void extractdata(std::string inputfile);
    void checkboundaries(const Point& v);
    void printboundaries() const;

  private:
    float xmin;
    float xmax;
    float ymin;
    float ymax;
    float zmin;
    float zmax;
    std::vector<Triangle> triangles;

};