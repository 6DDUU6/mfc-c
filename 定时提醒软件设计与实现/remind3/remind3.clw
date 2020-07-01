; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=REMINDBOX
LastTemplate=CFrameWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "remind3.h"

ClassCount=4
Class1=CRemind3App
Class2=CRemind3Dlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_REMINDBOX_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_REMIND3_DIALOG
Resource4=IDR_MENU1
Class4=REMINDBOX
Resource5=IDD_ABOUTBOX
Resource6=IDR_MENU2

[CLS:CRemind3App]
Type=0
HeaderFile=remind3.h
ImplementationFile=remind3.cpp
Filter=N
LastObject=CRemind3App

[CLS:CRemind3Dlg]
Type=0
HeaderFile=remind3Dlg.h
ImplementationFile=remind3Dlg.cpp
Filter=D
LastObject=ID_MIN
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=remind3Dlg.h
ImplementationFile=remind3Dlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_REMIND3_DIALOG]
Type=1
Class=CRemind3Dlg
ControlCount=31
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_MAINLIST,SysListView32,1350631445
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SEARCH1ED,edit,1350631552
Control7=IDC_BUTTON_SEARCH1,button,1342242816
Control8=IDC_SEARCH2ED,edit,1350631552
Control9=IDC_BUTTON_SEARCH2,button,1342242816
Control10=IDC_RESET,button,1342242816
Control11=IDC_EDIT_YEAR,edit,1350639745
Control12=IDC_SPIN_YEAR,msctls_updown32,1342177462
Control13=IDC_EDIT_MONTH,edit,1350639745
Control14=IDC_SPIN_MONTH,msctls_updown32,1342177334
Control15=IDC_EDIT_DAY,edit,1350639745
Control16=IDC_SPIN_DAY,msctls_updown32,1342177334
Control17=IDC_EDIT_HOUR,edit,1350639745
Control18=IDC_SPIN_HOUR,msctls_updown32,1342177334
Control19=IDC_EDIT_MINUTE,edit,1350639745
Control20=IDC_SPIN_MINUTE,msctls_updown32,1342177334
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_CONTENT,edit,1352732676
Control28=IDC_BUTTON_ADD,button,1342242816
Control29=IDC_EDIT_SECOND,edit,1350639745
Control30=IDC_SPIN_SECOND,msctls_updown32,1342177334
Control31=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_SHOWBOX
Command2=ID_MIN
Command3=ID_EXIT
CommandCount=3

[DLG:IDD_REMINDBOX_DIALOG]
Type=1
Class=REMINDBOX
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_REMINDED,edit,1352732676

[CLS:REMINDBOX]
Type=0
HeaderFile=REMINDBOX.h
ImplementationFile=REMINDBOX.cpp
BaseClass=CDialog
Filter=D
LastObject=REMINDBOX
VirtualFilter=dWC

[MNU:IDR_MENU2]
Type=1
Class=?
Command1=ID_DELETE
CommandCount=1

