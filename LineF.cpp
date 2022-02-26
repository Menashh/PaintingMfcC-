#include "stdafx.h"
#include "LineF.h"
#include"Figure.h"
IMPLEMENT_SERIAL(LineF, CObject, 1)
LineF::LineF(CPoint p1, CPoint p2) :Figure(p1, p2)
{

}

