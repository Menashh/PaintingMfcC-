#include "stdafx.h"  
#include "Figure.h"


IMPLEMENT_SERIAL(Figure, CObject, 1)



void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << bg;
		ar << fg;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> bg;
		ar >> fg;
	}
}
//!! 21 e

bool Figure::isInside(const CPoint &P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);

}
void Figure::Shift(int dx, int dy)
{
	P1 = P1 + CPoint(dx, dy);
	P2 = P2 + CPoint(dx, dy);
}
void Figure::Drawcolor(CPaintDC* dc)
{
	CPen pen(newpen, 2, fg); //create a new pen color
	CBrush brush(bg);
	CPen* oldPen = dc->SelectObject(&pen);
	CBrush* oldBrush = dc->SelectObject(&brush);
	Draw(dc);
	dc->SelectObject(oldPen);
	dc->SelectObject(oldBrush);
}

void Figure::SetBG(COLORREF _bg)
{
	this->bg = _bg;
}

void Figure::SetFG(COLORREF _fg)
{
	this->fg = _fg;
}

COLORREF Figure::GetBG()
{
	return bg;
}

COLORREF Figure::GetFG()
{
	return fg;
}

void Figure::SetPen(int pen)
{
	this->newpen = pen;
}
