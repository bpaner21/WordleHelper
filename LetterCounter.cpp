#include "LetterCounter.h"

int LetterCounter::_defaultLetterCount = 5;

//---
// Constructors

LetterCounter::LetterCounter() {}

LetterCounter::LetterCounter(std::vector<ScoredWord> &wordVector)
{
	parse(wordVector);
}

//---
// Parse new lists of words

void LetterCounter::parse(std::vector<ScoredWord> &wordVector)
{
	if (_parsed) 
	{ 
		mostCommonLetters(); 
		return; 
	}

	// clear letter counts
	for (int i = 0; i < 26; ++i)
	{
		std::pair<int, char> newPair(0, 'A' + i);

		_tlc[i] = newPair;

		for (int j = 0; j < 5; ++j) 
		{ 
			_plc[j][i] = newPair; 
		
			_pScore[j].fill(0);
		}
	}

	// count letters
	for (int k = 0; k < wordVector.size(); ++k) 
	{
		for (int l = 0; l < 5; ++l)
		{
			int letter = wordVector[k].word[l] - 'A';

			// total letter count
			++_tlc[letter].first;

			// letter count at position l
			++_plc[l][letter].first;

			++_pScore[l][letter];
		}
	}

	// sort counts in descending order
	std::cout << "\n- Sorting " << wordVector.size() << " total words. - \n";

	std::sort(_tlc.begin(), _tlc.end(),
		[](const auto& a, const auto& b) { return a.first > b.first; });


	for (int m = 0; m < 5; ++m) 
	{
		std::cout << "- Sorting letters at Position " << m << " -\n";

		std::sort(_plc[m].begin(), _plc[m].end(),
			[](const auto& a, const auto& b) { return a.first > b.first; });
	}

	_parsed = true;

	// confirm letter counts are accurate
	/*
	int sumT = 0, sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

	for (int n = 0; n < 26; ++n)
	{
		sumT += _tlc[n].first;
		sum0 += _plc[0][n].first;
		sum1 += _plc[1][n].first;
		sum2 += _plc[2][n].first;
		sum3 += _plc[3][n].first;
		sum4 += _plc[4][n].first;
	}

	std::cout << "\nTotal: " << sumT
		<< "\nPosition 0: " << sum0
		<< "\nPosition 1: " << sum1
		<< "\nPosition 2: " << sum2
		<< "\nPosition 3: " << sum3
		<< "\nPosition 4: " << sum4 << "\n";

	//*/

	return;
}

void LetterCounter::parseNewText(std::vector<ScoredWord> &newVector)
{
	_parsed = false;

	parse(newVector);

	return;
}

void LetterCounter::setTScore(std::array<int, 26>& tScore)
{
	for (int i = 0; i < 26; ++i)
	{
		tScore[_tlc[i].second - 'A'] = _tlc[i].first;
	}

	return;
}

//---
// Letter Count

void LetterCounter::_mcl(const std::array<std::pair<int, char>, 26> &arr, int numLetters)
{
	if (numLetters < 0) { numLetters = 5; }
	if (numLetters > 26) { numLetters = 26; }

	for (int i = 0; i < numLetters; ++i)
	{
		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << arr[i].second << ": " << arr[i].first << " points\n";
	}

	return;
}

void LetterCounter::mostCommonLetters(int numLetters)
{
	std::cout << "\n" << numLetters << " Most common letters:\n";

	_mcl(_tlc, numLetters);

	return;
}

void LetterCounter::mostCommonLettersAt(int position, int numLetters)
{
	if (position < 0) { position = 0; }
	if (position > 4) { position = 4; }

	std::cout << "\n" << numLetters << " Most common letters at Position " << position << ":\n";

	_mcl(_plc[position], numLetters);

	return;
}

void LetterCounter::mostCommonLettersAllPos(int numLetters) {

	for (int i = 0; i < 5; ++i)
	{
		mostCommonLettersAt(i, numLetters);
	}

	return;
}

//---
// Consonant Count

void LetterCounter::_mcc(const std::array<std::pair<int, char>, 26> &arr, int numLetters)
{
	if (numLetters < 0) { numLetters = 5; }
	if (numLetters > 21) { numLetters = 21; }

	int i = 0, count = 0;

	while (count < numLetters && i < 26) 
	{
		if (_vowels.find(arr[i].second) == std::string::npos) 
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (count + 1) << ". " << arr[i].second << ": " << arr[i].first << " points\n";

			++count;
		}

		++i;
	}

	return;
}

void LetterCounter::mostCommonConsonants(int numLetters)
{
	std::cout << "\n" << numLetters << " Most common consonants:\n";

	_mcc(_tlc, numLetters);

	return;
}

void LetterCounter::mostCommonConsonantsAt(int position, int numLetters)
{
	if (position < 0) { position = 0; }
	if (position > 4) { position = 4; }

	std::cout << "\n" << numLetters << " Most common consonants at Position " << position << ":\n";

	_mcc(_plc[position], numLetters);

	return;
}

void LetterCounter::mostCommonConsonantsAllPos(int numLetters) {

	for (int i = 0; i < 5; ++i)
	{
		mostCommonConsonantsAt(i, numLetters);
	}

	return;
}

//---
// Vowel Count

void LetterCounter::_mcv(const std::array<std::pair<int, char>, 26> &arr, int numLetters)
{
	int i = 0, count = 0;

	while (count < numLetters && i < 26) 
	{
		if (_vowels.find(arr[i].second) != std::string::npos)
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (count + 1) << ". " << arr[i].second << ": " << arr[i].first << " points\n";

			++count;
		}

		++i;
	}

	return;
}

void LetterCounter::mostCommonVowels()
{
	std::cout << "\nMost common vowels:\n";

	_mcv(_tlc, 5);

	return;
}

void LetterCounter::mostCommonVowelsAt(int position)
{
	if (position < 0) { position = 0; }
	if (position > 4) { position = 4; }

	std::cout << "\nMost common vowels at Position " << position << ":\n";

	_mcc(_plc[position], 5);

	return;
}

void LetterCounter::mostCommonVowelsAllPos() {

	for (int i = 0; i < 5; ++i)
	{
		mostCommonVowelsAt(i);
	}

	return;
}