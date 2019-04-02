#include <math.h>

#include "draw.h"

#define MAX_INTENS 255

template <typename T>
int sgn(T x)
{
	if (x < 0)
		return -1; 
	if (x > 0)
		return 1; 
    return 0;
}

void draw_line_dda(QImage *img, Point p1, Point p2, QColor color)
{
	if (p1 == p2)
	{
		img->setPixel(p1.x(), p1.y(), color.rgb());
		return;
	}
	double xlen = p2.x() - p1.x(), ylen = p2.y() - p1.y();
	double len;
	if (fabs(xlen) > fabs(ylen))
		len =fabs(xlen);
	else
		len = fabs(ylen);
	double dx = xlen / len, dy = ylen / len;
	
	double x = p1.x(), y = p1.y();
	for (int i = 1; i <= dx + len; i++)
	{
		img->setPixel(round(x), round(y), color.rgb());
		x += dx;
		y += dy;
	}
}

void draw_line_bres_real(QImage *img, Point p1, Point p2, QColor color)
{
	if (p1 == p2)
	{
		img->setPixel(p1.x(), p1.y(), color.rgb());
		return;
	}
	
	int x = p1.x(), y = p1.y();
	double dx = p2.x() - p1.x(), dy = p2.y() - p1.y();
	int sx = sgn(dx), sy = sgn(dy);
	dx = fabs(dx);
	dy = fabs(dy);
	
	bool xchg = false;
	if (dy >= dx)
	{
		double t = dx;
		dx = dy;
		dy = t;
		xchg = true;
	}
	
	double m = dy / dx;
	double e = m - 0.5;
	
	for (int i = 0; i < dx; i++)
	{
		img->setPixel(x, y, color.rgb());
		if (e >= 0)
		{
			if (xchg)
				x += sx;
			else
				y += sy;
			e -= 1;
		}
		if (xchg)
			y += sy;
		else
			x += sx;
		e += m;
	}
}

void draw_line_bres_int(QImage *img, Point p1, Point p2, QColor color)
{
	if (p1 == p2)
	{
		img->setPixel(p1.x(), p1.y(), color.rgb());
		return;
	}
	int x = p1.x(), y = p1.y();
	int dx = p2.x() - p1.x(), dy = p2.y() - p1.y();
	int sx = sgn(dx), sy = sgn(dy);
	dx = abs(dx);
	dy = abs(dy);
	
	bool xchg = false;
	if (dy > dx)
	{
		int t = dx;
		dx = dy;
		dy = t;
		xchg = true;
	}
	
	int ddx = 2 * dx;
	int ddy = 2 * dy;
	int e = ddy - dx;
	
	for (int i = 0; i < dx; i++)
	{
		img->setPixel(x, y, color.rgb());
		if (e >= 0)
		{
			if (xchg)
				x += sx;
			else
				y += sy;
			e -= ddx;
		}
		if (xchg)
			y += sy;
		else
			x += sx;
		e += ddy;
	}
}

void draw_line_bres_aa(QImage *img, Point p1, Point p2, QColor color)
{
	if (p1 == p2)
	{
		img->setPixel(p1.x(), p1.y(), color.rgb());
		return;
	}
	int x = p1.x(), y = p1.y();
	double dx = p2.x() - p1.x(), dy = p2.y() - p1.y();
	int sx = sgn(dx), sy = sgn(dy);
	dx = abs(dx);
	dy = abs(dy);
	
	bool xchg = false;
	if (dy > dx)
	{
		double t = dx;
		dx = dy;
		dy = t;
		xchg = true;
	}
	
	double tang = dx == 0 ? 0 : dy / dx;
	double e = (double)MAX_INTENS / 2;
	double m = tang * MAX_INTENS;
	double w = MAX_INTENS - m;
	
	for (int i = 0; i < dx; i++)
	{
		color.setAlpha((MAX_INTENS - e) / 255);
		img->setPixel(x, y, color.rgba());
		if (e >= w)
		{
			x += sx;
			y += sy;
			e -= w;
		}
		else
		{
			if (xchg)
				y += sy;
			else
				x += sx;
			e += m;
		}
	}
}