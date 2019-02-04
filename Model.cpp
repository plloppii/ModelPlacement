#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Model.h"

Model::Model(){
	xmin = 1e+30;
	xmax = 1e-30;
	ymin = 1e+30;
	ymax = 1e-30;
	zmin = 1e+30;
	zmax = 1e-30;
}

Model::Model(float x1, float x2,float y1, float y2,float z1, float z2){
	xmin = x1;
	xmax = x2;
	ymin = y1;
	ymax = y2;
	zmin = z1;
	zmax = z2;
}

Model::Model(float w, float l){
	width = w;
	length = l;
	area = width*length;
}

//input extracts header, data of triangles,and all of the triangles
//sets boundary conditions for the model. 
//adds triangles to the triangle vector
void Model::extractdata(std::string inputfile){
	name = inputfile;
	std::cout<< name<<std::endl;

	char buffer[80];
	char numoftris[4];

	std::ifstream in_str;
	in_str.open(inputfile.c_str(), std::ios::in| std::ios::binary);
 	if (!in_str.good()) {
   		std::cerr << "Can't open " << inputfile<< " to read.\n";
    	exit(1);
  	}

  	//Reading in Header[80 bytes]
  	in_str.read(buffer,80);
  	//Reading in Number of Triangles
  	in_str.read(numoftris,4);
  	unsigned int numberoftriangles = *((unsigned int*) numoftris);

  	for(unsigned i=0; i<numberoftriangles; i++){
  		Triangle tri = extracttriangles(in_str);
  		triangles.push_back(tri);
  	}
  	width = xmax - xmin;
  	length = ymax - ymin;
  	height = zmax - zmin;
  	area = width * length;
}


// Format for each triangle:
// For each point: (4bytes xcoord, 4bytes ycoord, 4bytes, zcoord)
// 12byte normal vector
// 12byte vertex1 
// 12byte vertex2
// 12byte vertex3
// 2byte nothing
// Total: 50bytes
Triangle Model::extracttriangles(std::ifstream& instring){
	std::vector<Point> vertex;
	std::vector<float> coord;
	//std::vector<Triangle> something;
	char buff[sizeof(float)];
	//Loop through Vertex
	//4 Verticies, 3 coords each
	for (unsigned i=0; i<4; i++){
		//Loop through each Coord for each Vertex
		//3 coords, 4bytes each
		for(unsigned j=0; j<3;j++){
			instring.read(buff,4);
			float c = *((float*) buff);
			// float* num = (float*) buff;
			// float c = *num;
			coord.push_back(c);
		}
		Point singlecoord(coord[0],coord[1],coord[2]);
		vertex.push_back(singlecoord);
		coord.clear();
	}
	vertex.clear();
	//Last two bytes are dummy bytes
	char dummy[2];
	instring.read(dummy,2);

	//Check if new verticies create new max or min. 
	checkboundaries(vertex[1]); 
	checkboundaries(vertex[2]);
	checkboundaries(vertex[3]);

	Triangle newtri(vertex[0],vertex[1],vertex[2],vertex[3]);

	return newtri;
}

void Model::checkboundaries(const Point& v){
	if(v.getx() < xmin) xmin = v.getx();
	if(v.getx() > xmax) xmax = v.getx();
	if(v.gety() < ymin) ymin = v.gety();
	if(v.gety() > ymax) ymax = v.gety();
	if(v.getz() < zmin) zmin = v.getz();
	if(v.getz() > zmax) zmax = v.getz();
}

void Model::printboundaries(){
	std::cout<< "xmin: "<< xmin << " xmax: "<<xmax<<std::endl;
	std::cout<< "ymin: "<< ymin << " ymax: "<<ymax<<std::endl;
	std::cout<< "zmin: "<< zmin << " zmax: "<<zmax<<std::endl;
}

void Model::printdimensions(){
	std::cout<< "Width: "<<width<<std::endl;
	std::cout<< "Length: "<<length<<std::endl;
	std::cout<< "Height: "<<height<<std::endl;
	std::cout<< "Area: "<<area<<std::endl;
}