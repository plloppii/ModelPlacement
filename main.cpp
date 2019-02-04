#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Buildplatform.h"

std::vector<std::string> askforfiles(){
	std::vector<std::string> fnames;
	unsigned int number_of_files;
	std::string filename;
	std::cout<< "Input number of models to orient: ";
	std::cin >> number_of_files;

	//Error checking if input is not a unsigned int. 
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

//First traverse through the model names and determine if they are valid. 
//Code checking if the models are Binary or ACSII Formatted will exist here if implemented.
bool validate_files(std::vector<std::string> &filenames){
	std::ifstream in_str;
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
	return true;
}


int main(int argc, char* argv[]){

	//Ask for file names
	std::vector<std::string> filenames = askforfiles();

	//Validate that files can be opened
	bool validfiles = validate_files(filenames); //Always returns true with current implementation 
	if(!validfiles) { 
		std::cout<<"Files cannot be read."<<std::endl; 
		exit(1);
	}

	std::vector<Model> models;
	for(unsigned i=0; i<filenames.size(); i++){
		Model temp;
		temp.extractdata(filenames[i]);
		temp.printdimensions();
		models.push_back(temp);
	}
	// std::vector<Model> mods;
	// Model m1(70,170);
	// mods.push_back(m1);
	// Model m2(30,60);
	// mods.push_back(m2);
	// Model m3(25,63);
	// mods.push_back(m3);
	Buildplatform butt(200,200,models);
	butt.createrootnode();





}