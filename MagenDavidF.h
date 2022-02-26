#pragma once
#include"TriangleF.h"
class MagenDavidF :public TriangleF
{
	DECLARE_SERIAL(MagenDavidF)
public:
	MagenDavidF() {}
	MagenDavidF(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};

