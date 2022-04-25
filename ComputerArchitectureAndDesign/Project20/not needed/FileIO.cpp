// FileIO.cpp
// Example with File I/O

#include <stdio.h>
#include <stdlib.h>

// Assume: argv[1] = Name of the output textfile (array of chars)
    // argv[2] = number of circles to create (int)
    // argv[3] = Starting value for the radius (double)

int main(int argc, char *argv[]){

    printf("Number of arguments: %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("%d %s\n", i, argv[i]);
    }
    int numberCircles = atoi(argv[2]); // atoi = convert to int
    printf("Number of circles: %s %d\n", argv[2], numberCircles);

    double startingRadius = atof(argv[3]); // atof = convert to float
    printf("Starting raduis: %s %d\n", argv[2], startingRadius);

    FILE *outputFile = fopen(argv[1], "w");

    for (int i = 1; i <= 19; i+=2){
        printf("%d %d\n", i, i+1);
        fprintf(outputFile, "%d %d\n", i, i+1);
    }

    for (int i = 101; i <= 119; i+=2){
        printf("%d %d\n", i, i+1);
        fprintf(outputFile, "%d %d\n", i, i+1);
    }

    for (int i = 201; i <= 219; i+=2){
        printf("%d %d\n", i, i+1);
        fprintf(outputFile, "%d %d\n", i, i+1);
    }

    for (int i = 301; i <= 319; i+=2){
        printf("%d %d\n", i, i+1);
        fprintf(outputFile, "%d %d\n", i, i+1);
    }

    for(int i = 0; i < numberCircles; i++){
        fprintf(outputFile, "%d %d %lf\n", i, i, startingRadius + i);
    }

    fclose(outputFile);

    return 0;
}