// Circle.cpp
// Circle implementation file

#include "Circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// print the info of a cricle with an internal struct
void printCircleWithStruct(CircleWithStruct c){
	printf("\nRadius: %lf, [x, y] = [%d, %d]\n",c.radius,c.centerS.x,c.centerS.y);
}

// print the info of a cricle with an internal pointer to a struct
void printCircleWithPointer(CircleWithPointer c){
	printf("\nRadius: %lf, [x, y] = [%d, %d]\n",c.radius, (c.centerP)->x,(c.centerP)->y);
}

// find the distance between the origin and the circle's center if the center is a struct
double findDistanceToOriginS(CircleWithStruct c){
	return sqrt(pow(c.centerS.x,2)+ pow(c.centerS.y,2));
}

// find the distance between the origin and the circle's center ifthe center is a pointer to a struct
double findDistanceToOriginP(CircleWithPointer c){
	return sqrt(pow(c.centerP->x,2)+ pow(c.centerP->y,2));
}

