// lab8Doc.cpp : implementation of the CLab8Doc class
//

#include "stdafx.h"
#include "lab8.h"

#include "lab8Set.h"
#include "lab8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab8Doc

IMPLEMENT_DYNCREATE(CLab8Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab8Doc, CDocument)
	//{{AFX_MSG_MAP(CLab8Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab8Doc construction/destruction

CLab8Doc::CLab8Doc()
{
	// TODO: add one-time construction code here

}

CLab8Doc::~CLab8Doc()
{
}

BOOL CLab8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLab8Doc diagnostics

#ifdef _DEBUG
void CLab8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab8Doc commands
