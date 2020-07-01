// remind3Dlg.h : header file
//

#if !defined(AFX_REMIND3DLG_H__C139670B_5CCF_441C_B757_1F4B74F37239__INCLUDED_)
#define AFX_REMIND3DLG_H__C139670B_5CCF_441C_B757_1F4B74F37239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRemind3Dlg dialog

class CRemind3Dlg : public CDialog
{
// Construction
public:
	CRemind3Dlg(CWnd* pParent = NULL);	// standard constructor
	LRESULT OnShowTask( WPARAM wParam,LPARAM lParam );
	void ShowTray(bool bShow);
	void init_list();
	//void insertnew(CString s1,CString s2);
// Dialog Data
	//{{AFX_DATA(CRemind3Dlg)
	enum { IDD = IDD_REMIND3_DIALOG };
	CEdit	m_s2;
	CEdit	m_s1;
	CEdit	m_content;
	CSpinButtonCtrl	m_ssecond;
	CEdit	m_second;
	CEdit	m_day;
	CEdit	m_hour;
	CEdit	m_minute;
	CEdit	m_month;
	CSpinButtonCtrl	m_sday;
	CSpinButtonCtrl	m_shour;
	CSpinButtonCtrl	m_sminute;
	CSpinButtonCtrl	m_smonth;
	CSpinButtonCtrl	m_syear;
	CEdit	m_year;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemind3Dlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRemind3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAdd();
	afx_msg void OnDestroy();
	afx_msg void OnReset();
	afx_msg void OnShowbox();
	afx_msg void OnButtonSearch1();
	afx_msg void OnButtonSearch2();
	afx_msg void OnRclickMainlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExit();
	afx_msg void OnDelete();
	afx_msg void OnMin();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMIND3DLG_H__C139670B_5CCF_441C_B757_1F4B74F37239__INCLUDED_)
