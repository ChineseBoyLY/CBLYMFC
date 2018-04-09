; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLab2View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lab2.h"
LastPage=0

ClassCount=5
Class1=CLab2App
Class2=CLab2Doc
Class3=CLab2View
Class4=CMainFrame

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource7=IDD_LAB2_FORM

[CLS:CLab2App]
Type=0
HeaderFile=lab2.h
ImplementationFile=lab2.cpp
Filter=N

[CLS:CLab2Doc]
Type=0
HeaderFile=lab2Doc.h
ImplementationFile=lab2Doc.cpp
Filter=N

[CLS:CLab2View]
Type=0
HeaderFile=lab2View.h
ImplementationFile=lab2View.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_TIME


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_TIME_CURRENT




[CLS:CAboutDlg]
Type=0
HeaderFile=lab2.cpp
ImplementationFile=lab2.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_TIME_START
Command18=ID_TIME_STOP
Command19=ID_TIME_CURRENT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_LAB2_FORM]
Type=1
Class=CLab2View
ControlCount=2
Control1=IDC_STATIC,static,1342308864
Control2=IDC_TIME,edit,1350633600

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_TIME_START
Command10=ID_TIME_STOP
Command11=ID_TIME_CURRENT
CommandCount=11

