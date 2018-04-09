// lab2View.cpp : implementation of the CLab2View class
//

#include "stdafx.h"
#include "lab2.h"

#include "lab2Doc.h"
#include "lab2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab2View

IMPLEMENT_DYNCREATE(CLab2View, CFormView)

BEGIN_MESSAGE_MAP(CLab2View, CFormView)
	//{{AFX_MSG_MAP(CLab2View)
	ON_COMMAND(ID_TIME_START, OnTimeStart)
	ON_COMMAND(ID_TIME_STOP, OnTimeStop)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_TIME_START, OnUpdateTimeStart)
	ON_COMMAND(ID_TIME_CURRENT, OnTimeCurrent)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab2View construction/destruction

CLab2View::CLab2View()
	: CFormView(CLab2View::IDD)
{
	//{{AFX_DATA_INIT(CLab2View)
	m_strTime = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_timer=0;
	m_btimer=true;
	h=0;
	m=0;
	s=0;
	ms=0;
}

CLab2View::~CLab2View()
{
}

void CLab2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLab2View)
	DDX_Text(pDX, IDC_TIME, m_strTime);
	//}}AFX_DATA_MAP
}

BOOL CLab2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CLab2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CLab2View printing

BOOL CLab2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLab2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CLab2View diagnostics

#ifdef _DEBUG
void CLab2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CLab2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLab2Doc* CLab2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab2Doc)));
	return (CLab2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab2View message handlers

void CLab2View::OnTimeStart() 
{
	// TODO: Add your command handler code here
	m_timer=SetTimer(1,100,NULL);    //设置定时器
	m_btimer=false;
}

void CLab2View::OnTimeStop() 
{
	// TODO: Add your command handler code here
	KillTimer(m_timer);   //销毁定时器
	m_btimer=true;
}

void CLab2View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_strTime.Format("%d:%d:%d.%d",h,m,s,ms);
	UpdateData(false);    //刷新控件显示
	ms++;
	if(ms==10){ms=0;s++;}
	if(s==60){s=0;m++;}
	if(m==60){m=0;h++;}
	CFormView::OnTimer(nIDEvent);
}

void CLab2View::OnUpdateTimeStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(!m_btimer)
		pCmdUI->Enable(false);
	
}

void CLab2View::OnTimeCurrent() 
{
	// TODO: Add your command handler code here
	OnTimeStop();
	CTime t=CTime::GetCurrentTime();
	CString str;
	str.Format("Current Time is %02d:%02d:%02d",t.GetHour(),t.GetMinute(),t.GetSecond());
	MessageBox(str,NULL,MB_OK);
	h=m=s=ms=0;
	m_strTime.Format("%02d:%02d:%02d.%01d",h,m,s,ms);
	UpdateData(false);
}
