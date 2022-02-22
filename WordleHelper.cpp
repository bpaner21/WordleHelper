#include "WordleHelper.h"

//---
// Constructors

WordleHelper::WordleHelper() {}

WordleHelper::WordleHelper(std::string fileName) : _fL(new FileLoader(fileName))
{
	// read words from file to string vector
	_fL->wordsFromFile(_words);

	// parse words and count letters
	_lC = new LetterCounter(_words);

	_lC->setTScore(_tScore);

	_scoreAndSort(_words);

	_dictionarySize = _words.size();

	_numGuess = _words.size();

	std::cout << "\nWords Scored and Weighed\n";

	std::cout << "\n" << _defaultListSize << " Highest Scoring Words:\n";

	for (int i = 0; i < _defaultListSize; ++i)
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
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].word.size(); ++j)
		{
			v[i].score += _tScore[v[i].word[j] - 'A'];
		}
	}

	std::sort(v.begin(), v.end(), [](const ScoredWord& a, const ScoredWord& b) { return a.score > b.score; });

	return;
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
	for (ScoredWord s : _words)
	{
		s.validGuess = true;
	}

	_numGuess = _dictionarySize;

	return;
}

// remove words with incorrect letters from guess list
void WordleHelper::remove(const std::string &incorrectLetters)
{
	for (ScoredWord w : _words)
	{
		for (char ch : incorrectLetters)
		{
			if (w.word.find(ch) != std::string::npos)
			{
				w.validGuess = false;

				--_numGuess;

				break;
			}
		}
	}

	int display = _numGuess >= _defaultListSize ? _defaultListSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing \"" << incorrectLetters << "\":\n";

	int i = 0;

	for (int i = 0, j = 0; i < _words.size() && j < display; ++i)
	{
		if (_words[i].validGuess)
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (i + 1) << ". " << _words[i].word << ": " << _words[i].score << " points\n";

			++j;
		}
	}

	std::cout << "\n" << _numGuess << " words remaining.\n";

	return;
}

// remove words without correct letters from guess list
void WordleHelper::right(const std::string &correctLetters)
{
	for (ScoredWord s : _words)
	{
		for (char ch : correctLetters)
		{
			if (s.word.find(ch) == std::string::npos)
			{
				s.validGuess = false;

				--_numGuess;
			}

			if (!s.validGuess) { break; }
		}
	}

	int display = _numGuess >= _defaultListSize ? _defaultListSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words without \"" << correctLetters << "\":\n";

	for (int i = 0, j = 0; i < _words.size() && j < display; ++i)
	{
		if (_words[i].validGuess)
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (i + 1) << ". " << _words[i].word << ": " << _words[i].score << " points\n";

			++j;
		}
	}

	std::cout << "\n" << _numGuess << " words remaining.\n";

	return;
}

// remove words with correct letter at incorrect position
void WordleHelper::removeAt(char letter, int position)
{
	for (ScoredWord s : _words)
	{
		if (s.word[position] == letter) 
		{ 
			s.validGuess = false;

			--_numGuess;
		}
	}

	int display = _numGuess >= _defaultListSize ? _defaultListSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words with \'" << letter << "\' at Position " << position << ":\n";

	for (int i = 0, j = 0; i < _words.size() && j < display; ++i)
	{
		if (_words[i].validGuess)
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (i + 1) << ". " << _words[i].word << ": " << _words[i].score << " points\n";

			++j;
		}
	}

	std::cout << "\n" << _numGuess << " words remaining.\n";

	return;
}

// remove words without correct letter at correct position
void WordleHelper::rightAt(char letter, int position)
{
	for (ScoredWord s : _words)
	{
		if (s.word[position] != letter) 
		{ 
			s.validGuess = false; 

			--_numGuess;
		}
	}

	int display = _numGuess >= _defaultListSize ? _defaultListSize : _numGuess;

	std::cout << "\n" << display << " Highest Scoring Words after removing words without \'" << letter << "\' at Position " << position << ":\n";

	for (int i = 0, j = 0; i < _words.size() && j < display; ++i)
	{
		if (_words[i].validGuess)
		{
			std::cout << std::fixed << std::setw(2) << std::setfill('0');
			std::cout << (i + 1) << ". " << _words[i].word << ": " << _words[i].score << " points\n";

			++j;
		}
	}

	std::cout << "\n" << _numGuess << " words remaining.\n";

	return;
}

//---
// File Opening

//---
// Letter Counting

void WordleHelper::mostCommonLetters(int numLetters)
{
	_lC->mostCommonLetters(numLetters);

	return;
}

void WordleHelper::mostCommonLettersAt(int position, int numLetters)
{
	_lC->mostCommonLettersAt(position, numLetters);

	return;
}

void WordleHelper::mostCommonLettersAllPos(int numLetters)
{
	_lC->mostCommonLettersAllPos(numLetters);

	return;
}

//---

void WordleHelper::mostCommonConsonants(int numLetters)
{
	_lC->mostCommonConsonants(numLetters);

	return;
}

void WordleHelper::mostCommonConsonantsAt(int position, int numLetters)
{
	_lC->mostCommonConsonantsAt(position, numLetters);

	return;
}

void WordleHelper::mostCommonConsonantsAllPos(int numLetters)
{
	_lC->mostCommonConsonantsAllPos(numLetters);

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
	_lC->mostCommonVowelsAt(position);

	return;
}

void WordleHelper::mostCommonVowelsAllPos()
{
	_lC->mostCommonVowelsAllPos();

	return;
}