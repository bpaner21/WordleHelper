#include "FileLoader.h"

//---
// Constructors

FileLoader::FileLoader() {}

FileLoader::FileLoader(std::string fileName) : _fileName(fileName) {}

//---
// Open File
void FileLoader::wordsFromFile(std::vector<std::string> &words)
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

		std::string word;

		while (!text.eof())
		{
			getline(text, word, ' ');

			words.push_back(word);
		}
	}

	text.close();

	return;
}