// lab6Doc.cpp : implementation of the CLab6Doc class
//

#include "stdafx.h"
#include "lab6.h"

#include "lab6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab6Doc

IMPLEMENT_DYNCREATE(CLab6Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab6Doc, CDocument)
	//{{AFX_MSG_MAP(CLab6Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab6Doc construction/destruction

CLab6Doc::CLab6Doc()
{
	// TODO: add one-time construction code here

}

CLab6Doc::~CLab6Doc()
{
}

BOOL CLab6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLab6Doc serialization

void CLab6Doc::Serialize(CArchive& ar)
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
// CLab6Doc diagnostics

#ifdef _DEBUG
void CLab6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab6Doc commands
