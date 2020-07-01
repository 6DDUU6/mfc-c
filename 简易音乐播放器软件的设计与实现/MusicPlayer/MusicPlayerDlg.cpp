// MusicPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MusicPlayer.h"
#include "MusicPlayerDlg.h"
#include "bass.h"
#include <string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CMusicPlayerDlg dialog

CMusicPlayerDlg::CMusicPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMusicPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMusicPlayerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMusicPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMusicPlayerDlg)
	DDX_Control(pDX, IDC_SPAN, m_span);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_NEXTMUSIC, m_next);
	DDX_Control(pDX, IDC_ADDMUSIC, m_add);
	DDX_Control(pDX, IDC_DELMUSIC, m_del);
	DDX_Control(pDX, IDC_DOWN, m_down);
	DDX_Control(pDX, IDC_UP, m_up);
	DDX_Control(pDX, IDC_PLAY, m_play);
	DDX_Control(pDX, IDC_PAUSE, m_pause);
	DDX_Control(pDX, IDC_GETFILE, m_getfile);
	DDX_Control(pDX, IDC_MAINLIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMusicPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CMusicPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDMUSIC, OnAddmusic)
	ON_BN_CLICKED(IDC_GETFILE, OnGetfile)
	ON_BN_CLICKED(IDC_DELMUSIC, OnDelmusic)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_NEXTMUSIC, OnNextmusic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMusicPlayerDlg message handlers

BOOL CMusicPlayerDlg::OnInitDialog()
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
	BASS_Init(-1,44100,0,this->m_hWnd,NULL);
	BASS_SetVolume(100);
	m_py = NULL;

	m_list.SetExtendedStyle(LVS_EX_HEADERDRAGDROP | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_list.InsertColumn(0,"id",LVCFMT_LEFT,30);
	m_list.InsertColumn(1,"音乐路径",LVCFMT_LEFT,100);
	m_list.InsertColumn(2,"音乐名称",LVCFMT_LEFT,250);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMusicPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMusicPlayerDlg::OnPaint() 
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
HCURSOR CMusicPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

string getfilename(string path)
{
	int pos = path.find_last_of('\\');
	return path.substr(pos+1);
}
void CMusicPlayerDlg::OnAddmusic() 
{
	UpdateData();
	CString tmp;
	string tmp2;
	m_edit.GetWindowText(tmp);
	if(tmp=="")
	{
		MessageBoxA("请选择一首歌曲用来插入列表","提示",0);
		return;
	}
	char a[1000];
	int newid = m_list.GetItemCount();
	sprintf(a,"%d",newid+1);
	m_list.InsertItem(newid, a);
	m_list.SetItemText(newid,1,tmp);
	tmp2 = getfilename(tmp.GetBuffer(0));
	tmp = tmp2.c_str();
	m_list.SetItemText(newid,2,tmp);
}

void CMusicPlayerDlg::OnGetfile() 
{
	char szFileFilter[] = "mp3文件(*.mp3)|*.mp3|"
		"wma文件(*.wma)|*.wma|"
		"wav文件(*.wav)|*.wav|"
		"所有文件(*.*)|*.*|";//文件类型过滤    
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY, szFileFilter);
	if (dlg.DoModal() == IDOK)
	{
		CString strFilepath = dlg.GetPathName();
		SetDlgItemText(IDC_EDIT1,strFilepath);
	}
}

void CMusicPlayerDlg::OnDelmusic() 
{
	int nItem = m_list.GetSelectionMark();
	if(nItem<0)
	{
		MessageBoxA("未选择一首歌曲","提示",0);
		return;
	}
	m_list.DeleteItem(nItem);
	refresh();
}

