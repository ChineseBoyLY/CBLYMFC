// lab2Doc.h : interface of the CLab2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB2DOC_H__065017D6_D75E_48C3_A6CB_2F69D209B853__INCLUDED_)
#define AFX_LAB2DOC_H__065017D6_D75E_48C3_A6CB_2F69D209B853__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab2Doc : public CDocument
{
protected: // create from serialization only
	CLab2Doc();
	DECLARE_DYNCREATE(CLab2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB2DOC_H__065017D6_D75E_48C3_A6CB_2F69D209B853__INCLUDED_)
