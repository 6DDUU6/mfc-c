// remind3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "remind3.h"
#include "remind3Dlg.h"
#include "Public.h"
#include "sqlite3.h"
#include "REMINDBOX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//===================================================================
 
#define WM_SHOWTASK (WM_USER +1)
 
void CRemind3Dlg::ShowTray(bool bShow)
{
	NOTIFYICONDATA nid;
	nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);  
	nid.hWnd=this->m_hWnd;  
	nid.uID=IDR_MAINFRAME;    //托盘图标的id
	nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;  
	nid.uCallbackMessage=WM_SHOWTASK;//自定义的回调消息名称id
	nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));    //设置图标
	strcpy(nid.szTip,_T("定时提醒"));//信息提示条
	Shell_NotifyIcon(bShow?NIM_ADD:NIM_DELETE,&nid);//在托盘区添加图标
}
 
 
//托盘图标的所有处理事件都转到这里
LRESULT CRemind3Dlg::OnShowTask( WPARAM wParam,LPARAM lParam )
{
	//w参数 代表id ， L参数代表消息id
	if(wParam!=IDR_MAINFRAME)return 1;
	switch(lParam)
	{
	case WM_LBUTTONUP:  //左键单击显示主界面
		ShowWindow(SW_SHOW);
		ShowTray(0);
		break;
	case WM_RBUTTONUP:  //右击弹出菜单		
		break;
	case WM_LBUTTONDBLCLK:  //左键双击不处理
		break;
	default:
		break;
	}
}

//==================================================================================

void timeproc()
{
	sqlite3_stmt * stmt;//创建记录集指针
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	sqlite3_prepare(conn,"select * from task_list where time=datetime('now','localtime');",-1,&stmt,0);
	int rc = sqlite3_step(stmt);
	while(rc == SQLITE_ROW)
	{
		CString time = sqlite3_column_text(stmt,1);
		CString msg = sqlite3_column_text(stmt,2);
		if(app->p == NULL)
		{
			REMINDBOX *p = new REMINDBOX;
			p->Create(IDD_REMINDBOX_DIALOG);
			p->ShowWindow(SW_NORMAL);
			app->p = p;
			p->m_reminded.SetWindowText(time+"\r\n"+msg+"\r\n\r\n");
		}else
		{
			REMINDBOX *p = app->p;
			CString tmp;
			p->m_reminded.GetWindowText(tmp);
			p->m_reminded.SetWindowText(tmp+time+"\r\n"+msg+"\r\n\r\n");
		}
		rc=sqlite3_step(stmt);//下一记录
	}
	sqlite3_finalize(stmt);//关闭记录集
	return;
}

void Insert2db(CString str1,CString str2)
{
	char *err_msg = NULL;
	char sql[1000] = "";//最大1000个字符
	char err[1000];
	sprintf(sql, "insert into task_list(time,msg) values('%s','%s')",str1,str2);
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	if (sqlite3_exec (conn, sql, NULL, NULL, &err_msg) != SQLITE_OK)  
    {
		sprintf(err,"插入数据失败！错误信息：%s",err_msg);
		MessageBoxA(NULL,err,"提示",0);
    }
}

CString changestr(CString str)
{
	CString tmp;
	tmp = str;
	if(strlen(tmp) == 1)
	{
		tmp = "0" + tmp;
	}
	return tmp;
}


void CRemind3Dlg::init_list()
{
	int newid;
	sqlite3_stmt * stmt;
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	sqlite3_prepare(conn,"select * from task_list where time>datetime('now','localtime');",-1,&stmt,0);//筛选出时间大于现在的记录。
	int rc = sqlite3_step(stmt);
	while( rc == SQLITE_ROW )
	{
		CString time = sqlite3_column_text(stmt,1);
		CString msg = sqlite3_column_text(stmt,2);
		newid = m_list.InsertItem(NULL,time);
		m_list.SetItemText(newid,1,msg);
		rc=sqlite3_step(stmt);
	}
	sqlite3_finalize(stmt);
}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemind3Dlg dialog

