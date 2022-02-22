
#include "WordleHelper.h"

int main()
{
	// word list sourced from 
	// https://www.bestwordlist.com/5letterwords.htm
	// &
	// Wordle source code 2/7/22

	WordleHelper wH("Wordle List.txt");

	// Guess 1, AROSE
	// Guess 2, UNTIL

	wH.remove("ASE");
	
	wH.right("R");

	wH.removeAt('R', 1);

	wH.rightAt('O', 2);

	// Guess 2, LOORD

	wH.remove("LD");

	wH.rightAt('R', 3);

	// Guess 3, THORN - O

	return 0;
}