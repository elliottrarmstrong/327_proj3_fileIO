/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"
#include <string>

using namespace std;
using namespace KP_FileIO;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const string &filename, string &contents)
{
	ifstream file;
	file.open(filename.c_str());
	if(!file.is_open())
		return COULD_NOT_OPEN_FILE_TO_READ;
	string line;
	while(!file.eof()){
		getline(file,line);
		contents+=line;
	}
	file.close();
	return SUCCESS;
}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const string filename,vector<string> &myEntryVector)
{
	ofstream file;
	file.open(filename.c_str());
	if(!file.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	for(int i = 0; i < myEntryVector.size(); i++){
		file<<myEntryVector[i]<<endl;
	}
	file.close();
	return SUCCESS;
}


