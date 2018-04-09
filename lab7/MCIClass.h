// MCIClass.h: interface for the CMCIClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCICLASS_H__1F0CE1F0_DC99_11D1_92B0_000021003EA5__INCLUDED_)
#define AFX_MCICLASS_H__1F0CE1F0_DC99_11D1_92B0_000021003EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

#define MAX_RETURN_LENGTH	512

class CMCIClass  
{
protected:
	CString	m_strMediumAlias;//设备别名
	HWND	m_hWndCallback;//回调窗口句柄
	BOOL	m_bMediumOpen;//媒体打开标记

public:
	CMCIClass(HWND hWnd = NULL);
	virtual ~CMCIClass();

	LONG	Open(LPCSTR strMedium, LPCSTR strMediumType, LPCSTR strStyle="", HWND hWnd = NULL);
	LONG	Close();
	LONG	Play(LPCSTR strStyle="", LPCSTR strFlag="");
	LONG	Stop();
	LONG	SetTimeFormat(LPCSTR strTimeFormat="ms");
	LONG	GetLength();
	CString GetTimeFormat();
	LONG	GetPosition(LPSTR strPos);
	LONG	GetStartPosition(LPSTR strPos);
	BOOL	IsMediumOpen();
	BOOL    IsMediumPresent();
	LONG	Execute(LPCSTR strCmd, LPSTR lpstrReturn = NULL, BOOL bShowError = FALSE);
	LONG	Seek(LONG lPos);
};

#endif // !defined(AFX_MCICLASS_H__1F0CE1F0_DC99_11D1_92B0_000021003EA5__INCLUDED_)
