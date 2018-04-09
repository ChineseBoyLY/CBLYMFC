// lab6View.cpp : implementation of the CLab6View class
//

#include "stdafx.h"
#include "lab6.h"

#include "lab6Doc.h"
#include "lab6View.h"

#include "Math.h"
#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab6View

IMPLEMENT_DYNCREATE(CLab6View, CView)

BEGIN_MESSAGE_MAP(CLab6View, CView)
	//{{AFX_MSG_MAP(CLab6View)
	ON_WM_CREATE()
	ON_COMMAND(ID_COLOR, OnColor)
	ON_COMMAND(ID_ELLIPSE, OnEllipse)
	ON_COMMAND(ID_ELLIRECT, OnEllirect)
	ON_COMMAND(ID_LINE, OnLine)
	ON_COMMAND(ID_RECT, OnRect)
	ON_COMMAND(ID_WIDTH1, OnWidth1)
	ON_COMMAND(ID_WIDTH2, OnWidth2)
	ON_COMMAND(ID_WIDTH3, OnWidth3)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_LINE, OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_RECT, OnUpdateRect)
	ON_UPDATE_COMMAND_UI(ID_ELLIRECT, OnUpdateEllirect)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_WIDTH1, OnUpdateWidth1)
	ON_UPDATE_COMMAND_UI(ID_WIDTH2, OnUpdateWidth2)
	ON_UPDATE_COMMAND_UI(ID_WIDTH3, OnUpdateWidth3)
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_COMMAND(ID_FILL, OnFill)
	ON_UPDATE_COMMAND_UI(ID_FILL, OnUpdateFill)
	ON_COMMAND(ID_FONT, OnFont)
	ON_COMMAND(ID_PLAYMUSIC, OnPlaymusic)
	ON_COMMAND(ID_STOPMUSIC, OnStopmusic)
	ON_COMMAND(ID_PEN, OnPen)
	ON_UPDATE_COMMAND_UI(ID_PEN, OnUpdatePen)
	ON_COMMAND(ID_3dRect, On3dRect)
	ON_UPDATE_COMMAND_UI(ID_3dRect, OnUpdate3dRect)
	ON_COMMAND(ID_Chord, OnChord)
	ON_UPDATE_COMMAND_UI(ID_Chord, OnUpdateChord)
	ON_COMMAND(ID_CIRCLE, OnCircle)
	ON_UPDATE_COMMAND_UI(ID_CIRCLE, OnUpdateCircle)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab6View construction/destruction

CLab6View::CLab6View()
{
	// TODO: add construction code here
	m_type=1;
	m_color=RGB(0,0,255);
	m_fillcolor=RGB(0,255,0);
	m_nmx=0;
	m_nmy=0;
	m_width=1;
	m_pbmp=new CBitmap;
	m_pmdc=new CDC;
	m_pold=0;
	m_pnew=0;
	m_bdoing=false;
	//画笔
	m_PrePoint = CPoint(0, 0);
    m_bLButtonDown = false;
}

CLab6View::~CLab6View()
{
	delete m_pbmp;
	delete m_pmdc;
}

BOOL CLab6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLab6View drawing

void CLab6View::OnDraw(CDC* pDC)
{
	CLab6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBitmap * poldbmp=m_pmdc->SelectObject(m_pbmp);
	pDC->BitBlt(0,0,m_nmx,m_nmy,m_pmdc,0,0,SRCCOPY);
	m_pmdc->SelectObject(poldbmp);
}

/////////////////////////////////////////////////////////////////////////////
// CLab6View printing

BOOL CLab6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLab6View diagnostics

#ifdef _DEBUG
void CLab6View::AssertValid() const
{
	CView::AssertValid();
}

void CLab6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab6Doc* CLab6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab6Doc)));
	return (CLab6Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab6View message handlers

int CLab6View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_nmx=GetSystemMetrics(SM_CXSCREEN);
	m_nmy=GetSystemMetrics(SM_CYSCREEN);
	CDC *pDC=GetDC();
	m_pmdc->CreateCompatibleDC(pDC);
	m_pbmp->CreateCompatibleBitmap(pDC,m_nmx,m_nmy);
	CBitmap * pOldbitmap=m_pmdc->SelectObject(m_pbmp);
	CBrush brush;
	brush.CreateStockObject(WHITE_BRUSH);
	CRect rect(-1,-1,m_nmx,m_nmy);
	m_pmdc->FillRect(rect,&brush);
	m_pmdc->SelectObject(pOldbitmap);
	ReleaseDC(pDC);
	return 0;
}

void CLab6View::OnColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_PREVENTFULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult=m_color;
	if(dlg.DoModal()==IDOK)
	{
		m_color=dlg.GetColor();
	}
}

void CLab6View::OnEllipse() 
{
	// TODO: Add your command handler code here
	m_type=4;
}

void CLab6View::OnEllirect() 
{
	// TODO: Add your command handler code here
	m_type=3;
}

void CLab6View::OnLine() 
{
	// TODO: Add your command handler code here
	m_type=1;
}

