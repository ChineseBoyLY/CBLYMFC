; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLab6View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lab6.h"
LastPage=0

ClassCount=6
Class1=CLab6App
Class2=CLab6Doc
Class3=CLab6View
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDR_POPUP_MENU
Resource3=IDD_ABOUTBOX
Class6=CPasswordDialog
Resource4=IDD_PASSWORD_DIALOG

[CLS:CLab6App]
Type=0
HeaderFile=lab6.h
ImplementationFile=lab6.cpp
Filter=N

[CLS:CLab6Doc]
Type=0
HeaderFile=lab6Doc.h
ImplementationFile=lab6Doc.cpp
Filter=N
LastObject=CLab6Doc

[CLS:CLab6View]
Type=0
HeaderFile=lab6View.h
ImplementationFile=lab6View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_CIRCLE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=lab6.cpp
ImplementationFile=lab6.cpp
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
Command10=ID_LINE
Command11=ID_RECT
Command12=ID_ELLIRECT
Command13=ID_ELLIPSE
Command14=ID_WIDTH1
Command15=ID_WIDTH2
Command16=ID_WIDTH3
Command17=ID_COLOR
Command18=ID_CLEAR
Command19=ID_FILL
Command20=ID_VIEW_TOOLBAR
Command21=ID_VIEW_STATUS_BAR
Command22=ID_APP_ABOUT
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_CLEAR
Command3=ID_ELLIPSE
Command4=ID_COLOR
Command5=ID_ELLIRECT
Command6=ID_LINE
Command7=ID_FILE_NEW
Command8=ID_FILE_OPEN
Command9=ID_FILE_PRINT
Command10=ID_RECT
Command11=ID_FILE_SAVE
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_UNDO
Command14=ID_EDIT_CUT
Command15=ID_NEXT_PANE
Command16=ID_PREV_PANE
Command17=ID_EDIT_COPY
Command18=ID_EDIT_PASTE
Command19=ID_ACCEL32790
Command20=ID_EDIT_CUT
Command21=ID_EDIT_UNDO
CommandCount=21

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_COLOR
Command2=ID_LINE
Command3=ID_RECT
Command4=ID_ELLIRECT
Command5=ID_ELLIPSE
Command6=ID_CIRCLE
Command7=ID_3dRect
Command8=ID_Chord
Command9=ID_PEN
Command10=ID_WIDTH1
Command11=ID_WIDTH2
Command12=ID_WIDTH3
Command13=ID_FONT
Command14=ID_FILL
Command15=ID_CLEAR
Command16=ID_PLAYMUSIC
Command17=ID_STOPMUSIC
CommandCount=17

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_LINE
Command2=ID_RECT
Command3=ID_ELLIRECT
Command4=ID_ELLIPSE
Command5=ID_CLEAR
CommandCount=5

[DLG:IDD_PASSWORD_DIALOG]
Type=1
Class=CPasswordDialog
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PWD,edit,1350631584

[CLS:CPasswordDialog]
Type=0
HeaderFile=PasswordDialog.h
ImplementationFile=PasswordDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

