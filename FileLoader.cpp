#include "FileLoader.h"

//---
// Constructors

FileLoader::FileLoader() {}

FileLoader::FileLoader(std::string fileName) : _fileName(fileName) {}

//---
// Open File
void FileLoader::wordsFromFile(std::vector<ScoredWord> &words)
{
	std::ifstream text;
	text.open(_fileName);

	if (!text.good())
	{
		std::cout << "\nInput filename \"" + _fileName + "\" not found.\n";
	}
	else
	{
		std::cout << "\nInput filename \"" + _fileName + "\" found\n";

		words.clear();

		std::string s;

		while (!text.eof())
		{
			getline(text, s, ' ');

			words.push_back(ScoredWord(s));
		}
	}

	text.close();

	return;
}