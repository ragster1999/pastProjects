//Hangman.h

#include "Letter.h"

struct Hangman{
    int arraySize;  // Dynamic array containing pointers to letter structs
    char *word;     // pointer to array of chars
    char *runningWord; // pointer to array of chars ungoessed
    int score;      // Keeps track of score (decreasing from 10)
    int setScore;
    bool win;
    char *guessedLetters; // Keeps track of letters guessed
};

Hangman *initializeHangman(int newSize, char *clue);    // Done
Hangman *initializeHangmanObject(int num, char *name);    // Done
char convertToUppercase(char c);    // Done
void printString(Hangman *h);   // Done
void findLetter(Hangman *h, char letter);   // Done
bool gameOver(Hangman *h);  // Done
bool gameWon (Hangman *h);   // Done
void freeHangman(Hangman *h);   // Done
