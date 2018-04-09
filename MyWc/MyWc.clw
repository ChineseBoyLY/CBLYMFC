; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyWcDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyWc.h"

ClassCount=4
Class1=CMyWcApp
Class2=CMyWcDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CWCSocket
Resource3=IDD_MYWC_DIALOG

[CLS:CMyWcApp]
Type=0
HeaderFile=MyWc.h
ImplementationFile=MyWc.cpp
Filter=N

[CLS:CMyWcDlg]
Type=0
HeaderFile=MyWcDlg.h
ImplementationFile=MyWcDlg.cpp
Filter=D
LastObject=IDC_SEND
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MyWcDlg.h
ImplementationFile=MyWcDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYWC_DIALOG]
Type=1
Class=CMyWcDlg
ControlCount=18
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_TIME,static,1342308352
Control9=IDC_SERVER_NAME,edit,1350631552
Control10=IDC_CLIENT_NAME,edit,1350631552
Control11=IDC_SERVER_PORT,edit,1350631552
Control12=IDC_CONNECT,button,1342242816
Control13=IDC_CLOSE,button,1342242816
Control14=IDC_SEND,button,1342242816
Control15=IDC_LIST_NAME,listbox,1353777409
Control16=IDC_RECEIVED_INFO,listbox,1352728833
Control17=IDC_CHECK1,button,1342242819
Control18=IDC_SEND_INFO,edit,1350631552

[CLS:CWCSocket]
Type=0
HeaderFile=WCSocket.h
ImplementationFile=WCSocket.cpp
BaseClass=CSocket
Filter=N

