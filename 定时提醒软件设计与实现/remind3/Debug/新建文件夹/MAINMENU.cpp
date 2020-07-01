// MAINMENU.cpp : implementation file
//

#include "stdafx.h"
#include "remind3.h"
#include "MAINMENU.h"
#include "REMINDBOX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMAINMENU

IMPLEMENT_DYNCREATE(CMAINMENU, CFrameWnd)

CMAINMENU::CMAINMENU()
{
}

CMAINMENU::~CMAINMENU()
{
}


BEGIN_MESSAGE_MAP(CMAINMENU, CFrameWnd)
	//{{AFX_MSG_MAP(CMAINMENU)
	ON_COMMAND(ID_SHOWBOX, OnShowbox)
	ON_COMMAND(ID_OPINION, OnOpinion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMAINMENU message handlers

void CMAINMENU::OnShowbox() 
{
	MessageBoxA("aaa","a",0);
	
}

void CMAINMENU::OnOpinion() 
{
	// TODO: Add your command handler code here
	MessageBoxA("aaa","a",0);
}
