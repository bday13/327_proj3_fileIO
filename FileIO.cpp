/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream myFile;
	myFile.open(filename);

	if (!myFile.is_open()) {
		myFile.clear();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string str;
	contents = "";

	while (!myFile.eof()) {
		getline(myFile, str, '\n');
		contents.append(str);
	}

	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myFile;
	myFile.open(filename);

	if (!myFile.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	for (unsigned int i = 0; i < myEntryVector.size(); i++) {
		myFile << myEntryVector[i] << endl;
	}

	return SUCCESS;
}


