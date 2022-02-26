#include "stdafx.h"
#include "TrapezeF.h"
#include"Rectanglef.h"
IMPLEMENT_SERIAL(TrapezeF, CObject, 1);
TrapezeF::TrapezeF(CPoint p1, CPoint p2): RectangleF(p1, p2)
{

}

void TrapezeF::Draw(CDC* dc) const//p1=begin,p2=end
{
	dc->MoveTo(((P2.x - P1.x) / 3) + P1.x, P1.y); //a
	dc->LineTo(P1.x, P2.y);  //b
	dc->LineTo(P2.x, P2.y);  //c
	dc->LineTo((((P2.x - P1.x)) * 2 / 3) + P1.x, P1.y); // d
	dc->LineTo(((P2.x - P1.x) / 3) + P1.x, P1.y); //a

	CPoint a(((P2.x - P1.x) / 3) + P1.x, P1.y);
	CPoint b(P1.x, P2.y);
	CPoint c(P2.x, P2.y);
	CPoint d((((P2.x - P1.x)) * 2 / 3) + P1.x, P1.y);

	CPoint arr[4] = { a,b,c,d };

	dc->Polygon(arr, 4);
}
