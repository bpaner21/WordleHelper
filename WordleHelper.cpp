#include "WordleHelper.h"

//---
// Static Members

int WordleHelper::_wordLength = 5;

int WordleHelper::_listSize = 7;

//---
// Constructors

WordleHelper::WordleHelper() {}

WordleHelper::WordleHelper(std::string fileName) : _fL(new FileLoader(fileName))
{
	// read words from file to string vector
	_fL->wordsFromFile(_words);

	// parse words and count letters
	_lC = new LetterCounter(_words, _wordLength);

	_lC->setTScore(_tScore);

	_scoreAndSort(_words);

	_dictionarySize = _words.size();

	_numGuess = _words.size();

	std::cout << "\nWords Scored and Weighed\n";

	std::cout << "\n" << _listSize << " Highest Scoring Words:\n";

	for (int i = 0; i < _listSize; ++i)
	{
		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << _words[i].word << ": " << _words[i].score << " points\n"; 
		//*/
	}
}

//--
// Find answer

void WordleHelper::_scoreAndSort(std::vector<ScoredWord> &v)
{
	for (ScoredWord &s : v)
	{
		std::unordered_set<char> uniqueLetters {};

		for (char c : s.word)
		{
			s.score += _tScore[c - 'A'];
			uniqueLetters.emplace(c);
		}

		// put more weight towards words with more unique letters
		s.score *= uniqueLetters.size();
	}

	std::sort(v.begin(), v.end(), [](const ScoredWord& a, const ScoredWord& b) { return a.score > b.score; });

	return;
}

void WordleHelper::displayRemaining(int displaySize)
{
	for (int i = 0, j = 0; i < (int)_words.size() && j < displaySize; ++i)
	{
		if (_words[i].validGuess)
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (j + 1) << ". " << _words[i].word << ": " << _words[i].score << " points\n";

			++j;
		}
	}

	float percent = 100.0 * _numGuess / _dictionarySize;

	printf("\n%d words (%.2f%%) remaining.\n", _numGuess, percent);
}

void WordleHelper::input()
{
	std::string input, temp;

	std::vector<std::string> commands{};

	std::cout << "\nREMOVE\nRIGHT\nRIGHTAT\nRESET\nEXIT\n\nINPUT: ";

	while (true)
	{
		std::cin >> input;

		transform(input.begin(), input.end(), input.begin(), ::toupper);

		commands.push_back(input);

		if (std::cin.peek() == '\n') { break; }
	}

	if (std::find(_input.begin(), _input.end(), commands[0]) != _input.end())
	{

	}

	return;
}

// reset guess list
void WordleHelper::reset()
{
	for (ScoredWord &s : _words)
	{
		s.validGuess = true;
	}

	_numGuess = _dictionarySize;

	return;
}

// remove words with incorrect letters from guess list
void WordleHelper::remove(const std::string &incorrectLetters)
{
	for (ScoredWord &w : _words)
	{
		for (char ch : incorrectLetters)
		{
			if (w.validGuess && w.word.find(ch) != std::string::npos)
			{
				w.validGuess = false;

				--_numGuess;

				break;
			}
		}
	}

	int display = _numGuess >= _listSize ? _listSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words with the letters \"" << incorrectLetters << "\":\n";

	displayRemaining(display);

	return;
}

// remove words without correct letters from guess list
void WordleHelper::right(const std::string &correctLetters)
{
	for (ScoredWord &s : _words)
	{
		for (char ch : correctLetters)
		{
			if (s.validGuess && s.word.find(ch) == std::string::npos)
			{
				s.validGuess = false;

				--_numGuess;

				break;
			}
		}
	}

	int display = _numGuess >= _listSize ? _listSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words without the letters \"" << correctLetters << "\":\n";

	displayRemaining(display);

	return;
}

// remove words with correct letter at incorrect position
void WordleHelper::removeAt(int position, char letter)
{
	for (ScoredWord &s : _words)
	{
		if (s.validGuess && s.word[position] == letter)
		{ 
			s.validGuess = false;

			--_numGuess;
		}
	}

	int display = _numGuess >= _listSize ? _listSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words with \'" << letter << "\' as the " << _place[position] << " letter:\n";

	displayRemaining(display);

	return;
}

// remove words without correct letter at correct position
void WordleHelper::rightAt(int position, char letter)
{
	for (ScoredWord &s : _words)
	{
		if (s.validGuess && s.word[position] != letter)
		{ 
			s.validGuess = false; 

			--_numGuess;
		}
	}

	int display = _numGuess >= _listSize ? _listSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words without \'" << letter << "\' as the " << _place[position] << " letter:\n";

	displayRemaining(display);

	return;
}

//---
// File Opening

//---
// Letter Counting

void WordleHelper::mostCommonLetters(int listSize)
{
	_lC->mostCommonLetters(listSize);

	return;
}

void WordleHelper::mostCommonLettersAt(int position, int listSize)
{
	_lC->mostCommonLettersAt(position, listSize, _wordLength);

	return;
}

void WordleHelper::mostCommonLettersAllPos(int listSize)
{
	_lC->mostCommonLettersAllPos(listSize, _wordLength);

	return;
}

//---

void WordleHelper::mostCommonConsonants(int listSize)
{
	_lC->mostCommonConsonants(listSize);

	return;
}

void WordleHelper::mostCommonConsonantsAt(int position, int listSize)
{
	_lC->mostCommonConsonantsAt(position, listSize, _wordLength);

	return;
}

void WordleHelper::mostCommonConsonantsAllPos(int listSize)
{
	_lC->mostCommonConsonantsAllPos(listSize, _wordLength);

	return;
}

//---

void WordleHelper::mostCommonVowels()
{
	_lC->mostCommonVowels();

	return;
}

void WordleHelper::mostCommonVowelsAt(int position)
{
	_lC->mostCommonVowelsAt(position, _wordLength);

	return;
}

void WordleHelper::mostCommonVowelsAllPos()
{
	_lC->mostCommonVowelsAllPos(_wordLength);

	return;
}