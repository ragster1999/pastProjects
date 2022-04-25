// Driver.cpp
// Alex Gonzalez
// PO: 983
// Due: 5.16.19
// Time taken to complete: too much

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Circle.h"

// argv[1] = Size of each array
// argv[2] = Name of input file

int main(int argc, char *argv[]){

    int sizeOfArray = atoi(argv[1]);
    FILE *inputFile = fopen(argv[2], "r");
    int x, y;
    double z;

    // Static array of Static Point objects
    Point staticArrayOfStaticObjects[10];
    for(int i = 0; i < 10; i++){
        fscanf(inputFile, "%d", &x);
        fscanf(inputFile, "%d", &y);
        staticArrayOfStaticObjects[i].x = x;
        staticArrayOfStaticObjects[i].y = y;
    }
    printf("\n\nStatic array of Static Objects: \n");
    for(int i = 0; i < 10; i++){
        printf("%d: %d %d\n", i, staticArrayOfStaticObjects[i].x, staticArrayOfStaticObjects[i].y);
    }
    
    // Static array of Point pointers
    Point *staticArrayOfPointers[10];
    for(int i = 0; i < 10; i++){
        staticArrayOfPointers[i] = (Point*)malloc(sizeof(Point));
        fscanf(inputFile, "%d", &x);
        fscanf(inputFile, "%d", &y);
        staticArrayOfPointers[i]->x = x;
        staticArrayOfPointers[i]->y = y;
    }
    printf("\n\nStatic array of Dynamic Objects: \n");
    for(int i = 0; i < 10; i++){
        printf("%d: %d %d\n", i, staticArrayOfPointers[i]->x, staticArrayOfPointers[i]->y);
    }

    // Pointer to array of point objects
    Point *pArray = (Point*)malloc(sizeof(Point)*10);
    for(int i = 0; i < 10; i++){
        fscanf(inputFile, "%d", &x);
        fscanf(inputFile, "%d", &y);
        pArray[i].x = x;
        pArray[i].y = y;
    }
    printf("\n\nDynamic array of Static Objects: \n");
    for(int i = 0; i < 10; i++){
        printf("%d: %d %d\n", i, pArray[i].x, pArray[i].y);
    }
    free(pArray);
    
    // Pointer to an array of point pointers
    Point **p2Array = (Point**)malloc(sizeof(Point)*10);
    for(int i = 0; i < 10; i++){
        p2Array[i] = (Point*)malloc(sizeof(Point));
        fscanf(inputFile, "%d", &x);
        fscanf(inputFile, "%d", &y);
        p2Array[i]->x = x;
        p2Array[i]->y = y;
        //free(p2Array[i]);
    }
    printf("\n\nDynamic array of Dynamic Pointers: \n");
    for(int i = 0; i < 10; i++){
        printf("%d: %d %d\n", i, p2Array[i]->x, p2Array[i]->y);
    }
    free(p2Array);

    ///////////// Circle part ///////////////////////////////

    /*
            First and 3'd circle methods work real nice
    */
    
    // Static circle with Static Center
    CircleWithStruct c1;
    fscanf(inputFile, "%d", &x);
    fscanf(inputFile, "%d", &y);
    fscanf(inputFile, "%lf", &z);
    c1.centerS.x = x;
    c1.centerS.y = y;
    c1.radius = z;
    printf("\nStatic circle with Static Center:");
    printCircleWithStruct(c1);

    //Static circle with Dynamic Center
    CircleWithPointer c2;
    c2.centerP = (Point*)malloc(sizeof(Point));
    fscanf(inputFile, "%d", &x);
    fscanf(inputFile, "%d", &y);
    fscanf(inputFile, "%lf", &z);
    c2.centerP->x = x;
    c2.centerP->y = y;
    c2.radius = z;
    printf("\nStatic circle with Dynamic Center:");
    printCircleWithPointer(c2);
    free(c2.centerP); 
    
    // Dynamic circle with Static Center
    CircleWithStruct *c3 = (CircleWithStruct*)malloc(sizeof(CircleWithStruct));
    fscanf(inputFile, "%d", &x);
    fscanf(inputFile, "%d", &y);
    fscanf(inputFile, "%lf", &z);
    c3->centerS.x = x;
    c3->centerS.y = y;
    c3->radius = z;
    printf("\nDynamic circle with Static Center:");
    printCircleWithStruct(*c3);
    free(c3);
    
    // Dynamic circle with Dynamic Center
    CircleWithPointer *c4 = (CircleWithPointer*)malloc(sizeof(CircleWithPointer));
    c4->centerP = (Point*)malloc(sizeof(Point));
    fscanf(inputFile, "%d", &x);
    fscanf(inputFile, "%d", &y);
    fscanf(inputFile, "%lf", &z);
    c4->centerP->x = x;
    c4->centerP->y = y;
    c4->radius = z;
    printf("\nDymanic circle with Dynamic Center:");
    printCircleWithPointer(*c4);
    free(c4);

    ///////////////////
    printf("\n\n");
    fclose(inputFile);
    return 0;
}

// Optional
        // Static Circle with Point objects
        // Static Circle with Point pointers
        // Dynamic Circle with Point objects
        // Dynamic Circle with Point pointers