void CMusicPlayerDlg::OnUp() 
{
	UpdateData();
	int nItem = m_list.GetSelectionMark();
	if(nItem<0)
	{
		MessageBoxA("未选择一首歌曲","提示",0);
		return;
	}
	if(nItem == 0)
	{
		MessageBoxA("不能再往上移动了","提示",0);
		return;
	}
	CString tmp1;
	CString tmp2;
	CString tmp3;
	CString tmp4;
	tmp1 = m_list.GetItemText(nItem,1);
	tmp3 = m_list.GetItemText(nItem,2);
	tmp2 = m_list.GetItemText(nItem-1,1);
	tmp4 = m_list.GetItemText(nItem-1,2);
	m_list.SetItemText(nItem-1,1,tmp1);
	m_list.SetItemText(nItem-1,2,tmp3);
	m_list.SetItemText(nItem,1,tmp2);
	m_list.SetItemText(nItem,2,tmp4);
	m_list.SetFocus();
	m_list.SetItemState(nItem-1,LVNI_FOCUSED | LVNI_SELECTED, LVNI_FOCUSED | LVNI_SELECTED); 
	m_list.SetSelectionMark(nItem-1);
}

void CMusicPlayerDlg::OnDown() 
{
	int nItem = m_list.GetSelectionMark();
	if(nItem<0)
	{
		MessageBoxA("未选择一首歌曲","提示",0);
		return;
	}
	if(nItem == m_list.GetItemCount()-1)
	{
		MessageBoxA("不能再往下移动了","提示",0);
		return;
	}
	CString tmp1;
	CString tmp2;
	CString tmp3;
	CString tmp4;
	tmp1 = m_list.GetItemText(nItem,1);
	tmp3 = m_list.GetItemText(nItem,2);
	tmp2 = m_list.GetItemText(nItem+1,1);
	tmp4 = m_list.GetItemText(nItem+1,2);
	m_list.SetItemText(nItem+1,1,tmp1);
	m_list.SetItemText(nItem+1,2,tmp3);
	m_list.SetItemText(nItem,1,tmp2);
	m_list.SetItemText(nItem,2,tmp4);
	m_list.SetFocus();
	m_list.SetItemState(nItem+1,LVNI_FOCUSED | LVNI_SELECTED, LVNI_FOCUSED | LVNI_SELECTED); 
	m_list.SetSelectionMark(nItem+1);
}

void CMusicPlayerDlg::refresh()
{
	char a[1000];
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		sprintf(a,"%d",i+1);
		m_list.SetItemText(i,0,a);
	}
}

void CMusicPlayerDlg::OnPlay() 
{
	if(m_py != NULL)
	{
		BASS_ChannelPlay(m_py,FALSE);
		CString tmp;
		m_span.GetWindowText(tmp);
		tmp.Replace("暂停","正在播放");
		m_span.SetWindowText(tmp);
		return;
	}

	if(m_list.GetItemCount() == 0)
	{
		MessageBoxA("列表歌曲为空","提示",0);
		return;
	}

	m_py=BASS_StreamCreateFile(FALSE,m_list.GetItemText(0,1),0,0,BASS_SAMPLE_MONO);
    BASS_ChannelPlay(m_py,FALSE);
	m_span.SetWindowText("当前正在播放："+m_list.GetItemText(0,2));
	m_list.DeleteItem(0);
	refresh();

	KillTimer(1);
    SetTimer(1,1000,NULL);
}

void CMusicPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (BASS_ChannelBytes2Seconds(m_py, BASS_ChannelGetPosition(m_py, BASS_POS_BYTE)) == BASS_ChannelBytes2Seconds(m_py, BASS_ChannelGetLength(m_py, BASS_POS_BYTE)))
	{
		BASS_StreamFree(m_py);
		m_py = NULL;
		if(m_list.GetItemCount() != 0)
		{
			OnPlay();
		}
	}
}

void CMusicPlayerDlg::OnPause() 
{
	BASS_ChannelPause(m_py);
	CString tmp;
	m_span.GetWindowText(tmp);
	tmp.Replace("正在播放","暂停");
	m_span.SetWindowText(tmp);
}

void CMusicPlayerDlg::OnNextmusic() 
{
	if(m_py != NULL)
	{
		BASS_StreamFree(m_py);
		m_py = NULL;
	}
	OnPlay();
}
