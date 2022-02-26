#pragma once
#include"Figure.h"
class StarF:public Figure
{
	DECLARE_SERIAL(StarF)
public:
	StarF() {}
	StarF(CPoint p1, CPoint p2);
	void Draw(CDC* dc)const;
};

