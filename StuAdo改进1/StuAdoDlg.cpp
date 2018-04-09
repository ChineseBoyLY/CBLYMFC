// StuAdoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StuAdo.h"
#include "StuAdoDlg.h"

#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

extern CStuAdoApp theApp;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuAdoDlg dialog

CStuAdoDlg::CStuAdoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuAdoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuAdoDlg)
	m_address = _T("");
	m_name = _T("");
	m_id = _T("");
	m_age = _T("20");
	m_sex = "��";
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStuAdoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuAdoDlg)
	DDX_Control(pDX, IDC_FOLLOW_ADDRESS, m_follow_address);
	DDX_Control(pDX, IDC_FOLLOW_NAME, m_follow_name);
	DDX_Control(pDX, IDC_FOLLOW_ID, m_follow_id);
	DDX_Control(pDX, IDC_LISTALL, m_listall);
	DDX_Control(pDX, IDC_LISTDATABASE, m_listdatabase);
	DDX_Control(pDX, IDC_MODIFY, m_modify);
	DDX_Control(pDX, IDC_EXITSYS, m_exit);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Control(pDX, IDC_ADD, m_add);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_AGE1, m_age);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStuAdoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuAdoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LISTALL, OnListall)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EXITSYS, OnExitsys)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_LBN_SELCHANGE(IDC_LISTDATABASE, OnSelchangeListdatabase)
	ON_BN_CLICKED(IDC_FOLLOW_ID, OnFollowId)
	ON_BN_CLICKED(IDC_FOLLOW_NAME, OnFollowName)
	ON_BN_CLICKED(IDC_FOLLOW_ADDRESS, OnFollowAddress)
	ON_COMMAND(ID_PLAY_MUSIC, OnPlayMusic)
	ON_COMMAND(ID_STOP_MUSIC, OnStopMusic)
	ON_BN_CLICKED(IDC_BOY, OnBoy)
	ON_BN_CLICKED(IDC_GIRL, OnGirl)
	ON_EN_KILLFOCUS(IDC_AGE1, OnKillfocusAge1)
	ON_EN_KILLFOCUS(IDC_ID, OnKillfocusId)
	ON_EN_KILLFOCUS(IDC_NAME, OnKillfocusName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuAdoDlg message handlers
CToolBar m_ToolBar;
BOOL CStuAdoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	PlaySound("123.wav", NULL, SND_FILENAME | SND_ASYNC);
	m_pRecordset.CreateInstance(_uuidof(Recordset));
	try
	{
		m_pRecordset->Open( "SELECT * FROM t_stu",theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//=================================
	m_ToolBar.Create(this); //���������� 
	m_ToolBar.LoadToolBar(IDR_TOOLBAR1);//���ع�����
	//�ó��ؼ�����С.
	CRect rect; 
	CRect rectNow; 
	GetClientRect(rect); 
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0,reposQuery,rectNow); 
	//���ÿؼ���λ�� 
	CPoint ptOffset(rectNow.left-rect.left,rectNow.top-rect.top); 
	CRect rcChild; 
	CWnd* pwndChild=GetWindow(GW_CHILD); 
	while (pwndChild)
	{                                
		pwndChild->GetWindowRect(rcChild);
		ScreenToClient(rcChild);
		rcChild.OffsetRect(ptOffset); 
		pwndChild->MoveWindow(rcChild,FALSE);
		pwndChild=pwndChild->GetNextWindow();
	}
	//�����Ի���ߴ� 
	CRect rcWindow; 
	GetWindowRect(rcWindow); 
	rcWindow.right+=rect.Width()-rectNow.Width();
	rcWindow.bottom+=rect.Height()-rectNow.Height();
	MoveWindow(rcWindow, FALSE); 
	//�ؼ�����λ 
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);    
	//�Կ����
	CenterWindow(); 
	
	//==============================
	((CButton*)GetDlgItem(IDC_BOY))->SetCheck(true);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStuAdoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStuAdoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	   CPaintDC dc(this); 
       CRect rect;
       GetClientRect(&rect);       //�õ���ǰ�Ի���ĳߴ�
       dc.FillSolidRect(&rect,RGB(192,248,202));    //���ƶԻ��򱳾�ɫ

	   CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStuAdoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStuAdoDlg::showInfo()
{
	_variant_t var;
    CString strName,strAddress,strId,strSex,strAge;
    m_listdatabase.ResetContent();
    strId=strName=strAddress=strAge=strSex="";
	long count=0;
    try
    {
		if(!m_pRecordset->BOF)    
			m_pRecordset->MoveFirst();
		else
		{
			AfxMessageBox("��������Ϊ��");
			return;
		}
		while(!m_pRecordset->adoEOF)
		{
			var=m_pRecordset->GetCollect("t_id");
			if(var.vt!=VT_NULL)
				strId = (LPCSTR)_bstr_t(var);
			var=m_pRecordset->GetCollect("t_name");
			if(var.vt!=VT_NULL)
				strName = (LPCSTR)_bstr_t(var);
			var=m_pRecordset->GetCollect("t_address");
			if(var.vt!=VT_NULL)
				strAddress= (LPCSTR)_bstr_t(var);
			var=m_pRecordset->GetCollect("t_sex");
			if(var.vt!=VT_NULL)
				strSex= (LPCSTR)_bstr_t(var);
			var=m_pRecordset->GetCollect("t_age");
			if(var.vt!=VT_NULL)
				strAge= (LPCSTR)_bstr_t(var);

			
			if(strName.GetLength()==4)
			{
				m_listdatabase.AddString(strId+"    "+strName+"      "+strSex+"    "+strAge+"    "+strAddress);
			}
			else if(strName.GetLength()==6)
			{
				m_listdatabase.AddString(strId+"    "+strName+"    "+strSex+"    "+strAge+"    "+strAddress);
			}
			else
			{
				m_listdatabase.AddString(strId+"    "+strName+"  "+strSex+"    "+strAge+"    "+strAddress);
			}
			m_pRecordset->MoveNext();
			count++;
		}
		
		CString str="";
		str.Format("һ����%ld����¼��",count);
		AfxMessageBox(str,NULL,MB_OK);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
}

void CStuAdoDlg::OnListall() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->Close();
	try
	{
		m_pRecordset->Open( "SELECT * FROM t_stu order by t_id desc",theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	showInfo();
}

void CStuAdoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_id == "" || m_name == ""|| m_address== "")
    {
		AfxMessageBox("ѧ�ţ������ͼ�����Ϣ����Ϊ��!");
		return;
    }
	//�Ȳ�ѯ�����ظ���û��
	//==============================================================
	CString strSql;
	strSql.Format("select * from t_stu where t_id = '%s'",m_id);
	//����
	BSTR bsSql = strSql.AllocSysString();
	m_pRecordset->Close();
	try
	{
		m_pRecordset->Open(bsSql,theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	int count=0;
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveNext();
		count++;
	}
	if(count>=1)
	{
		AfxMessageBox("���ݿ����Ѿ����ڸõ�ѧ��");
		return;
	}
	//=============================================================
	
	//==============================================================
    try
    {
		m_pRecordset->AddNew(); 
		m_pRecordset->PutCollect("t_id",_variant_t(m_id));
		m_pRecordset->PutCollect("t_name",_variant_t(m_name));
		m_pRecordset->PutCollect("t_address",_variant_t(m_address));
		m_pRecordset->PutCollect("t_sex",_variant_t(m_sex));
		m_pRecordset->PutCollect("t_age",_variant_t(m_age));
		m_pRecordset->Update();
		int nCurSel = m_listdatabase.GetCurSel();
		OnListall();
		m_listdatabase.SetCurSel(nCurSel);
		OnSelchangeListdatabase();
    }
    catch(_com_error *e)
    {
		AfxMessageBox(e->ErrorMessage());
    }	
}

void CStuAdoDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int n=m_listdatabase.GetCount();

	if(n==0)
		return;
	else 
		if(m_listdatabase.GetCurSel() < 0 || m_listdatabase.GetCurSel() > n)
			m_listdatabase.SetCurSel(0);
		try
		{
			m_pRecordset->Delete(adAffectCurrent);
			m_pRecordset->Update();
			int nCurSel=m_listdatabase.GetCurSel();
			m_listdatabase.DeleteString(nCurSel);
			n--;
			if(nCurSel<n && n!=0)
				m_listdatabase.SetCurSel(nCurSel);
			else if(n!=0)
				m_listdatabase.SetCurSel(nCurSel-1);
			OnSelchangeListdatabase();
		}    
		catch(_com_error *e)
		{
			AfxMessageBox(e->ErrorMessage());    
		}
}

void CStuAdoDlg::OnExitsys() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CStuAdoDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);    
	if(m_listdatabase.GetCount()==0||m_id==""||m_name==""||m_address==""|| m_sex== "")
	{
		AfxMessageBox("�ռ�¼��ѧ�š��������Ա𡢼���Ϊ��!");
		return;
    }
    else if(m_listdatabase.GetCurSel()<0||m_listdatabase.GetCurSel()>m_listdatabase.GetCount());
    m_listdatabase.SetCurSel(0);
    try
    {  
		//m_pRecordset->PutCollect("t_id",_variant_t(m_id));//�����������޸�
		m_pRecordset->PutCollect("t_name",_variant_t(m_name));
		m_pRecordset->PutCollect("t_address",_variant_t(m_address));
		m_pRecordset->PutCollect("t_sex",_variant_t(m_sex));
		m_pRecordset->PutCollect("t_age",_variant_t(m_age));
		m_pRecordset->Update();

		int nCurSel=m_listdatabase.GetCurSel();
		OnListall();
		m_listdatabase.SetCurSel(nCurSel);

		OnSelchangeListdatabase();
    }
    catch(_com_error *e)
    {    
		AfxMessageBox(e->ErrorMessage());
    }	
}

