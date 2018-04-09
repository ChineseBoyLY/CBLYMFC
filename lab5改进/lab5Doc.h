// lab5Doc.h : interface of the CLab5Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB5DOC_H__50DD7244_8F83_46B0_B30B_89DC202A7FF7__INCLUDED_)
#define AFX_LAB5DOC_H__50DD7244_8F83_46B0_B30B_89DC202A7FF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab5Doc : public CDocument
{
protected: // create from serialization only
	CLab5Doc();
	DECLARE_DYNCREATE(CLab5Doc)

// Attributes
public:
	struct	
	{
		char name[10];
		char sex[3];
		int age;
		char tel[14];
		char school[30];
	}m_student[40];


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab5Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab5Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB5DOC_H__50DD7244_8F83_46B0_B30B_89DC202A7FF7__INCLUDED_)
