#include <math.h>

#include "circle.h"

void draw_circle_canon(QPainter *painter, Point pc, double r)
{
	double r2 = r * r;
	double x_end = r / sqrt(2);
	int xx, yy;
	
	for (double x = 0, y = r; x <= x_end; x += 1)
	{
		y = sqrt(r2 - x * x);
		xx = round(x);
		yy = round(y);
		
		painter->drawPoint(pc.x() + xx, pc.y() + yy);
		painter->drawPoint(pc.x() - xx, pc.y() + yy);
		painter->drawPoint(pc.x() + xx, pc.y() - yy);
		painter->drawPoint(pc.x() - xx, pc.y() - yy);
		
		painter->drawPoint(pc.x() + yy, pc.y() + xx);
		painter->drawPoint(pc.x() - yy, pc.y() + xx);
		painter->drawPoint(pc.x() + yy, pc.y() - xx);
		painter->drawPoint(pc.x() - yy, pc.y() - xx);
	}
}

void draw_circle_param(QPainter *painter, Point pc, double r)
{
	double dt = 1 / r;
	double t_end = 2 * M_PI;
	int x, y;
	
	for (double t = 0; t < 2 * t_end; t += dt)
	{
		x = pc.x() + (int)round(r * cos(t));
		y = pc.y() + (int)round(r * sin(t));
		painter->drawPoint(x, y);
	}
}

void draw_circle_lib(QPainter *painter, Point pc, double r)
{
	painter->drawEllipse(QPointF(pc.x(), pc.y()), r, r);
}
