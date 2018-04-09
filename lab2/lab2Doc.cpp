// lab2Doc.cpp : implementation of the CLab2Doc class
//

#include "stdafx.h"
#include "lab2.h"

#include "lab2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab2Doc

IMPLEMENT_DYNCREATE(CLab2Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab2Doc, CDocument)
	//{{AFX_MSG_MAP(CLab2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab2Doc construction/destruction

CLab2Doc::CLab2Doc()
{
	// TODO: add one-time construction code here

}

CLab2Doc::~CLab2Doc()
{
}

BOOL CLab2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLab2Doc serialization

void CLab2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLab2Doc diagnostics

#ifdef _DEBUG
void CLab2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab2Doc commands
