#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Triangle.h"


std::vector<std::string> askformodels(){

	std::vector<std::string> fnames;
	unsigned number_of_files;
	std::string filename;
	std::cout<< "Input number of models to orient: ";
	std::cin >> number_of_files;
	std::cout<< "Input the names of the models, hitting enter after each one"<<std::endl;
	for(unsigned i=0; i<number_of_files; i++){
		std::string fname;
		std::cout<< "Filename ";
		std::cout<<i+1;
		std::cout<<": ";
		std::cin>> fname;
		fnames.push_back(fname);
	}

	for(unsigned i=0; i<number_of_files; i++){
		std::cout<< fnames[i]<<std::endl;
	}

	return fnames;
}

// Format for each triangle:
// For each point: (4bytes xcoord, 4bytes ycoord, 4bytes, zcoord)
// 12byte normal vector
// 12byte vertex1 
// 12byte vertex2
// 12byte vertex3
// 2byte nothing
// Total: 50bytes
Triangle extracttriangles(std::ifstream& instring){
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

	Triangle newtri(vertex[0],vertex[1],vertex[2],vertex[3]);
	newtri.printtri();

	return newtri;


}


int main(int argc, char* argv[]){

	//Ask for Models
	//std::vector<std::string> filenames = askformodels();

	//Code checking if models are valid STL files
	//Code checking if the models are Binary or ACSII Formatted

	const std::string inputfile = argv[1];
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
  	std::cout<< buffer<<std::endl;
  	//Reading in Number of Triangles
  	in_str.read(numoftris,4);
  	unsigned int *r = (unsigned int*) numoftris;
  	unsigned int numberoftriangles = *r;
  	//unsigned int numberoftriangles = std::atoi(numoftris);
  	std::cout<< numberoftriangles<<std::endl;

  	for(unsigned i=0; i<10; i++){
  		std::cout<<"Triangle#"<<i+1<<std::endl;
  		extracttriangles(in_str);
  	}



  	// float text;
  	// while(in_str >> text){
  	// 	std::cout<< text;
  	// }


}