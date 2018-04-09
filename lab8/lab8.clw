; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLab8View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lab8.h"
LastPage=0

ClassCount=6
Class1=CLab8App
Class2=CLab8Doc
Class3=CLab8View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CLab8Set
Resource7=IDD_LAB8_FORM

[CLS:CLab8App]
Type=0
HeaderFile=lab8.h
ImplementationFile=lab8.cpp
Filter=N

[CLS:CLab8Doc]
Type=0
HeaderFile=lab8Doc.h
ImplementationFile=lab8Doc.cpp
Filter=N

[CLS:CLab8View]
Type=0
HeaderFile=lab8View.h
ImplementationFile=lab8View.cpp
Filter=D
LastObject=IDC_EDIT_ID
BaseClass=CRecordView
VirtualFilter=RVWC


[CLS:CLab8Set]
Type=0
HeaderFile=lab8Set.h
ImplementationFile=lab8Set.cpp
Filter=N

[DB:CLab8Set]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[编号], 12, 510
Column2=[名称], 12, 510
Column3=[演唱], 12, 510
Column4=[作者], 12, 510
Column5=[位置], 12, 510


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_RECORD_FIRST




[CLS:CAboutDlg]
Type=0
HeaderFile=lab8.cpp
ImplementationFile=lab8.cpp
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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_LAB8_FORM]
Type=1
Class=CLab8View
ControlCount=13
Control1=IDC_STATIC,static,1342308353
Control2=IDC_EDIT_ID,edit,1350631552
Control3=IDC_STATIC,static,1342308353
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308353
Control6=IDC_EDIT_SINGER,edit,1350631552
Control7=IDC_STATIC,static,1342308353
Control8=IDC_EDIT_WRITER,edit,1350631552
Control9=IDC_STATIC,static,1342308353
Control10=IDC_EDIT_POSITION,edit,1350631552
Control11=IDC_RECORD_ADD,button,1342242816
Control12=IDC_RECORD_DEL,button,1342242816
Control13=IDC_RECORD_EDIT,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

