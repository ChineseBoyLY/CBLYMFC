// lab1Doc.h : interface of the CLab1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB1DOC_H__B8A9C548_6D1E_44EA_A923_6B822D7343A3__INCLUDED_)
#define AFX_LAB1DOC_H__B8A9C548_6D1E_44EA_A923_6B822D7343A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab1Doc : public CDocument
{
protected: // create from serialization only
	CLab1Doc();
	DECLARE_DYNCREATE(CLab1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB1DOC_H__B8A9C548_6D1E_44EA_A923_6B822D7343A3__INCLUDED_)