CRemind3Dlg::CRemind3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemind3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRemind3Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemind3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemind3Dlg)
	DDX_Control(pDX, IDC_SEARCH2ED, m_s2);
	DDX_Control(pDX, IDC_SEARCH1ED, m_s1);
	DDX_Control(pDX, IDC_CONTENT, m_content);
	DDX_Control(pDX, IDC_SPIN_SECOND, m_ssecond);
	DDX_Control(pDX, IDC_EDIT_SECOND, m_second);
	DDX_Control(pDX, IDC_EDIT_DAY, m_day);
	DDX_Control(pDX, IDC_EDIT_HOUR, m_hour);
	DDX_Control(pDX, IDC_EDIT_MINUTE, m_minute);
	DDX_Control(pDX, IDC_EDIT_MONTH, m_month);
	DDX_Control(pDX, IDC_SPIN_DAY, m_sday);
	DDX_Control(pDX, IDC_SPIN_HOUR, m_shour);
	DDX_Control(pDX, IDC_SPIN_MINUTE, m_sminute);
	DDX_Control(pDX, IDC_SPIN_MONTH, m_smonth);
	DDX_Control(pDX, IDC_SPIN_YEAR, m_syear);
	DDX_Control(pDX, IDC_EDIT_YEAR, m_year);
	DDX_Control(pDX, IDC_MAINLIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRemind3Dlg, CDialog)
	//{{AFX_MSG_MAP(CRemind3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_COMMAND(ID_SHOWBOX, OnShowbox)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH1, OnButtonSearch1)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH2, OnButtonSearch2)
	ON_NOTIFY(NM_RCLICK, IDC_MAINLIST, OnRclickMainlist)
	ON_COMMAND(ID_EXIT, OnExit)
	ON_COMMAND(ID_DELETE, OnDelete)
	ON_COMMAND(ID_MIN, OnMin)
	ON_MESSAGE(WM_SHOWTASK,OnShowTask)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemind3Dlg message handlers

BOOL CRemind3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	Public *app = (Public *)AfxGetMainWnd();
	SetTimer(1,1000,(TIMERPROC)timeproc);

	m_list.SetExtendedStyle(LVS_EX_HEADERDRAGDROP | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );//显示网格线

	m_list.InsertColumn(0,"时间",LVCFMT_LEFT,150);
	m_list.InsertColumn(1,"提醒内容",LVCFMT_LEFT,400);

	CTime tm;
    tm=CTime::GetCurrentTime();
	m_year.SetWindowText(tm.Format("%Y"));
	m_month.SetWindowText(tm.Format("%m"));
	m_day.SetWindowText(tm.Format("%d"));
	m_hour.SetWindowText(tm.Format("%H"));
	m_minute.SetWindowText(tm.Format("%M"));
	m_second.SetWindowText("00");
	m_syear.SetRange(0,9999);
	m_smonth.SetRange(1,12);
	m_sday.SetRange(1,31);
	m_shour.SetRange(0,23);
	m_sminute.SetRange(0,59);
	m_ssecond.SetRange(0,59);
	
	m_content.SetWindowText("新内容");
	
	sqlite3 *conn;
	if (sqlite3_open("data.db", &conn) != SQLITE_OK)//创建或打开sqlite3数据库
	{
		MessageBoxA("打开或创建数据库失败！","提示",0);
	}
	sqlite3_exec (conn, "create table task_list(id INTEGER PRIMARY KEY AUTOINCREMENT,time timestamp,msg text)", NULL, NULL, NULL);
	app->conn = conn;

	init_list();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRemind3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRemind3Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRemind3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRemind3Dlg::OnButtonAdd() 
{
	UpdateData();
	int newid;
	CString str,tmp;
	str="";
	m_year.GetWindowText(tmp);
	str=str+tmp;
	m_month.GetWindowText(tmp);
	str=str+"-"+changestr(tmp);
	m_day.GetWindowText(tmp);
	str=str+"-"+changestr(tmp);
	m_hour.GetWindowText(tmp);
	str=str+" "+changestr(tmp);
	m_minute.GetWindowText(tmp);
	str=str+":"+changestr(tmp);
	m_second.GetWindowText(tmp);
	str=str+":"+changestr(tmp);
	newid = m_list.InsertItem(NULL, str);
	m_content.GetWindowText(tmp);
	m_list.SetItemText(newid,1,tmp);
	Insert2db(str,tmp);
}



