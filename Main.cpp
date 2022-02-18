
#include "WordleHelper.h"

int main()
{
	// word list sourced from 
	// https://www.bestwordlist.com/5letterwords.htm
	// &
	// Wordle source code

	WordleHelper wH("Wordle List.txt");

	wH.mostCommonLetters(10);
	//wH.mostCommonConsonants();
	//wH.mostCommonVowels();

	//wH.mostCommonLettersAllPos(10);
	//wH.mostCommonConsonantsAllPos(10);
	//wH.mostCommonVowelsAllPos();

	/*while (wH.IsRunning())
	{
		wH.input();
	}//*/

	//wH.input();

	// Guess 1, "AROSE" 
	// Guess 2, "UNTIL"
	
	wH.right("ASEL");

	wH.remove("ROUNTI");

	wH.removeAt('A', 0);

	wH.removeAt('S', 3);

	wH.rightAt('E', 4);

	return 0;
}