#pragma once
#include "Figure.h"
class MyOval: public Figure
{
public:
	MyOval(int x1, int y1, int x2, int y2, Graphics* g);
	void draw();
};

