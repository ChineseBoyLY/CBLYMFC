// lab3View.cpp : implementation of the CLab3View class
//

#include "stdafx.h"
#include "lab3.h"

#include "lab3Doc.h"
#include "lab3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab3View

IMPLEMENT_DYNCREATE(CLab3View, CView)

BEGIN_MESSAGE_MAP(CLab3View, CView)
	//{{AFX_MSG_MAP(CLab3View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)

	ON_MESSAGE(WM_USERMSG,OnMyFunction)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab3View construction/destruction
CPoint movePoint;
CLab3View::CLab3View()
{
	// TODO: add construction code here
	m_sMousePoint="";
	m_nLine=0;

	ptCharacter.x=0;
	ptCharacter.y=0;
}

CLab3View::~CLab3View()
{
}

BOOL CLab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLab3View drawing

void CLab3View::OnDraw(CDC* pDC)
{
	CLab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(movePoint.x,movePoint.y,m_sMousePoint);
	pDC->TextOut(0,m_nLine*20,m_strDisplay);
}

/////////////////////////////////////////////////////////////////////////////
// CLab3View printing

BOOL CLab3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLab3View diagnostics

#ifdef _DEBUG
void CLab3View::AssertValid() const
{
	CView::AssertValid();
}

void CLab3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab3Doc* CLab3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab3Doc)));
	return (CLab3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab3View message handlers

void CLab3View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	movePoint=point;

	m_sMousePoint.Format("鼠标左键在点(%d,%d)按下",point.x,point.y);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CLab3View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	movePoint=point;

	m_sMousePoint="鼠标左键被释放";
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CLab3View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	movePoint=point;

	m_sMousePoint.Format("鼠标位于点(%d,%d)按下",point.x,point.y);
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}

void CLab3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	if(nChar==VK_RETURN)
	{
		//换行
		ptCharacter.x=0;
		ptCharacter.y=ptCharacter.y+20;

	//  m_strDisplay.Empty();
	//	m_nLine++;
	}
	else
	{
		//m_strDisplay+=(TCHAR)nChar;	

		dc.TextOut(ptCharacter.x,ptCharacter.y,(LPCTSTR)&nChar);		//输出显示字符
		CSize textsize;
		textsize=dc.GetTextExtent((LPCTSTR)&nChar);				//获取当前字符大小
		//前进到下一个字符位置
		ptCharacter.x=ptCharacter.x+textsize.cx;
	}
	
//	dc.TextOut(0,m_nLine*20,m_strDisplay);
//	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CLab3View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetTimer(1,500,NULL);  //安装定时器
}

void CLab3View::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	KillTimer(1);   //清除定时器
}

void CLab3View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBeep(-1);
	CView::OnTimer(nIDEvent);
}

LRESULT CLab3View::OnMyFunction(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox("恭喜你，消息发送成功！");
	return NULL;
}

void CLab3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	HWND hWnd=GetSafeHwnd();
	if(nChar==VK_UP)
	{
		::PostMessage(hWnd,WM_USERMSG,0,0);
		return;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
