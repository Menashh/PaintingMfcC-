#include "stdafx.h"
#include "TriangleF.h"
IMPLEMENT_SERIAL(TriangleF, CObject, 1)
TriangleF::TriangleF(CPoint p1, CPoint p2):Figure(p1,p2)
{
}

void TriangleF::Draw(CDC* dc) const
{

	dc->MoveTo((P1.x + P2.x) / 2, P1.y); //take the first point 
	dc->LineTo(P1.x, P2.y);						//create lines
	dc->LineTo(P2.x, P2.y);							//create lines
	dc->LineTo((P1.x + P2.x) / 2, P1.y);	//create lines

	CPoint a((P1.x + P2.x) / 2, P1.y);
	CPoint b(P1.x, P2.y);
	CPoint c(P2.x, P2.y);

	CPoint arr[3] = { a,b,c };

	dc->Polygon(arr, 3);
}
