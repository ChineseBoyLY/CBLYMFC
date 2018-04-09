// MyWcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyWc.h"
#include "MyWcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CMyWcDlg dialog

CMyWcDlg::CMyWcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyWcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyWcDlg)
	m_client_name = _T("");
	m_talk = FALSE;
	m_systemTime = _T("");
	m_server_name = _T("localhost");
	m_nPort = 800;
	m_send_info = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyWcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyWcDlg)
	DDX_Control(pDX, IDC_LIST_NAME, m_ctlName);
	DDX_Control(pDX, IDC_RECEIVED_INFO, m_ctlRecvd);
	DDX_Text(pDX, IDC_CLIENT_NAME, m_client_name);
	DDX_Check(pDX, IDC_CHECK1, m_talk);
	DDX_Text(pDX, IDC_EDIT_TIME, m_systemTime);
	DDX_Text(pDX, IDC_SERVER_NAME, m_server_name);
	DDX_Text(pDX, IDC_SERVER_PORT, m_nPort);
	DDX_Text(pDX, IDC_SEND_INFO, m_send_info);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyWcDlg, CDialog)
	//{{AFX_MSG_MAP(CMyWcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_CLOSE, OnClose)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWcDlg message handlers

BOOL CMyWcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	
	m_ctlName.InsertString(0,"所有人");
	m_ctlName.SetCurSel(0);
	UpdateData(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyWcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyWcDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyWcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyWcDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString cName = m_client_name;
	if(!cName.Compare(""))
	{
		AfxMessageBox("Client's name can not be null");
		return;
	}
	if(!sockClient.Create())
	{
		AfxMessageBox("Create WC socket failed");
		PostQuitMessage(0);
	}
	if(!sockClient.Connect(m_server_name,m_nPort))
	{
		if(sockClient!=NULL) sockClient.Close();
		MessageBox("连接失败");
		return;
	}
	strcpy(m_Dat.m_type,"CONNECTION");
	strcpy(m_Dat.m_strName,m_client_name);
	sockClient.Send(&m_Dat,sizeof(m_Dat));//向服务器发送客户资料，如用户名
	GetDlgItem(IDC_CONNECT)->EnableWindow(false);
	GetDlgItem(IDC_SEND)->EnableWindow(true);
	GetDlgItem(IDC_CLOSE)->EnableWindow(true);
	GetDlgItem(IDC_SERVER_PORT)->EnableWindow(false);
	GetDlgItem(IDC_CLIENT_NAME)->EnableWindow(false);
	GetDlgItem(IDC_SERVER_NAME)->EnableWindow(false);
}

void CMyWcDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	strcpy(m_Dat.m_type,"CLOSE");
	sockClient.Send(&m_Dat,sizeof(m_Dat));
	sockClient.Close();
	exit(0);
}

void CMyWcDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString talkingName;

	m_ctlName.GetText(m_ctlName.GetCurSel(),talkingName);
	if(talkingName != "所有人")
	{
		strcpy(m_Dat.m_type,"PRIVATE");
		strcpy(m_Dat.m_talkingName,talkingName);
	}
	else	strcpy(m_Dat.m_type,"MSG");
	memset(m_Dat.m_dbData,0,255);
	memcpy(m_Dat.m_dbData,m_send_info,m_send_info.GetLength());
	strcpy(m_Dat.m_strName,m_client_name);
	int iSent=sockClient.Send(&m_Dat,sizeof(m_Dat));
	if(iSent!=SOCKET_ERROR)
	{   m_ctlRecvd.AddString(m_client_name+"说：("+m_systemTime+")");
		m_ctlRecvd.AddString("     "+m_send_info);
        m_send_info="";
		UpdateData(false);
	}
}