void CStuAdoDlg::OnSelchangeListdatabase() 
{
	// TODO: Add your control notification handler code here
	int curSel=m_listdatabase.GetCurSel();
	if(curSel<0)
		return;
	_variant_t var;
	try
	{	
		m_pRecordset->MoveFirst();
		m_pRecordset->Move(long(curSel));
		var=m_pRecordset->GetCollect("t_id");
		if(var.vt!=VT_NULL)
			m_id=(LPCSTR)_bstr_t(var);
		var=m_pRecordset->GetCollect("t_name");
		if(var.vt!=VT_NULL)
			m_name=(LPCSTR)_bstr_t(var);
		var=m_pRecordset->GetCollect("t_address");
		if(var.vt!=VT_NULL)
			m_address=(LPCSTR)_bstr_t(var);
		var=m_pRecordset->GetCollect("t_sex");
		if(var.vt!=VT_NULL)
			m_sex=(LPCSTR)_bstr_t(var);
		var=m_pRecordset->GetCollect("t_age");
		if(var.vt!=VT_NULL)
			m_age=(LPCSTR)_bstr_t(var);
			
		if(m_sex=="��")
		{
			((CButton*)GetDlgItem(IDC_BOY))->SetCheck(true);
			((CButton*)GetDlgItem(IDC_GIRL))->SetCheck(false);
		}
		else if(m_sex=="Ů")
		{
			((CButton*)GetDlgItem(IDC_GIRL))->SetCheck(true);
			((CButton*)GetDlgItem(IDC_BOY))->SetCheck(false);
		}
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
    }	
}

