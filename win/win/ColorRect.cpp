#include "stdafx.h"
#include "ColorRect.h"


CColorRect::CColorRect(CRect * pRect, int penWidth, COLORREF penColor, COLORREF bkgColor)
{

}

CColorRect::CColorRect(const CRect &)
{
}

CColorRect::CColorRect(const CPoint & LeftTop, const CPoint & RightBottom)
{
}

CColorRect::CColorRect(const CPoint &, const CSize &)
{
}

CColorRect::~CColorRect()
{
}

void CColorRect::PaintRect(CDC * pDC)
{
}

void CColorRect::setAttr(int penWidth, COLORREF penColor, COLORREF bkgColor)
{
}

CPen * CColorRect::getRectPen()
{
	return nullptr;
}

CBrush * CColorRect::getRectBrush()
{
	return nullptr;
}

void CColorRect::initAtrr()
{
}

void CColorRect::createAtrr(int penWidth, COLORREF penColor, COLORREF bkgColor)
{
}

