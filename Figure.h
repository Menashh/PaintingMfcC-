#pragma once
#include "stdafx.h"
class Figure: public CObject {
	DECLARE_SERIAL(Figure)    
	CPoint P1;
	CPoint P2;
	COLORREF bg, fg;
	int newpen;
public:
	Figure() {};
	Figure(CPoint p1, CPoint p2):fg(RGB(0, 0, 0)), bg(RGB(255, 255, 255)),
		P1(p1), P2(p2){}
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const //line
	{
		dc->MoveTo(P1.x, P1.y);
		dc->LineTo(P2.x, P2.y);
	}
	CPoint getP1() const 
	{ 
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual void Shift(int dx, int dy);
	void Drawcolor(CPaintDC* dc);
	void SetBG(COLORREF _bg);
	void SetFG(COLORREF _fg);
	COLORREF GetBG();
	COLORREF GetFG();
	void SetPen(int pen);
};
