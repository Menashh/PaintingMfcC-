#pragma once
#include "RectangleF.h"
class TrapezeF:public RectangleF
{
	DECLARE_SERIAL(TrapezeF)
public:
	TrapezeF() {}
	TrapezeF(CPoint p1, CPoint p2);
	void Draw(CDC* dc)const;
};

