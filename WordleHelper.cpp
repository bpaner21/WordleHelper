#include "WordleHelper.h"

//---
// Static Members

std::array<int, 26> WordleHelper::_tScore { 0 };

bool WordleHelper::tScoreCompare(const std::string &a, const std::string &b)
{
	int sA = 0, sB = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		sA += _tScore[a[i] - 'A'];
		sB += _tScore[b[i] - 'A'];
	}

	return sA > sB;
}

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

	_scoreSort(_words);

	_guess = _words;

	std::cout << "\nWords Scored and Weighed\n";

	std::cout << "\n" << _defaultListSize << " Highest Scoring Words:\n";

	for (int i = 0; i < _defaultListSize; ++i)
	{
		//std::cout << i << ". " << _words[i] << "\n";

		//*
		int score = 0;

		for (int j = 0; j < 5; ++j)
		{
			score += _tScore[_words[i][j] - 'A'];
		}

		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << _words[i] << ": " << score << " points\n"; 
		//*/
	}
}

//--
// Find answer

void WordleHelper::_scoreSort(std::vector<std::string>& v)
{
	std::sort(v.begin(), v.end(), tScoreCompare);

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
	_guess.clear();

	_guess = _words;

	return;
}

// remove words with incorrect letters from guess list
void WordleHelper::remove(const std::string &incorrectLetters)
{
	std::vector<std::string> temp{};

	bool validGuess;

	for (std::string g : _guess)
	{
		validGuess = true;

		for (char ch : incorrectLetters)
		{
			if (!validGuess) { break; }

			if (g.find(ch) != std::string::npos)
			{
				validGuess = false;
			}
		}

		if (validGuess) { temp.push_back(g); }
	}

	_guess = temp;

	int display = _guess.size() >= _defaultListSize ? _defaultListSize : _guess.size();

	std::cout << "\n" << display << " Highest Scoring Words after removing \"" << incorrectLetters << "\":\n";

	for (int i = 0; i < display; ++i)
	{
		//std::cout << i << ". " << _words[i] << "\n";

		//*
		int score = 0;

		for (int j = 0; j < 5; ++j)
		{
			score += _tScore[_guess[i][j] - 'A'];
		}

		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << _guess[i] << ": " << score << " points\n";
		//*/
	}

	std::cout << "\n" << _guess.size() << " words remaining.\n";

	return;
}

// remove words without correct letters from guess list
void WordleHelper::right(const std::string &correctLetters)
{
	std::vector<std::string> temp{};

	bool validGuess;

	for (std::string g : _guess)
	{
		validGuess = true;

		for (char ch : correctLetters)
		{
			if (!validGuess) { break; }

			if (g.find(ch) == std::string::npos)
			{
				validGuess = false;
			}
		}

		if (validGuess) { temp.push_back(g); }
	}

	_guess = temp;

	int display = _guess.size() >= _defaultListSize ? _defaultListSize : _guess.size();

	std::cout << "\n" << display << " Highest Scoring Words after removing words without \"" << correctLetters << "\":\n";

	for (int i = 0; i < display; ++i)
	{
		//std::cout << i << ". " << _words[i] << "\n";

		//*
		int score = 0;

		for (int j = 0; j < 5; ++j)
		{
			score += _tScore[_guess[i][j] - 'A'];
		}

		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << _guess[i] << ": " << score << " points\n";
		//*/
	}

	std::cout << "\n" << _guess.size() << " words remaining.\n";

	return;
}

// remove words with correct letter at incorrect position
void WordleHelper::removeAt(char letter, int position)
{
	std::vector<std::string> temp{};

	bool validGuess;

	for (std::string g : _guess)
	{
		validGuess = true;

		if (g[position] == letter) { validGuess = false; }

		if (validGuess) { temp.push_back(g); }
	}

	_guess = temp;

	int display = _guess.size() >= _defaultListSize ? _defaultListSize : _guess.size();

	std::cout << "\n" << display << " Highest Scoring Words after removing words with \'" << letter << "\' at Position " << position << ":\n";

	for (int i = 0; i < display; ++i)
	{
		//std::cout << i << ". " << _words[i] << "\n";

		//*
		int score = 0;

		for (int j = 0; j < 5; ++j)
		{
			score += _tScore[_guess[i][j] - 'A'];
		}

		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << _guess[i] << ": " << score << " points\n";
		//*/
	}

	std::cout << "\n" << _guess.size() << " words remaining.\n";

	return;
}

// remove words without correct letter at correct position
void WordleHelper::rightAt(char letter, int position)
{
	std::vector<std::string> temp{};

	bool validGuess;

	for (std::string g : _guess)
	{
		validGuess = true;

		if (g[position] != letter) { validGuess = false; }

		if (validGuess) { temp.push_back(g); }
	}

	_guess = temp;

	int display = _guess.size() >= _defaultListSize ? _defaultListSize : _guess.size();

	std::cout << "\n" << display << " Highest Scoring Words after removing words without \'" << letter << "\' at Position " << position << ":\n";

	for (int i = 0; i < display; ++i)
	{
		//std::cout << i << ". " << _words[i] << "\n";

		//*
		int score = 0;

		for (int j = 0; j < 5; ++j)
		{
			score += _tScore[_guess[i][j] - 'A'];
		}

		std::cout << std::fixed << std::setw(2) << std::setfill('0');
		std::cout << (i + 1) << ". " << _guess[i] << ": " << score << " points\n";
		//*/
	}

	std::cout << "\n" << _guess.size() << " words remaining.\n";

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