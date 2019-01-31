#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Model.h"


std::vector<std::string> askformodels(){

	std::vector<std::string> fnames;
	unsigned number_of_files;
	std::string filename;
	std::cout<< "Input number of models to orient: ";
	std::cin >> number_of_files;
	while(!std::cin){
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout<< "Input another number: ";
		std::cin >> number_of_files;
	}
	std::cout<< "Input the names of the models, hitting enter after each one"<<std::endl;
	for(unsigned i=0; i<number_of_files; i++){
		std::string fname;
		std::cout<< "Filename ";
		std::cout<<i+1;
		std::cout<<": ";
		std::cin>> fname;
		fnames.push_back(fname);
	}

	return fnames;
}


int main(int argc, char* argv[]){

	//Ask for Models
	std::vector<std::string> filenames = askformodels();

	std::ifstream in_str;
	std::vector<Model> models;

	//First traverse through the model names and determine if they are valid. 
	//Code checking if the models are Binary or ACSII Formatted will exist here if implemented.
	for(unsigned i=0; i<filenames.size(); i++){
		in_str.open(filenames[i].c_str(), std::ios::in| std::ios::binary);
	 	while (!in_str.good()) {
	 		in_str.close();
	 		std::string newname;
	   		std::cerr << "The file " << filenames[i]<< " is invalid. Please enter it again: ";
	   		std::cin>> newname;
	   		filenames[i] = newname;
	   		in_str.open(filenames[i].c_str(), std::ios::in| std::ios::binary);
  		}
  		in_str.close();
	}

	// for(unsigned i=0; i<filenames.size();i++){
	// 	std::cout<< filenames[i]<<std::endl;
	// }

	for(unsigned i=0; i<filenames.size(); i++){
		Model temp;
		temp.extractdata(filenames[i]);
		temp.printboundaries();
		models.push_back(temp);
	}
}