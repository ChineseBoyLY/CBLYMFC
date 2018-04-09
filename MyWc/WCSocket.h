#if !defined(AFX_WCSOCKET_H__7679C370_8DAD_4024_BCC7_B5C307A49FD9__INCLUDED_)
#define AFX_WCSOCKET_H__7679C370_8DAD_4024_BCC7_B5C307A49FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WCSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CWCSocket command target

class CWCSocket : public CSocket
{
	typedef struct
	{
		char m_strName[255];
		char m_dbData[255];
		char m_type[255];
		char m_talkingName[255];
	}_DATA;

// Attributes
public:
	_DATA m_Dat;
// Operations
public:
	CWCSocket();
	virtual ~CWCSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWCSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CWCSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WCSOCKET_H__7679C370_8DAD_4024_BCC7_B5C307A49FD9__INCLUDED_)