void CRemind3Dlg::OnDestroy() 
{
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	if (sqlite3_close(conn) != SQLITE_OK)//退出程序时关闭数据库
    {
		MessageBoxA("非正常退出！无法关闭数据库！","提示",0);
    }
	app->conn = NULL;
	CDialog::OnDestroy();//退出
}


BOOL CRemind3Dlg::DestroyWindow() 
{
	return CDialog::DestroyWindow();
}


void CRemind3Dlg::OnReset() 
{
	m_list.DeleteAllItems();
	init_list();	
}

void CRemind3Dlg::OnShowbox()
{
	Public *app = (Public *)AfxGetMainWnd();
	REMINDBOX *p = new REMINDBOX;
	p->Create(IDD_REMINDBOX_DIALOG);
	p->ShowWindow(SW_NORMAL);
	app->p = p;
}

void CRemind3Dlg::OnButtonSearch1() 
{
	m_list.DeleteAllItems();
	int newid;
	CString tmp;
	sqlite3_stmt * stmt;
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	m_s1.GetWindowText(tmp);
	sqlite3_prepare(conn,"select * from task_list where time like '%"+tmp+"%';",-1,&stmt,0);//模糊筛选出时间记录
	int rc = sqlite3_step(stmt);
	while( rc == SQLITE_ROW )
	{
		CString time = sqlite3_column_text(stmt,1);
		CString msg = sqlite3_column_text(stmt,2);
		newid = m_list.InsertItem(NULL,time);
		m_list.SetItemText(newid,1,msg);
		rc=sqlite3_step(stmt);
	}
	sqlite3_finalize(stmt);
}

void CRemind3Dlg::OnButtonSearch2() 
{
	m_list.DeleteAllItems();
	int newid;
	CString tmp;
	sqlite3_stmt * stmt;
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	m_s2.GetWindowText(tmp);
	sqlite3_prepare(conn,"select * from task_list where msg like '%"+tmp+"%';",-1,&stmt,0);//模糊筛选出内容记录
	int rc = sqlite3_step(stmt);
	while( rc == SQLITE_ROW )
	{
		CString time = sqlite3_column_text(stmt,1);
		CString msg = sqlite3_column_text(stmt,2);
		newid = m_list.InsertItem(NULL,time);
		m_list.SetItemText(newid,1,msg);
		rc=sqlite3_step(stmt);
	}
	sqlite3_finalize(stmt);
}

void CRemind3Dlg::OnRclickMainlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMenu menu,*pSubMenu;//定义下面要用到的cmenu对象  
	menu.LoadMenu(IDR_MENU2);//装载自定义的右键菜单  
	pSubMenu=menu.GetSubMenu(0);//获取第一个弹出菜单，所以第一个菜单必须有子菜单  
    CPoint oPoint;//定义一个用于确定光标位置的位置  
	GetCursorPos(&oPoint);//获取当前光标的位置，以便使得菜单可以跟随光标  
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,oPoint.x,oPoint.y,this);  //在指定位置显示弹出菜单
	*pResult = 0;
}

void CRemind3Dlg::OnExit() 
{
	exit(0);
}

void CRemind3Dlg::OnDelete() 
{
	Public *app = (Public *)AfxGetMainWnd();
	sqlite3 *conn = app->conn;
	CString tmp1;
	CString tmp2;
	int nItem;
	nItem = m_list.GetSelectionMark();
	tmp1 = m_list.GetItemText(nItem,0);
	tmp2 = m_list.GetItemText(nItem,1);
	char *err_msg = NULL;
	char err[1000];
	if (sqlite3_exec (conn, "delete from task_list where time='"+tmp1+"' and msg='"+tmp2+"';", NULL, NULL, &err_msg) != SQLITE_OK)  
    {
		sprintf(err,"删除数据失败！错误信息：%s",err_msg);
		MessageBoxA(err,"提示",0);
    }
	m_list.DeleteAllItems();
	init_list();
}

void CRemind3Dlg::OnMin() 
{
	ShowWindow(SW_HIDE);
	ShowTray(1);
}

void CRemind3Dlg::OnClose() 
{
	int tmp;

	tmp = MessageBoxA("是否要退出程序？\r\n点否最小化到托盘","提示",MB_YESNOCANCEL);
	if(tmp == IDYES)
	{
		CDialog::OnClose();
	}else if (tmp == IDNO)
	{
		OnMin();
	}
}
