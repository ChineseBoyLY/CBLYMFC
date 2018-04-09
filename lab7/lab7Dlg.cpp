// lab7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "lab7.h"
#include "lab7Dlg.h"

#include "mmsystem.h"


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
// CLab7Dlg dialog

CLab7Dlg::CLab7Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLab7Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLab7Dlg)
	m_radio = -1;
	m_dight = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLab7Dlg)
	DDX_Control(pDX, IDC_SLIDER1, m_Slider);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	DDX_Radio(pDX, IDC_RADIO_WAVE, m_radio);
	DDX_Text(pDX, IDC_EDIT_DIGHT, m_dight);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLab7Dlg, CDialog)
	//{{AFX_MSG_MAP(CLab7Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO_WAVE, OnRadioWave)
	ON_BN_CLICKED(IDC_RADIO_MIDI, OnRadioMidi)
	ON_BN_CLICKED(IDC_RADIO_AVI, OnRadioAvi)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab7Dlg message handlers

BOOL CLab7Dlg::OnInitDialog()
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

	GetDlgItem(IDC_BUTTON_OPEN)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(false);

	m_Progress.SetRange(0,100);    
	m_Progress.ShowWindow(SW_HIDE);
	SetTimer(100,500,NULL);       
	
	m_Slider.SetRange(0,100);
    m_Slider.ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab7Dlg::OnPaint() 
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

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab7Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLab7Dlg::OnRadioWave() 
{
	// TODO: Add your control notification handler code here
	m_radio=0;
}

void CLab7Dlg::OnRadioMidi() 
{
	// TODO: Add your control notification handler code here
	m_radio=1;
}

void CLab7Dlg::OnRadioAvi() 
{
	// TODO: Add your control notification handler code here
	m_radio=2;
}
void CLab7Dlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	//更新Radio单选按钮关联变量m_radio
	CString strFilter;
	UpdateData(true); 
//	AfxMessageBox("gfdgfd");
	switch (m_radio)
	{
	case 0: strFilter = "Wave Files (*.wav)|*.wav|All Files (*.*)|*.*||";
		break;
	case 1: strFilter = "Midi Files (*.mid)|*.mid|All Files (*.*)|*.*||";
		break;
	case 2:  strFilter = "AVI Files (*.avi)|*.avi|All Files (*.*)|*.*||";
		break;
	}
	CFileDialog FileDlg(true, NULL, NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter, this);
	if (FileDlg.DoModal() == IDOK)
	{
		CString strFileName = FileDlg.GetPathName();
		char szFileName[_MAX_PATH];
		GetShortPathName((LPCSTR)strFileName, szFileName, _MAX_PATH);
		char szExt[8];
		_splitpath((const char *)szFileName, NULL, NULL, NULL, szExt);
		
		// 保存是否成功打开的状态
		MCIERROR mciError = 0;
		if (!stricmp(szExt, ".wav"))
			mciError = Open(szFileName, "waveaudio", "", m_hWnd);
		else if (!stricmp(szExt, ".mid"))
			mciError = Open(szFileName, "sequencer", "", m_hWnd);
		else if (!stricmp(szExt, ".avi"))
			mciError = Open(szFileName, "avivideo", "overlapped", m_hWnd);
		// 默认时间单位是 ms
		if (mciError == 0)
		{
			SetTimeFormat("ms");
		}
		//设置Button按钮的初始状态
		GetDlgItem(IDC_BUTTON_OPEN)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(false);
	}
}

void CLab7Dlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(false);
	m_Progress.ShowWindow (SW_SHOW);
	m_Slider.ShowWindow(SW_SHOW);			
	
	Play();
}

void CLab7Dlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	Stop();
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(false); 
    GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(true);
}

void CLab7Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(IsMediumPresent())
	{
		char szPos[1024];
		m_Progress.SetPos((int)(100*GetPosition(szPos)/GetLength()));
		m_Slider.SetPos((int)(100*GetPosition(szPos)/GetLength()));
		m_dight = itoa((100*GetPosition(szPos)/GetLength()),szPos,10);
		m_dight += "%";
		UpdateData(false);
	}
	CDialog::OnTimer(nIDEvent);
}



void CLab7Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	int  nSPos = m_Slider.GetPos();
	LONG lLength = GetLength();
	LONG lMPos = (LONG)(nSPos*lLength/100.0);
	Seek(lMPos);
	Play();

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


