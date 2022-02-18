# WordleHelper
An application to help narrow down the correct answer in Wordle.

This is a C++ application meant to help identify the most likely answer in Wordle by narrowing down choices by counting the most frequently occuring letters in every possible word both cumulatively and at specific positions (i.e. which letters most frequently occur at the beginning or end of a word) from a list of words provided by an input file.

At the start of the application, each word is given a raw score based on the cumulative occurence of all its letters, like so:

- A: 5990 Points
- E: 6662 Points
- R: 4158 Points
- S: 6665 Points

- "ERASE": 30137 Points

The words with the highest scores are the ones most likely to be the answer based on the current information.

Beginning with a full list of possible words, the application attempts to identify the correct answer based on the following information provided by each guess:

- Which letters are part of the correct answer
- Whether a letter is in the correct position

Currently, the application only weighs answers by the initial cumulative frequency of each letter, but I hope to expand its functionality to provide updated weights with each guess.
