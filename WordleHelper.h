#pragma once

#include <algorithm>
#include <sstream>
#include <unordered_set>

#include "ScoredWord.h"
#include "FileLoader.h"
#include "LetterCounter.h"

class WordleHelper
{
private:
	static int _wordLength;

	static int _listSize;

	bool _isRunning = true;

	// made extensible for wordle clones that might use longer or shorter words
	std::vector<std::string> _place { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};

	std::vector<std::string> _input{ "REMOVE", "RIGHT", "RIGHTAT", "RESET", "EXIT" };

	std::vector<ScoredWord> _words {};

	std::array<int, 26> _tScore{ 0 }; // total count of letters, used for sorting

	int _dictionarySize = 0; // total number of words

	int _numGuess = 0; // number of words that may still be the answer

	void _scoreAndSort(std::vector<ScoredWord> &v);

	// loads input file and writes words to string vector 
	// runs once to set up letter counter and word tracker
	FileLoader *_fL = nullptr; 

	// calculates count of letters used from words both cumulatively and at specific positions
	// runs once each time a new word list is loaded
	LetterCounter *_lC = nullptr;

	// keeps track of which words may be the answer based on previous guesses
	// words are deleted as new information is provided
	// track list is reset when a new game is started

protected:
	WordleHelper();

public:
	WordleHelper(std::string fileName);

	bool IsRunning() { return _isRunning; }

	void input();

	void reset();

	void remove(const std::string &incorrectLetters); // remove words with incorrect letters from guess list

	void right(const std::string &correctLetters); // remove words without correct letters from guess list

	void removeAt(int position, char letter); // remove words with correct letter at incorrect position

	void rightAt(int position, char letter); // remove words without correct letter at correct position

	void narrow(const std::string &correctLetters); // suggest words without any of the correct letters help find an answer

	void displayRemaining(int displaySize);

	//---
	// File Loading

	//---
	// Letter Counting

	void mostCommonLetters(int listSize = _listSize);

	void mostCommonLettersAt(int position = 0, int listSize = _listSize);

	void mostCommonLettersAllPos(int listSize = _listSize);

	//---

	void mostCommonConsonants(int listSize = _listSize);

	void mostCommonConsonantsAt(int position, int listSize = _listSize);

	void mostCommonConsonantsAllPos(int listSize = _listSize);

	//---

	void mostCommonVowels();

	void mostCommonVowelsAt(int position = 0);

	void mostCommonVowelsAllPos();
};

