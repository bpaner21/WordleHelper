
#include "WordleHelper.h"

int main()
{
	// word list sourced from 
	// https://www.bestwordlist.com/5letterwords.htm
	// &
	// Wordle source code 2/7/22

	WordleHelper wH("Wordle List.txt");

	//wH.mostCommonLetters();
	//wH.mostCommonLettersAt(99);
	//wH.mostCommonLettersAllPos(11);

	//wH.mostCommonConsonants();
	//wH.mostCommonConsonantsAt(99, 3);
	//wH.mostCommonConsonantsAllPos(99);

	//wH.mostCommonVowels();

	// Most helpful words: AROSE and UNTIL
	// 
	// Most efficient order:
	// 1. rightAt()
	// 2. right()
	// 3. removeAt()
	// 4. remove()

	// Guess 1, AROSE

	wH.right("O");			// 3911 words (30.15%) remaining.
	wH.removeAt(2, 'O');	// 2918 words (22.49%) remaining.
	wH.remove("ARSE");		// 463 words (3.57%) remaining.

	// Guess 2, DOILT

	wH.rightAt(1, 'O');		// 307 words (2.37%) remaining.
	wH.right("D");			// 63 words (0.49%) remaining.
	wH.removeAt(0, 'D');	// 40 words (0.31%) remaining.
	wH.remove("ILT");		// 20 words (0.15%) remaining.

	// Guess 3, POUND

	wH.rightAt(2, 'U');		// 6 words (0.05%) remaining.
	wH.rightAt(3, 'N');		// 6 words (0.05%) remaining.
	wH.rightAt(4, 'D');		// 6 words (0.05%) remaining.
	wH.remove("P");			// 5 words (0.04%) remaining.

	// Guess 4, WHELM

	wH.remove("WHM");		// 2 words (0.02%) remaining.

	// Guess 5, BOUND

	wH.remove("B");			// 1 words (0.01%) remaining.

	// Guess 6, FOUND
	// Correct

	return 0;
}