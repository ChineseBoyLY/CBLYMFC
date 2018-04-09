; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPasswordDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lab4.h"

ClassCount=4
Class1=CLab4App
Class2=CLab4Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_LAB4_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CPasswordDialog
Resource4=IDD_PASSWORD_DIALOG

[CLS:CLab4App]
Type=0
HeaderFile=lab4.h
ImplementationFile=lab4.cpp
Filter=N

[CLS:CLab4Dlg]
Type=0
HeaderFile=lab4Dlg.h
ImplementationFile=lab4Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CLab4Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=lab4Dlg.h
ImplementationFile=lab4Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LAB4_DIALOG]
Type=1
Class=CLab4Dlg
ControlCount=21
Control1=IDC_BUTTON0,button,1342242816
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_BUTTON3,button,1342242816
Control5=IDC_BUTTON4,button,1342242816
Control6=IDC_BUTTON5,button,1342242816
Control7=IDC_BUTTON6,button,1342242816
Control8=IDC_BUTTON7,button,1342242816
Control9=IDC_BUTTON8,button,1342242816
Control10=IDC_BUTTON9,button,1342242816
Control11=IDC_DISPLAY,edit,1350631552
Control12=IDC_BUTTON_SIGN,button,1342242816
Control13=IDC_BUTTON_POINT,button,1342242816
Control14=IDC_BUTTON_DIV,button,1342242816
Control15=IDC_BUTTON_EQUAL,button,1342242816
Control16=IDC_BUTTON_MULTIPLY,button,1342242816
Control17=IDC_BUTTON_MINUS,button,1342242816
Control18=IDC_BUTTON_ADD,button,1342242816
Control19=IDC_BUTTON_RECIPROCAL,button,1342242816
Control20=IDC_BUTTON_SQRT,button,1342242816
Control21=IDC_BUTTON_CLEAR,button,1342242816

[DLG:IDD_PASSWORD_DIALOG]
Type=1
Class=CPasswordDialog
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PASSWORD_EDIT,edit,1350631584

[CLS:CPasswordDialog]
Type=0
HeaderFile=PasswordDialog.h
ImplementationFile=PasswordDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPasswordDialog

