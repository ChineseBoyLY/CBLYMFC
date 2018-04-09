// lab8Doc.h : interface of the CLab8Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB8DOC_H__BF6D92A7_24A9_4B6E_8F5D_4FBC5552729D__INCLUDED_)
#define AFX_LAB8DOC_H__BF6D92A7_24A9_4B6E_8F5D_4FBC5552729D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "lab8Set.h"


class CLab8Doc : public CDocument
{
protected: // create from serialization only
	CLab8Doc();
	DECLARE_DYNCREATE(CLab8Doc)

// Attributes
public:
	CLab8Set m_lab8Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab8Doc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab8Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB8DOC_H__BF6D92A7_24A9_4B6E_8F5D_4FBC5552729D__INCLUDED_)
