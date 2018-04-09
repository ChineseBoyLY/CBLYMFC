// lab3Doc.cpp : implementation of the CLab3Doc class
//

#include "stdafx.h"
#include "lab3.h"

#include "lab3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab3Doc

IMPLEMENT_DYNCREATE(CLab3Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab3Doc, CDocument)
	//{{AFX_MSG_MAP(CLab3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab3Doc construction/destruction

CLab3Doc::CLab3Doc()
{
	// TODO: add one-time construction code here

}

CLab3Doc::~CLab3Doc()
{
}

BOOL CLab3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLab3Doc serialization

void CLab3Doc::Serialize(CArchive& ar)
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
// CLab3Doc diagnostics

#ifdef _DEBUG
void CLab3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab3Doc commands
