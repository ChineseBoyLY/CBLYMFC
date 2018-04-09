// lab1Doc.cpp : implementation of the CLab1Doc class
//

#include "stdafx.h"
#include "lab1.h"

#include "lab1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab1Doc

IMPLEMENT_DYNCREATE(CLab1Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab1Doc, CDocument)
	//{{AFX_MSG_MAP(CLab1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab1Doc construction/destruction

CLab1Doc::CLab1Doc()
{
	// TODO: add one-time construction code here

}

CLab1Doc::~CLab1Doc()
{
}

BOOL CLab1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLab1Doc serialization

void CLab1Doc::Serialize(CArchive& ar)
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
// CLab1Doc diagnostics

#ifdef _DEBUG
void CLab1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab1Doc commands
