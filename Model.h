#ifndef __Model__h_
#define __Model__h_

#include <iostream>
#include <vector>
#include "Triangle.h"

class Model{

  public:
    Model();
    Model(float x1, float x2,float y1, float y2,float z1, float z2);
    Model(float w, float l);

    float getwidth() const {return width;}
    float getlength() const {return length;}
    float getheight() const {return height;}
    float getarea() const {return area;}

    Triangle extracttriangles(std::ifstream& instring);
    void extractdata(std::string inputfile);
    void checkboundaries(const Point& v);
    void printboundaries();
    void printdimensions();

  private:
    std::string name;

    float xmin;
    float xmax;
    float ymin;
    float ymax;
    float zmin;
    float zmax;

    float width;
    float length;
    float height;
    float area;

    std::vector<Triangle> triangles;

};

#endif