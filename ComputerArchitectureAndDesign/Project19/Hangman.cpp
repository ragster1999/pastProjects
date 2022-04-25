// Hangman.cpp
// Alex Gonzalez
// PO: 983
// Due: 5.17.19

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Hangman.h"

Hangman *initializeHangmanObject(int num, char *name){ // Passes in the number word thay want and the file name
    char *clue;
    Hangman *h = (Hangman *)malloc(sizeof(Hangman));
    FILE *InputFile = fopen(name, "r");

    // Loop through file
    for(int i = 0; i < num; i++){
        
        fscanf(InputFile, "%d", &h->arraySize);
        clue = (char*)malloc(sizeof(char) * h->arraySize);
        fscanf(InputFile, "%s", clue);  
    }
    h->word = (char*)malloc(sizeof(char) * h->arraySize);
    h->runningWord = (char*)malloc(sizeof(char) * h->arraySize);
    
    // Populate word and runningWord objects
    for(int j = 0; j < h->arraySize; j++){
        h->word[j] = clue[j];
        h->runningWord[j] = '_';    
    }

    h->score = 10;
    h->setScore = h->score;
    h->win = false;
    h->guessedLetters = (char*)malloc(sizeof(char) * h->setScore);
    
    fclose(InputFile);
    return h;
}

Hangman *initializeHangman(int newSize, char *clue){
    Hangman *h = (Hangman *)malloc(sizeof(Hangman));
    h->arraySize = newSize;
    h->score = 10;
    h->word = (char*)malloc(sizeof(char) * h->arraySize);
    h->runningWord = (char*)malloc(sizeof(char) * h->arraySize);
    h->win = false;

    for(int i = 0; i < h->arraySize; i++){
        h->word[i] = clue[i];
        h->runningWord[i] = '_';
    }
    return h;
}

char convertToUppercase(char c){
    int x = (int)c;
    if(x >= 97 && x <= 122){
            c = (char)x- 32;
        }
    return c;
}

void printString(Hangman *h){
    printf("Word: ");
    for(int i = 0; i < h->arraySize; i++){
        printf(" %c", h->runningWord[i]);
    }
    printf("\nScore: %d", h->score);
    printf("\n");
    return;
}

void findLetter(Hangman *h, char letter){
    bool loose = true;
    for(int i = 0; i < h->arraySize; i++){
        if(h->word[i] == letter){
            h->runningWord[i] = letter;
            loose = false;
        }
        
    }
    if(loose){
        for(int i = 0; i < h->setScore; i++){
            if(letter == h->guessedLetters[i]){
                loose = false;
                printf("\n\tYou already guessed '%c'", letter);
            }
        }
    }
    if(loose){
        h->guessedLetters[h->setScore - h->score] = letter;
        h->score--;
    }
    return;
}

bool gameOver(Hangman *h){
    bool win = true;
    for(int i = 0; i < h->arraySize; i++){
        if(h->word[i] != h->runningWord[i]){
            win = false;
        }
    }
    if(h->score == 0 || win){
        h->win = true;
        return true;
    }else{
        return false;
    }
}

bool gameWon(Hangman *h){
    if(h->score > 0 && h->win){
        return true;
    }else{
        return false;
    }
}

void freeHangman(Hangman *h){
    free(h);
    return;
}