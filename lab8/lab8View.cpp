// lab8View.cpp : implementation of the CLab8View class
//

#include "stdafx.h"
#include "lab8.h"

#include "lab8Set.h"
#include "lab8Doc.h"
#include "lab8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab8View

IMPLEMENT_DYNCREATE(CLab8View, CRecordView)

BEGIN_MESSAGE_MAP(CLab8View, CRecordView)
	//{{AFX_MSG_MAP(CLab8View)
	ON_COMMAND(ID_RECORD_FIRST, OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, OnRecordLast)
	ON_COMMAND(ID_RECORD_NEXT, OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, OnRecordPrev)
	ON_BN_CLICKED(IDC_RECORD_ADD, OnRecordAdd)
	ON_BN_CLICKED(IDC_RECORD_DEL, OnRecordDel)
	ON_BN_CLICKED(IDC_RECORD_EDIT, OnRecordEdit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab8View construction/destruction

CLab8View::CLab8View()
	: CRecordView(CLab8View::IDD)
{
	//{{AFX_DATA_INIT(CLab8View)
	m_pSet = NULL;
	m_ID = _T("");
	m_name = _T("");
	m_position = _T("");
	m_singer = _T("");
	m_writer = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CLab8View::~CLab8View()
{
}

void CLab8View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLab8View)
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_POSITION, m_position);
	DDX_Text(pDX, IDC_EDIT_SINGER, m_singer);
	DDX_Text(pDX, IDC_EDIT_WRITER, m_writer);
	//}}AFX_DATA_MAP
}

BOOL CLab8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CLab8View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_lab8Set;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	try
	{
		m_pSet=new CLab8Set();
		m_pSet->Open();
		MyUpdateData();
	}
	catch(CDBException *pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLab8View printing

BOOL CLab8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLab8View diagnostics

#ifdef _DEBUG
void CLab8View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CLab8View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CLab8Doc* CLab8View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab8Doc)));
	return (CLab8Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab8View database support
CRecordset* CLab8View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CLab8View message handlers

void CLab8View::OnRecordFirst() 
{
	// TODO: Add your command handler code here
	m_pSet->MoveFirst();
	MyUpdateData();
}

void CLab8View::OnRecordLast() 
{
	// TODO: Add your command handler code here
	m_pSet->MoveLast();
	MyUpdateData();
}

void CLab8View::OnRecordNext() 
{
	// TODO: Add your command handler code here
	m_pSet->MoveNext();
	MyUpdateData();
}

void CLab8View::OnRecordPrev() 
{
	// TODO: Add your command handler code here
	m_pSet->MovePrev();
	MyUpdateData();
}

void CLab8View::OnRecordAdd() 
{
	// TODO: Add your control notification handler code here
	try
	{
		m_pSet->AddNew();
		UpdateData(true);
		m_pSet->m_column1=m_ID;
		m_pSet->m_column2=m_name;
		m_pSet->m_column3=m_singer;
		m_pSet->m_column4=m_writer;
		m_pSet->m_column5=m_position;
		m_pSet->Update();
		m_pSet->Requery();
	}
	catch(CDBException *pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

void CLab8View::OnRecordDel() 
{
	// TODO: Add your control notification handler code here
	try
	{
		m_pSet->Delete();
		m_pSet->Requery();
		MyUpdateData();
	}
	catch(CDBException *pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

void CLab8View::OnRecordEdit() 
{
	// TODO: Add your control notification handler code here
	try
	{
		m_pSet->Edit();
		UpdateData(true);
		m_pSet->m_column1=m_ID;
		m_pSet->m_column2=m_name;
		m_pSet->m_column3=m_singer;
		m_pSet->m_column4=m_writer;
		m_pSet->m_column5=m_position;
		m_pSet->Update();
	}
	catch(CDBException *pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

void CLab8View::MyUpdateData()
{
	m_ID=m_pSet->m_column1;
	m_name=m_pSet->m_column2;
	m_singer=m_pSet->m_column3;
	m_writer=m_pSet->m_column4;
	m_position=m_pSet->m_column5;
}
