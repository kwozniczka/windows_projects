#pragma once
#include "atltypes.h"
#include "afxdialogex.h"
#include "stdafx.h"

#define BLACK RGB(0,0,0)

class CColorRect : public CRect {

	//konstruktory, destruktor
public:
	CColorRect(CRect* pRect = NULL, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK);
	CColorRect(const CRect& /*...""....*/);
	CColorRect(const CPoint& LeftTop, const CPoint& RightBottom /*...""...*/); //x,y
	CColorRect(const CPoint&, const CSize& /*...""...*/);

	~CColorRect();

public:
	void PaintRect(CDC* pDC);
	void setAttr(int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK);
	CPen* getRectPen();
	CBrush* getRectBrush();


private:
	void initAtrr();
	void createAtrr(int penWidth, COLORREF penColor, COLORREF bkgColor);

private:
	CPen* m_pPen;
	CBrush* m_pBrush;



};


