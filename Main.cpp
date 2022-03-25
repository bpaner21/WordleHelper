
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

	wH.right("OE");			// 1217 words remaining, 9.382%
	wH.removeAt(2, 'O');	// 1001 words remaining, 7.717%
	wH.removeAt(4, 'E');	// 746 words remaining, 5.751%
	wH.remove("ARS");		// 275 words remaining, 2.120%

	// Guess 2, TELOI

	wH.rightAt(1, 'E');		// 59 words remaining, 0.455%
	wH.rightAt(3, 'O');		// 34 words remaining, 0.262%
	wH.right("T");			// 14 words remaining, 0.108%
	wH.removeAt(0, 'T');	// 11 words remaining, 0.085%
	wH.remove("LI");		// 8 words remaining, 0.062%

	// Guess 3, DEPOT
	// Correct

	return 0;
}