// lab3View.h : interface of the CLab3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB3VIEW_H__A293FA7E_73ED_4356_82B7_4BC8E3D04D42__INCLUDED_)
#define AFX_LAB3VIEW_H__A293FA7E_73ED_4356_82B7_4BC8E3D04D42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int WM_USERMSG=WM_USER+100;
class CLab3View : public CView
{
protected: // create from serialization only
	CLab3View();
	DECLARE_DYNCREATE(CLab3View)
	CString m_sMousePoint;
	int m_nLine;           //存储按回车键的次数
	CString m_strDisplay;  //存储当前行输入的字符
// Attributes
public:
	CLab3Doc* GetDocument();

public:
	afx_msg LRESULT OnMyFunction(WPARAM wParam, LPARAM lParam);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab3View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint ptCharacter;
	virtual ~CLab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab3View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lab3View.cpp
inline CLab3Doc* CLab3View::GetDocument()
   { return (CLab3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB3VIEW_H__A293FA7E_73ED_4356_82B7_4BC8E3D04D42__INCLUDED_)
