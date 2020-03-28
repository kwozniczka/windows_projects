
// SortAppView.h : interface of the CSortAppView class
//

#pragma once


#define RED RGB(255,0,0)
#define GREEN RGB(153, 255, 153)
#define PINK RGB(255, 204, 255)
#define BLUE RGB(179, 240, 255)
#define PEACH RGB(255, 187, 153)
#define PURPLE RGB(230, 153, 255)
#define YELLOW RGB(255, 255, 179)





static COLORREF colors[] = { BLUE, PINK, GREEN, PEACH, PURPLE, YELLOW };


class CSortAppView : public CView
{
protected: // create from serialization only
	CSortAppView();
	DECLARE_DYNCREATE(CSortAppView)

// Attributes
public:
	CSortAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSortAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	CRect* m_pClientRect;
	CFont* m_pFontNums;
	CFont* m_pFontNames;
	

private:
	void drawPlot(CDC* pDC);
	void drawSorts(CDC * pDC, CSortAppDoc * pDoc);
	void drawScale(CDC* pDC, CSortAppDoc * pDoc);
};

#ifndef _DEBUG  // debug version in SortAppView.cpp
inline CSortAppDoc* CSortAppView::GetDocument() const
   { return reinterpret_cast<CSortAppDoc*>(m_pDocument); }
#endif

