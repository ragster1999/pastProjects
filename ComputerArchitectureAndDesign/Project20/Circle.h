// Circle.h
// Cricle header file

#include "Point.h"

struct CircleWithStruct
{
	double radius;
	Point centerS;
};

struct CircleWithPointer
{
	double radius;
	Point *centerP;
};

void printCircleWithStruct(CircleWithStruct c);		// Done
void printCircleWithPointer(CircleWithPointer c);	// Done

double findDistanceToOriginS(CircleWithStruct c);	// Done
double findDistanceToOriginP(CircleWithPointer c);	// Done
