#pragma once

#include "ScoredWord.h"
#include <array>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

class LetterCounter
{
private:
	static int _defaultLetterCount;

	int _wordSize = 5;

	bool _parsed = false;

	const std::string _vowels = "AEIOU";

	std::array<std::array<int, 26>, 5> _pScore {{}}; // count of each letter at each position, used for sorting

	std::array<std::pair<int, char>, 26> _tlc {}; // total count of letters across every word and position

	std::array<std::array<std::pair<int, char>, 26>, 5> _plc {{}}; // count of each letter for each position

	void _mcl(const std::array<std::pair<int, char>, 26> &arr, int numLetters); // calculate most common letters

	void _mcc(const std::array<std::pair<int, char>, 26> &arr, int numLetters); // calculate most common consonants (includes y)

	void _mcv(const std::array<std::pair<int, char>, 26> &arr, int numLetters); // calculate most common vowels (excludes y)

protected:
	LetterCounter();

public:
	LetterCounter(std::vector<ScoredWord>& vectorName);

	//---

	static int DefaultLetterCount() { return _defaultLetterCount; }

	void setTScore(std::array<int, 26> &tScore);

	const std::array<std::array<int, 26>, 5> &PScore() { return _pScore; }
	 
	//---

	void parse(std::vector<ScoredWord> &wordVector);

	void parseNewText(std::vector<ScoredWord> &newVector);

	//---

	void mostCommonLetters(int numLetters = _defaultLetterCount);

	void mostCommonLettersAt(int position, int numLetters);

	void mostCommonLettersAllPos(int numLetters);

	//---

	void mostCommonConsonants(int numLetters);

	void mostCommonConsonantsAt(int position, int numLetters);

	void mostCommonConsonantsAllPos(int numLetters);

	//---

	void mostCommonVowels();

	void mostCommonVowelsAt(int postion);

	void mostCommonVowelsAllPos();
};