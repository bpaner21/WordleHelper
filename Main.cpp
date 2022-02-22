
#include "WordleHelper.h"

int main()
{
	// word list sourced from 
	// https://www.bestwordlist.com/5letterwords.htm
	// &
	// Wordle source code 2/7/22

	WordleHelper wH("Wordle List.txt");

	wH.mostCommonLetters();
	wH.mostCommonLettersAt(99);
	wH.mostCommonLettersAllPos(11);

	wH.mostCommonConsonants();
	wH.mostCommonConsonantsAt(99, 3);
	wH.mostCommonConsonantsAllPos(99);

	wH.mostCommonVowels();

	// Most helpful words: AROSE and UNTIL

	// Guess 1, AROSE

	return 0;
}