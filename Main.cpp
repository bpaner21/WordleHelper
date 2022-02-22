
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

	wH.remove("AROSE");

	return 0;
}