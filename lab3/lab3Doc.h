// lab3Doc.h : interface of the CLab3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB3DOC_H__D2EFF81A_4C71_477D_9451_AF48848724CF__INCLUDED_)
#define AFX_LAB3DOC_H__D2EFF81A_4C71_477D_9451_AF48848724CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab3Doc : public CDocument
{
protected: // create from serialization only
	CLab3Doc();
	DECLARE_DYNCREATE(CLab3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB3DOC_H__D2EFF81A_4C71_477D_9451_AF48848724CF__INCLUDED_)
