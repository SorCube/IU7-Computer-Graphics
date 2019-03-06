#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"
#include "lineseg.h"

class Triangle
{
public:
	Triangle();
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    Triangle(Point p1, Point p2, Point p3);
	
	Point *point(int i);
	
private:
	Point points[3];
};

bool isTriangle(Point *p1, Point *p2, Point *p3);

bool isTriangle(Triangle *tr);

void tr_ptrdel(void *data);

#endif // TRIANGLE_H
