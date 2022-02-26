#include "stdafx.h"
#include "StarF.h"
IMPLEMENT_SERIAL(StarF, CObject, 1);
StarF::StarF(CPoint p1, CPoint p2):Figure(p1,p2)
{
}

void StarF::Draw(CDC* dc) const
{
	dc->MoveTo((P1.x + P2.x) / 2, P1.y);//a
	dc->LineTo(((P2.x - P1.x) * 6.4 / 10) + P1.x, ((P1.y - P2.y) * 6.4 / 10) + P2.y);//b
	dc->LineTo(P2.x, ((P1.y - P2.y) * 6 / 10) + P2.y);//c
	dc->LineTo(((P2.x - P1.x) * 6.8 / 10) + P1.x, ((P1.y - P2.y) * 4 / 10) + P2.y);//d
	dc->LineTo((P2.x - P1.x) * 8 / 10 + P1.x, P2.y);//e
	dc->LineTo((P1.x + P2.x) / 2, ((P1.y - P2.y) * 2.5 / 10) + P2.y);//f
	dc->LineTo(((P2.x - P1.x) * 2 / 10) + P1.x, P2.y);//g
	dc->LineTo(((P2.x - P1.x) * 3.2 / 10) + P1.x, ((P1.y - P2.y) * 4 / 10) + P2.y);//h
	dc->LineTo(P1.x, ((P1.y - P2.y) * 6 / 10) + P2.y);//i
	dc->LineTo(((P2.x - P1.x) * 3.8 / 10) + P1.x, ((P1.y - P2.y) * 6.4 / 10) + P2.y);//j
	dc->LineTo((P1.x + P2.x) / 2, P1.y);//a

	CPoint a((P1.x + P2.x) / 2, P1.y);
	CPoint b(((P2.x - P1.x) * 6.4 / 10) + P1.x, ((P1.y - P2.y) * 6.4 / 10) + P2.y);
	CPoint c(P2.x, ((P1.y - P2.y) * 6 / 10) + P2.y);
	CPoint d(((P2.x - P1.x) * 6.8 / 10) + P1.x, ((P1.y - P2.y) * 4 / 10) + P2.y);;
	CPoint e((P2.x - P1.x) * 8 / 10 + P1.x, P2.y);
	CPoint f((P1.x + P2.x) / 2, ((P1.y - P2.y) * 2.5 / 10) + P2.y);
	CPoint g(((P2.x - P1.x) * 2 / 10) + P1.x, P2.y);
	CPoint h(((P2.x - P1.x) * 3.2 / 10) + P1.x, ((P1.y - P2.y) * 4 / 10) + P2.y);
	CPoint i(P1.x, ((P1.y - P2.y) * 6 / 10) + P2.y);
	CPoint j(((P2.x - P1.x) * 3.8 / 10) + P1.x, ((P1.y - P2.y) * 6.4 / 10) + P2.y);


	CPoint arr[10] = { a,b,c,d,e,f,g,h,i,j };

	dc->Polygon(arr, 10);
}
