/////////////////////////////////
// Play Hangman Drive
// HW 19 Shell
///////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "Hangman.h"

int main(int argc, char *argv[]){
        // File stuff
        int numWords = atoi(argv[1]);
        int plays, num;
        printf("How many times would you like to play?\t" );
        scanf("%d", &plays);

        for(int i = 0; i < plays; i++){
                printf("\n~~~~~~~~~~~~~ Round %d ~~~~~~~~~~~~~~~~~~\n", i+1);
                // Initializing the hangman
                        //Hangman *h = initializeHangman(5, clue);
                printf("Enter a number between 1 and %d:\t", numWords);
                scanf("%d", &num);
                Hangman *h = initializeHangmanObject(num, argv[2]);

                while (!gameOver(h)){
                        printString(h);
                        char guess = 'A';
                        printf("Enter your guess: \t");
                        scanf(" %c", &guess);
                        guess = convertToUppercase(guess);
                        findLetter(h, guess);
                        printf("\n");
                }
                printString(h);
                if (gameWon(h)){
                        printf("\nYou won with score: %d!! :) :)\n", h->score);
                }
                else
                        printf("\nYou lost :( \n");
                freeHangman(h);
                h = NULL;
        }
        return 0;
}

/* Notes on main()
        * argc = number of arguments
        * argv[1] = number of words in file (call this numWords)
 * Notes on other jazz
        * atoi = converts a char to an integer
*/