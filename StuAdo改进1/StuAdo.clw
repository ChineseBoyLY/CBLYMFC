; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPasswordDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StuAdo.h"

ClassCount=4
Class1=CStuAdoApp
Class2=CStuAdoDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_STUADO_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CPasswordDialog
Resource4=IDR_MENU1
Resource5=IDD_PASSWORD_DIALOG
Resource6=IDR_TOOLBAR1

[CLS:CStuAdoApp]
Type=0
HeaderFile=StuAdo.h
ImplementationFile=StuAdo.cpp
Filter=N

[CLS:CStuAdoDlg]
Type=0
HeaderFile=StuAdoDlg.h
ImplementationFile=StuAdoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_NAME

[CLS:CAboutDlg]
Type=0
HeaderFile=StuAdoDlg.h
ImplementationFile=StuAdoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUADO_DIALOG]
Type=1
Class=CStuAdoDlg
ControlCount=21
Control1=IDC_LISTDATABASE,listbox,1352728833
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ID,edit,1350639744
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NAME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ADDRESS,edit,1350631552
Control8=IDC_ADD,button,1342242816
Control9=IDC_DELETE,button,1342242816
Control10=IDC_MODIFY,button,1342242816
Control11=IDC_LISTALL,button,1342242816
Control12=IDC_EXITSYS,button,1342242816
Control13=IDC_FOLLOW_ID,button,1342242816
Control14=IDC_FOLLOW_NAME,button,1342242816
Control15=IDC_FOLLOW_ADDRESS,button,1342242816
Control16=IDC_STATIC,static,1342177283
Control17=IDC_STATIC,button,1342177287
Control18=IDC_BOY,button,1342308361
Control19=IDC_GIRL,button,1342177289
Control20=IDC_AGE,static,1342308352
Control21=IDC_AGE1,edit,1350631552

[DLG:IDD_PASSWORD_DIALOG]
Type=1
Class=CPasswordDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_USER_EDIT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PWD_EDIT,edit,1350631584

[CLS:CPasswordDialog]
Type=0
HeaderFile=PasswordDialog.h
ImplementationFile=PasswordDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CPasswordDialog
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=CStuAdoDlg
Command1=IDC_ADD
Command2=IDC_DELETE
Command3=IDC_MODIFY
Command4=IDC_EXITSYS
Command5=IDC_FOLLOW_ID
Command6=IDC_FOLLOW_NAME
Command7=IDC_FOLLOW_ADDRESS
Command8=IDC_LISTALL
Command9=ID_PLAY_MUSIC
Command10=ID_STOP_MUSIC
CommandCount=10

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDC_ADD
Command2=IDC_DELETE
Command3=IDC_MODIFY
Command4=IDC_LISTALL
Command5=ID_PLAY_MUSIC
Command6=ID_STOP_MUSIC
CommandCount=6

