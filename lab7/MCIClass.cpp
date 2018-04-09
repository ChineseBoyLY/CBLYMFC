// MCIClass.cpp: implementation of the CMCIClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>
#include "mmsystem.h"

//#include "CLab7Dlg.h"
#include "MCIClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CMCIClass::CMCIClass(HWND hWnd)
{
	m_strMediumAlias = "";
	m_hWndCallback = hWnd;
	m_bMediumOpen = FALSE;
}

CMCIClass::~CMCIClass()
{
	Stop();
	Close();
}

LONG CMCIClass::Open(LPCSTR strMediumName, LPCSTR strMediumType, LPCSTR strStyle, HWND hWnd)
{
	if (IsMediumOpen())
	{
		Stop();
		Close();
	}

	if (hWnd != NULL)
		m_hWndCallback = hWnd;

	CString strMedium = strMediumType;
	CString strCmd = "open ";
	m_strMediumAlias = strMediumType;
	m_strMediumAlias += "_ALIAS";

	strCmd += strMediumName;
	strCmd += " type ";
	strCmd += strMediumType;
	strCmd += " alias ";
	strCmd += m_strMediumAlias;
		
	if (!strMedium.CompareNoCase("AVIVideo"))
	{
		strCmd += " style ";
		strCmd += strStyle;

		CString strHWnd;
		if (m_hWndCallback != NULL)
		{
			strHWnd.Format(" parent %u", m_hWndCallback);
			strCmd += strHWnd;
		}
	}
	
	LONG lRet = Execute(strCmd);

	if (lRet == 0)
		m_bMediumOpen = TRUE;
	
	return lRet;
}

LONG CMCIClass::Close()
{
	m_bMediumOpen = FALSE;

	CString strCmd = "close ";
	strCmd += m_strMediumAlias;

	return Execute(strCmd);
}

LONG CMCIClass::Play(LPCSTR strStyle, LPCSTR strFlag)
{
	CString strCmd = "play ";
	strCmd += m_strMediumAlias;

	CString strStyle0 = strStyle;
	if (!strStyle0.CompareNoCase("fullscreen") || !strStyle0.CompareNoCase("window"))
	{
		CString strPut = "put ";
		strPut += m_strMediumAlias;
		strPut += " source destination";
		Execute(strPut);
		strCmd += strStyle;
	}

	CString s = strFlag;
	if (!s.IsEmpty())
	{
		strCmd += " ";
		strCmd += strFlag;
	}
	return Execute(strCmd);
}

LONG CMCIClass::Stop()
{
	CString strCmd = "stop ";
	strCmd += m_strMediumAlias;
	return Execute(strCmd);
}

LONG CMCIClass::SetTimeFormat(LPCSTR strTimeFormat)
{
	CString strCmd = "set ";
	strCmd += m_strMediumAlias;
	strCmd += " time format ";
	strCmd += strTimeFormat;
	return Execute(strCmd);
}

LONG CMCIClass::GetLength()
{
	CString strCmd = "status ";
	strCmd += m_strMediumAlias;
	strCmd += " length";
	CString strTimeFormat = GetTimeFormat();
	SetTimeFormat("ms");
	char szReturn[MAX_RETURN_LENGTH];
	Execute(strCmd, szReturn);
	SetTimeFormat(strTimeFormat);
	return atol(szReturn);
}


CString  CMCIClass::GetTimeFormat()
{
	CString strCmd = "status ";
	strCmd += m_strMediumAlias;
	strCmd += " time format";
	char szReturn[MAX_RETURN_LENGTH];
	Execute(strCmd, szReturn);
	return CString(szReturn);
}

LONG CMCIClass::GetPosition(LPSTR strPos)
{
	CString strCmd = "status ";
	strCmd += m_strMediumAlias;
	strCmd += " position";

	char szReturn[MAX_RETURN_LENGTH];
	Execute(strCmd, szReturn);

	lstrcpy(strPos, szReturn);

	return atol(szReturn);
}
LONG CMCIClass::GetStartPosition(LPSTR strPos)
{
	CString strCmd = "status ";
	strCmd += m_strMediumAlias;
	strCmd += " start position";

	char szReturn[MAX_RETURN_LENGTH];
	Execute(strCmd, szReturn);

	lstrcpy(strPos, szReturn);

	return atol(szReturn);
}

BOOL CMCIClass::IsMediumOpen()
{
	return m_bMediumOpen;
}

BOOL CMCIClass::IsMediumPresent()
{
	CString strCmd = "status ";
	strCmd += m_strMediumAlias;
	strCmd += " media present";

	char szReturn[MAX_RETURN_LENGTH];
	Execute(strCmd, szReturn);

	if (stricmp(szReturn, "true"))
		return FALSE;
	else
		return TRUE;
}

LONG CMCIClass::Execute(LPCSTR strCmd, LPSTR lpstrReturn, BOOL bShowError)
{
	char szReturn[MAX_RETURN_LENGTH];
	MCIERROR mciError = mciSendString(strCmd,szReturn,sizeof(szReturn),m_hWndCallback);
	lstrcpy(lpstrReturn, szReturn);
	if (bShowError && mciError != 0)
	{
		mciGetErrorString(mciError, szReturn, sizeof(szReturn));
		MessageBox(m_hWndCallback, szReturn, "MCI Error", MB_OK|MB_ICONWARNING);
	}

	return mciError;
}

LONG CMCIClass::Seek(LONG lPos)
{
	CString strPos;
	if (lPos == 0L)
		strPos = " to start";
	else if (lPos == -1L)
		strPos = " to end";
	else
		strPos.Format(" to %ld", lPos);

	CString strCmd = "seek ";
	strCmd += m_strMediumAlias;
	strCmd += strPos;

	return Execute(strCmd);
}
