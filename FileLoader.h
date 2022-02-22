#pragma once

#include "ScoredWord.h"
#include <vector>
#include <fstream>
#include <iostream>

class FileLoader
{
private:
	std::string _fileName = ""; // name of text file to parse



protected:
	FileLoader();

public:
	FileLoader(std::string fileName);

	void wordsFromFile(std::vector<ScoredWord> &words); // open input file and write words to string vector
};

