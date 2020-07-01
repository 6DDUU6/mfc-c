// REMINDBOX.cpp : implementation file
//

#include "stdafx.h"
#include "remind3.h"
#include "REMINDBOX.h"
#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// REMINDBOX dialog


REMINDBOX::REMINDBOX(CWnd* pParent /*=NULL*/)
	: CDialog(REMINDBOX::IDD, pParent)
{
	//{{AFX_DATA_INIT(REMINDBOX)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void REMINDBOX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(REMINDBOX)
	DDX_Control(pDX, IDC_REMINDED, m_reminded);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(REMINDBOX, CDialog)
	//{{AFX_MSG_MAP(REMINDBOX)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// REMINDBOX message handlers

void REMINDBOX::OnDestroy() 
{
	CDialog::OnDestroy();
}

BOOL REMINDBOX::DestroyWindow() 
{
	return CDialog::DestroyWindow();
}


void REMINDBOX::OnClose() 
{
	Public *app = (Public *)AfxGetMainWnd();
	app->p = NULL;
	CDialog::OnClose();
}

BOOL REMINDBOX::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int nWidth = GetSystemMetrics(SM_CXSCREEN);  //ÆÁÄ»¿í¶È    
	int nHeight = GetSystemMetrics(SM_CYSCREEN); //ÆÁÄ»¸ß¶È
	RECT rect;
	GetClientRect(&rect);
	MoveWindow(nWidth-rect.right,nHeight-rect.bottom-80,rect.right,rect.bottom+30);
	::SetWindowPos(this->GetSafeHwnd(),HWND_TOPMOST, 0, 0, 0, 0,SWP_NOSIZE | SWP_NOMOVE);//´°¿ÚÖÃ¶¥
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void REMINDBOX::OnOK() 
{	
	Public *app = (Public *)AfxGetMainWnd();
	app->p = NULL;
	CDialog::OnOK();
}
