#pragma once
#include "Figure.h"
class Graphics;
class MyRect: public Figure
{
public:
	MyRect(int x1, int y1, int x2, int y2, Graphics *g);
	void draw();
};

