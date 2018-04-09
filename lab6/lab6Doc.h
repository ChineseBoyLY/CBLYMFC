// lab6Doc.h : interface of the CLab6Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB6DOC_H__4BCADCC4_AF5D_42B9_A929_11F6AABE3988__INCLUDED_)
#define AFX_LAB6DOC_H__4BCADCC4_AF5D_42B9_A929_11F6AABE3988__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab6Doc : public CDocument
{
protected: // create from serialization only
	CLab6Doc();
	DECLARE_DYNCREATE(CLab6Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab6Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab6Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB6DOC_H__4BCADCC4_AF5D_42B9_A929_11F6AABE3988__INCLUDED_)
