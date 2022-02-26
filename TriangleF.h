#pragma once
#include "Figure.h"
class TriangleF:public Figure
{
	DECLARE_SERIAL(TriangleF)
public:
	TriangleF(){}
	TriangleF(CPoint p1,CPoint p2);
	void Draw(CDC* dc)const;
};

