// lab1View.cpp : implementation of the CLab1View class
//

#include "stdafx.h"
#include "lab1.h"

#include "lab1Doc.h"
#include "lab1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab1View

IMPLEMENT_DYNCREATE(CLab1View, CView)

BEGIN_MESSAGE_MAP(CLab1View, CView)
	//{{AFX_MSG_MAP(CLab1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab1View construction/destruction

CLab1View::CLab1View()
{
	// TODO: add construction code here

}

CLab1View::~CLab1View()
{
}

BOOL CLab1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLab1View drawing

void CLab1View::OnDraw(CDC* pDC)
{
	CLab1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->TextOut(10,10,"My First MFC! Hello World!");
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLab1View printing

BOOL CLab1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLab1View diagnostics

#ifdef _DEBUG
void CLab1View::AssertValid() const
{
	CView::AssertValid();
}

void CLab1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab1Doc* CLab1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab1Doc)));
	return (CLab1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab1View message handlers
