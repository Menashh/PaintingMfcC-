//!! 14 b
#include "stdafx.h" 
#include "RectangleF.h"


IMPLEMENT_SERIAL(RectangleF, CObject, 1)


RectangleF::RectangleF(CPoint p1, CPoint p2) 
	:Figure(p1,p2)
{
}
void RectangleF::Draw(CDC* dc)const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}

