// FileInputCircles.cpp
// File I/O + arrays of objects

#include<stdio.h>
#include <stdlib.h>

#include "Circle.h"

// argv[1] = Size of each array
// argv[2] = Name of input file

int main(int argc, char *argv[]){

    int sizeOfArray = atoi(argv[1]);
    FILE *inputFile = fopen(argv[2], "r");

    Point staticArrayOfPoints[10];

    for(int i = 0; i < 10; i++){
        int x, y;
        fscanf(inputFile, "%d", &x);
        fscanf(inputFile, "%d", &y);
        staticArrayOfPoints[i].x = x;
        staticArrayOfPoints[i].y = y;
    }

    printf("Static array of static objects: \n");
    for(int i = 0; i < 10; i++){
        printf("%d: %d %d\n", i, staticArrayOfPoints[i].x, staticArrayOfPoints[i].y);
    }

    fclose(inputFile);
    return 0;
}

// Input: ./a.out 10 FileWithNumbers.txt