void CLab6View::OnRect() 
{
	// TODO: Add your command handler code here
	m_type=2;
}

void CLab6View::OnWidth1() 
{
	// TODO: Add your command handler code here
	m_width=1;
}

void CLab6View::OnWidth2() 
{
	// TODO: Add your command handler code here
	m_width=2;
}

void CLab6View::OnWidth3() 
{
	// TODO: Add your command handler code here
	m_width=3;
}

void CLab6View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//int count=0;
	//count++;
	// TODO: Add your message handler code here and/or call default
	if(m_bdoing) return;
	m_bdoing=true;
	m_pnew=point;
	m_pold=point;

	//填充操作
	if(m_type==5)
	{	 
		CBrush newBrush;
		newBrush.CreateSolidBrush(m_color);
		CBrush* poldbrush=m_pmdc->SelectObject(&newBrush);
		CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
		m_pmdc->ExtFloodFill(point.x,point.y,m_pmdc->GetPixel(point),FLOODFILLSURFACE); 
		Invalidate(false); 
		m_pmdc->SelectObject(poldbrush);
		m_pmdc->SelectObject(poldbmp);
		m_bdoing=FALSE; 
	}
	//橡皮擦
	if(m_type==6)
	{	 
		m_bLButtonDown = true;
		CDC *pDC = GetDC();
		pDC->MoveTo(point);
	//	Invalidate(false);
		m_PrePoint = point;
		ReleaseDC(pDC);
	}
	//CBrush * pbrush=pDC->SelectObject(&newBrush);
	//pDC->SelectObject(newBrush);
	//pDC->SelectObject(pbrush);
	//ReleaseDC(pDC);
	//CView::OnLButtonDown(nFlags, point);
}

void CLab6View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bdoing) return;
	CDC * pDC=GetDC();
	CBitmap * poldbmp=m_pmdc->SelectObject(m_pbmp);
	CPen pen;
	pen.CreatePen(PS_SOLID,m_width,m_color);
	CPen * poldpen=pDC->SelectObject(&pen);
	CBrush * poldbrush=(CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	CRect rectold(m_pold,m_pnew);
	rectold.NormalizeRect();
	rectold.InflateRect(m_width,m_width);
	pDC->BitBlt(rectold.left,rectold.top,rectold.Width(),rectold.Height(),m_pmdc,rectold.left,rectold.top,SRCCOPY);
	CRect rectnew(m_pold,point);
	
	int r=0;
	r=(sqrt(pow((m_pold.x-point.x),2)+pow((m_pold.y-point.y),2)))/2;
	

	switch(m_type)
	{
	case 1:
		pDC->MoveTo(m_pold);
		pDC->LineTo(point);
		break;
	case 2:
		pDC->Rectangle(rectnew);
		break;
	case 3:
		pDC->RoundRect(m_pold.x,m_pold.y,point.x,point.y,10,10);
		break;
	case 4:
		pDC->Ellipse(rectnew);
		break;
	case 6:
		//画刷
		if(m_bLButtonDown)
		{
			CPen pen;
			pen.CreatePen(PS_SOLID,25,RGB(255,255,255));
			CPen * poldpen=pDC->SelectObject(&pen);
			pDC->MoveTo(m_pold);
			pDC->LineTo(point);
		//	Invalidate(true);
		}
		break;
	case 9:
		pDC->Ellipse(m_pold.x-r,m_pold.y-r,m_pold.x+r,m_pold.y+r);//圆形
	//	Invalidate(false);
		break;
	default:
		break;
	}
	m_pmdc->SelectObject(poldbmp);
	pDC->SelectObject(poldpen);
	pDC->SelectObject(poldbrush);
	ReleaseDC(pDC);
	m_pnew=point;

//	CView::OnMouseMove(nFlags, point);
}
//CPoint pointArr[5];
void CLab6View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	int r=0;
	r=(sqrt(pow((m_pold.x-point.x),2)+pow((m_pold.y-point.y),2)))/2;
	// TODO: Add your message handler code here and/or call default
	if(!m_bdoing) return;
	m_bdoing=false;
	CBitmap * poldbmp=m_pmdc->SelectObject(m_pbmp);
	CPen pen;
	pen.CreatePen(PS_SOLID,m_width,m_color);
	CPen * poldpen=m_pmdc->SelectObject(&pen);
	CBrush * poldbrush=(CBrush *)m_pmdc->SelectStockObject(NULL_BRUSH);
	CRect rect(m_pnew,m_pold);
	switch(m_type)
	{
	case 1:
		m_pmdc->MoveTo(m_pold);
		m_pmdc->LineTo(point);
		break;
	case 2:
		m_pmdc->Rectangle(rect);
		break;
	case 3:
		m_pmdc->RoundRect(m_pnew.x,m_pnew.y,m_pold.x,m_pold.y,10,10);
		break;
	case 4:
		m_pmdc->Ellipse(rect);
		break;
	case 6:
		if(true){
		m_bLButtonDown = false;
		CPen pen;
		pen.CreatePen(PS_SOLID,25,RGB(255,255,255));
		CPen * poldpen=m_pmdc->SelectObject(&pen);
		m_pmdc->MoveTo(m_pold);
		m_pmdc->LineTo(point);
		}
		break;
	case 7:
		m_pmdc->Draw3dRect(rect,m_color,RGB(165,168,1));
		m_pmdc->DrawEdge(rect,BDR_SUNKENOUTER|BDR_SUNKENINNER,BF_TOPRIGHT);
		break;
	case 8:
		m_pmdc->Chord(rect,m_pold,m_pnew);//椭圆弧
		break;
	case 9:
		m_pmdc->Ellipse(m_pold.x-r,m_pold.y-r,m_pold.x+r,m_pold.y+r);//圆形
		break;
	default:
		break;
	}
	Invalidate(false);
	m_pmdc->SelectObject(poldbmp);
	m_pmdc->SelectObject(poldpen);
	m_pmdc->SelectObject(poldbrush);
