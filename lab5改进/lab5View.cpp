// lab5View.cpp : implementation of the CLab5View class
//

#include "stdafx.h"
#include "lab5.h"
#include "windows.h" 
#include "lab5Doc.h"
#include "lab5View.h"

#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab5View

IMPLEMENT_DYNCREATE(CLab5View, CFormView)

BEGIN_MESSAGE_MAP(CLab5View, CFormView)
	//{{AFX_MSG_MAP(CLab5View)
	ON_CBN_SELCHANGE(IDC_COMBO_SNO, OnSelchangeComboSno)
	ON_EN_CHANGE(IDC_EDIT_AGE, OnChangeEditAge)
	ON_EN_CHANGE(IDC_EDIT_NAME, OnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_SCHOOL, OnChangeEditSchool)
	ON_EN_CHANGE(IDC_EDIT_SEX, OnChangeEditSex)
	ON_EN_CHANGE(IDC_EDIT_TEL, OnChangeEditTel)
	ON_COMMAND(ID_FILE_MYOPEN, OnFileMyopen)
	ON_COMMAND(ID_FILE_MYSAVE, OnFileMysave)
	ON_COMMAND(ID_PLAY, OnPlay)
	ON_COMMAND(ID_STOP, OnStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab5View construction/destruction

CLab5View::CLab5View()
	: CFormView(CLab5View::IDD)
{
	//{{AFX_DATA_INIT(CLab5View)
	m_age = 0;
	m_name = _T("");
	m_school = _T("");
	m_sex = _T("");
	m_tel = _T("");

	m_nCurrentNo=0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	
}

CLab5View::~CLab5View()
{
}

void CLab5View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLab5View)
	DDX_Control(pDX, IDC_COMBO_SNO, m_noList);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_SCHOOL, m_school);
	DDX_Text(pDX, IDC_EDIT_SEX, m_sex);
	DDX_Text(pDX, IDC_EDIT_TEL, m_tel);
	//}}AFX_DATA_MAP
}

BOOL CLab5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CLab5View::OnInitialUpdate()
{
	PlaySound(".\\123.wav", NULL, SND_ASYNC);//播放
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	char temp[4];
	CString k;
	for(int i=0;i<40;i++)
	{
		if(i<9) k="1140820";
		else     k="114082";
		m_noList.InsertString(i,k+itoa(i+1,temp,10));
	}
	CLab5Doc *pDoc=GetDocument();
	m_noList.SetCurSel(0);

	m_name=pDoc->m_student[0].name;
	m_age=pDoc->m_student[0].age;
	m_school=pDoc->m_student[0].school;
	m_sex=pDoc->m_student[0].sex;
	m_tel=pDoc->m_student[0].tel;

	UpdateData(false);
}

/////////////////////////////////////////////////////////////////////////////
// CLab5View printing

BOOL CLab5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLab5View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CLab5View diagnostics

#ifdef _DEBUG
void CLab5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CLab5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLab5Doc* CLab5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab5Doc)));
	return (CLab5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab5View message handlers

void CLab5View::OnSelchangeComboSno() 
{
	// TODO: Add your control notification handler code here
	CLab5Doc *pDoc=GetDocument();
	m_nCurrentNo=m_noList.GetCurSel();
	m_name=pDoc->m_student[m_nCurrentNo].name;
	m_age=pDoc->m_student[m_nCurrentNo].age;
	m_school=pDoc->m_student[m_nCurrentNo].school;
	m_sex=pDoc->m_student[m_nCurrentNo].sex;
	m_tel=pDoc->m_student[m_nCurrentNo].tel;
	UpdateData(false);
}

void CLab5View::OnChangeEditAge() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CLab5Doc *pDoc=GetDocument();
	UpdateData(true);
	if(pDoc->m_student[m_nCurrentNo].age!=m_age)
	{
		pDoc->m_student[m_nCurrentNo].age=m_age;
		pDoc->SetModifiedFlag();
	}
}

void CLab5View::OnChangeEditName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CLab5Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].name,m_name))
	{
		strcpy(pDoc->m_student[m_nCurrentNo].name,m_name);
		pDoc->SetModifiedFlag();
	}
}

void CLab5View::OnChangeEditSchool() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CLab5Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].school,m_school))
	{
		strcpy(pDoc->m_student[m_nCurrentNo].school,m_school);
		pDoc->SetModifiedFlag();
	}
}

void CLab5View::OnChangeEditSex() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CLab5Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].sex,m_sex))
	{
		strcpy(pDoc->m_student[m_nCurrentNo].sex,m_sex);
		pDoc->SetModifiedFlag();
	}
}

void CLab5View::OnChangeEditTel() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CLab5Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].tel,m_tel))
	{
		strcpy(pDoc->m_student[m_nCurrentNo].tel,m_tel);
		pDoc->SetModifiedFlag();
	}
}

void CLab5View::OnFileMyopen() 
{
	// TODO: Add your command handler code here
	CString strFilter="Dat Files(*.dat)|*.dat|All Files(*.*)|*.*||";
	//通用文件对话框
	CFileDialog FileDlg(true,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(FileDlg.DoModal()!=IDOK)return;
	CString strFileName=FileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeRead))
	{
		AfxMessageBox("打开文件失败");
		return;
	}
	CLab5Doc *pDoc=GetDocument();
	//读出文件中的数据，存放到文档类的数据成员中
	f.Read(&m_nCurrentNo,sizeof(int));
	for(int i=0;i<=40;i++)
	{
		f.Read(pDoc->m_student[i].name,10);
		f.Read(pDoc->m_student[i].sex,3);
		f.Read(&(pDoc->m_student[i].age),sizeof(int));
		f.Read(pDoc->m_student[i].tel,14);
		f.Read(pDoc->m_student[i].school,30);
	}
	f.Close();
	//将文档类的数据传递给视图类的数据成员，并显示
	m_noList.SetCurSel(m_nCurrentNo);
	m_name=pDoc->m_student[m_nCurrentNo].name;
	m_sex=pDoc->m_student[m_nCurrentNo].sex;
	m_age=pDoc->m_student[m_nCurrentNo].age;
	m_school=pDoc->m_student[m_nCurrentNo].school;
	m_tel=pDoc->m_student[m_nCurrentNo].tel;

	UpdateData(false);
}

void CLab5View::OnFileMysave() 
{
	// TODO: Add your command handler code here
	CString strFilter="Dat Files(*.dat)|*.dat|All Files(*.*)|*.*||";
	//通用文件对话框
	CFileDialog FileDlg(true,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(FileDlg.DoModal()!=IDOK)return;
	CString strFileName=FileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeCreate | CFile::modeWrite))
	{
		AfxMessageBox("创建文件失败");
		return;
	}

	CLab5Doc *pDoc=GetDocument();
	f.Write(&m_nCurrentNo,sizeof(int));
	for(int i=0;i<=40;i++)
	{
		f.Write(pDoc->m_student[i].name,10);
		f.Write(pDoc->m_student[i].sex,3);
		f.Write(&(pDoc->m_student[i].age),sizeof(int));
		f.Write(pDoc->m_student[i].tel,14);
		f.Write(pDoc->m_student[i].school,30);
	}
	f.Close();
}

void CLab5View::OnPlay()
{
	PlaySound(".\\123.wav", NULL, SND_ASYNC);//播放
}

void CLab5View::OnStop()
{
	PlaySound(NULL, NULL, SND_ASYNC);//停止播放
}	