void CStuAdoDlg::OnFollowId() 
{
	UpdateData(true);
	if(m_id=="")
	{
		AfxMessageBox("ѧ��Ϊ��!");
		return;
    }
	//����б��
	m_listdatabase.ResetContent();									
	//�ر���һ�β�ѯ�ļ�¼��
	m_pRecordset->Close();
	//����SQL�������
	CString strSql;
	strSql="select * from t_stu where t_id like '%" + m_id + "%' order by t_id desc";
	//����
	BSTR bsSql = strSql.AllocSysString();
	try
	{
		m_pRecordset->Open(bsSql,theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	//����ѯ������б������ʾ����
	showInfo();
}

void CStuAdoDlg::OnFollowName() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_name=="")
	{
		AfxMessageBox("����Ϊ��!");
		return;
    }
	m_listdatabase.ResetContent();									//����б��
	//�ر���һ�β�ѯ�ļ�¼��
	m_pRecordset->Close();
	//����SQL�������
	CString strSql;
	strSql="select * from t_stu where t_name like '%" + m_name + "%' order by t_id desc";
	//����
	BSTR bsSql = strSql.AllocSysString();
	try
	{
		m_pRecordset->Open(bsSql,theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	//����ѯ������б������ʾ����
	showInfo();
}

void CStuAdoDlg::OnFollowAddress() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_address=="")
	{
		AfxMessageBox("����Ϊ��!");
		return;
    }
	m_listdatabase.ResetContent();									//����б��
	//�ر���һ�β�ѯ�ļ�¼��
	m_pRecordset->Close();
	//����SQL�������
	CString strSql;
	strSql="select * from t_stu where t_address like '%" + m_address + "%' order by t_id desc";
	//����
	BSTR bsSql = strSql.AllocSysString();
	try
	{
		m_pRecordset->Open(bsSql,theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	//����ѯ������б������ʾ����
	showInfo();
}

void CStuAdoDlg::countInfo()
{
	//
}

void CStuAdoDlg::OnPlayMusic() 
{
	// TODO: Add your command handler code here
	PlaySound("123.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void CStuAdoDlg::OnStopMusic() 
{
	// TODO: Add your command handler code here
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
}

void CStuAdoDlg::OnBoy() 
{
	// TODO: Add your control notification handler code here
	m_sex="��";
}

void CStuAdoDlg::OnGirl() 
{
	// TODO: Add your control notification handler code here
	m_sex="Ů";
}

void CStuAdoDlg::OnKillfocusAge1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(atoi(m_age)<15 || atoi(m_age)>30)
	{
		AfxMessageBox("���䷶Χ��15-30��֮�䣡���������롭��");
	}
}

void CStuAdoDlg::OnKillfocusId() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	//�Ѿ�����������������ֻ���������֣�����ֻ��Ҫ���Ƴ��ȼ���
	if(m_id.GetLength()>8)
	{
		AfxMessageBox("�������ֻ����8�����֣����������롭��");
	}
}

void CStuAdoDlg::OnKillfocusName() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_name.GetLength()>8)
	{
		AfxMessageBox("�������ֻ����8���ַ������������롭��");
	}
}
