
#include "WordleHelper.h"

int main()
{
	// word list sourced from 
	// https://www.bestwordlist.com/5letterwords.htm
	// &
	// Wordle source code 2/7/22

	WordleHelper wH("Wordle List.txt");

	// Most helpful words: AROSE and UNTIL

	// Guess 1, AROSE

	wH.remove("AS");

	wH.right("ROE");

	wH.removeAt('R', 1);
	wH.removeAt('O', 2);
	wH.removeAt('E', 4);

	// Guess 2, RETRO

	wH.remove("T");

	wH.rightAt('R', 0);
	wH.removeAt('E', 1);
	wH.rightAt('O', 4);

	// Guess 3, 

	return 0;
}