//	CView::OnLButtonUp(nFlags, point);
}

void CLab6View::OnUpdateLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==1);
}

void CLab6View::OnUpdateRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==2);
}

void CLab6View::OnUpdateEllirect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==3);
}

void CLab6View::OnUpdateEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==4);
}

void CLab6View::OnUpdateFill(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==5);
}

void CLab6View::OnUpdateWidth1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_width==1);
}

void CLab6View::OnUpdateWidth2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_width==2);
}

void CLab6View::OnUpdateWidth3(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_width==3);
}

void CLab6View::OnClear() 
{
	// TODO: Add your command handler code here
	m_pbmp=new CBitmap;
	m_pmdc=new CDC;

	Invalidate(true);

	m_nmx=GetSystemMetrics(SM_CXSCREEN);
	m_nmy=GetSystemMetrics(SM_CYSCREEN);
	CDC *pDC=GetDC();
	m_pmdc->CreateCompatibleDC(pDC);
	m_pbmp->CreateCompatibleBitmap(pDC,m_nmx,m_nmy);
	CBitmap * pOldbitmap=m_pmdc->SelectObject(m_pbmp);
	CBrush brush;
	brush.CreateStockObject(WHITE_BRUSH);
	CRect rect(-1,-1,m_nmx,m_nmy);
	m_pmdc->FillRect(rect,&brush);
	m_pmdc->SelectObject(pOldbitmap);
	ReleaseDC(pDC);
}

void CLab6View::OnFill() 
{
	// TODO: Add your command handler code here
	m_type=5;
}
void CLab6View::OnPen() 
{
	// TODO: Add your command handler code here
	m_type=6;
}
void CLab6View::OnUpdatePen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==6);
}
void CLab6View::OnFont() 
{
	// TODO: Add your command handler code here
	CDC *pDC=GetDC();
	pDC->SetBkColor(RGB(240,240,250));
	pDC->SetTextColor(RGB(255,0,0));
	int ny=5;
	int ndl=0;
	int i;
	for(i=24;i>=12;i-=4)
	{
		FontOut(pDC,ny,i,ndl);
		ndl+=300;
	}
}
void CLab6View::FontOut(CDC* pDC,int& nHeight,int nPoints,int dline)
{
	//定义文本结构变量
	TEXTMETRIC textM;
	CFont font;
	CString str;
//	CFontDialog dlg;
//	dlg.m_cf.Flags |= CC_PREVENTFULLOPEN | CC_RGBINIT;
	//dlg.m_cf.
/*	if(dlg.DoModal()==IDOK)
	{
		m_color=dlg.GetColor();
	}*/
	font.CreateFont(-nPoints,0,-dline,0,400,false,false,0,ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,"楷体");
	CFont *poldfont=(CFont*)pDC->SelectObject(&font);
	//获取文本信息
	pDC->GetTextMetrics(&textM);
	str.Format("这是%d点阵宋体字",nPoints);
	pDC->TextOut(30,nHeight,str);
	
	nHeight+=textM.tmHeight+textM.tmExternalLeading;
	//恢复原有字体
	pDC->SelectObject(poldfont);
}


void CLab6View::OnPlaymusic() 
{
	// TODO: Add your command handler code here
	PlaySound(".\\123.wav", NULL, SND_ASYNC);//播放     SND_ASYNC用异步方式播放声音，PlaySound函数在开始播放后立即返回。
}

void CLab6View::OnStopmusic() 
{
	// TODO: Add your command handler code here
	PlaySound(NULL, NULL, SND_ASYNC);//播放
}


void CLab6View::On3dRect() 
{
	// TODO: Add your command handler code here
	m_type=7;
}

void CLab6View::OnUpdate3dRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==7);
}

void CLab6View::OnChord() 
{
	// TODO: Add your command handler code here
	m_type=8;
}

void CLab6View::OnUpdateChord(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==8);
}

void CLab6View::OnCircle() 
{
	// TODO: Add your command handler code here
	m_type=9;
}

void CLab6View::OnUpdateCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==9);
}
