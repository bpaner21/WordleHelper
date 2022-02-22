#pragma once

#include <algorithm>
#include <sstream>

#include "FileLoader.h"
#include "LetterCounter.h"

class WordleHelper
{
private:
	bool _isRunning = true;

	std::vector<std::string> _input{ "REMOVE", "RIGHT", "RIGHTAT", "RESET", "EXIT" };

	std::vector<ScoredWord> _words {};

	static std::array<int, 26> _tScore; // total count of letters, used for sorting

	int _dictionarySize = 0; // total number of words

	int _numGuess = 0; // number of words that may still be the answer

	const int _defaultListSize = 10;

	static bool tScoreCompare(const ScoredWord &a, const ScoredWord &b);

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

	void removeAt(char letter, int position); // remove words with correct letter at incorrect position

	void rightAt(char letter, int position); // remove words without correct letter at correct position

	void narrow(const std::string &correctLetters); // suggest words without any of the correct letters help find an answer

	//---
	// File Loading

	//---
	// Letter Counting

	void mostCommonLetters(int numLetters = LetterCounter::DefaultLetterCount());

	void mostCommonLettersAt(int position = 0, int numLetters = LetterCounter::DefaultLetterCount());

	void mostCommonLettersAllPos(int numLetters = LetterCounter::DefaultLetterCount());

	//---

	void mostCommonConsonants(int numLetters = LetterCounter::DefaultLetterCount());

	void mostCommonConsonantsAt(int position, int numLetters = LetterCounter::DefaultLetterCount());

	void mostCommonConsonantsAllPos(int numLetters = LetterCounter::DefaultLetterCount());

	//---

	void mostCommonVowels();

	void mostCommonVowelsAt(int position = 0);

	void mostCommonVowelsAllPos();
};

