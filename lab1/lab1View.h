// lab1View.h : interface of the CLab1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB1VIEW_H__B5C39387_BBAB_435C_9480_F985D879866C__INCLUDED_)
#define AFX_LAB1VIEW_H__B5C39387_BBAB_435C_9480_F985D879866C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab1View : public CView
{
protected: // create from serialization only
	CLab1View();
	DECLARE_DYNCREATE(CLab1View)

// Attributes
public:
	CLab1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lab1View.cpp
inline CLab1Doc* CLab1View::GetDocument()
   { return (CLab1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB1VIEW_H__B5C39387_BBAB_435C_9480_F985D879866C__INCLUDED_)
