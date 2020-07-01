// MusicPlayerDlg.h : header file
//
#include "bass.h"

#if !defined(AFX_MUSICPLAYERDLG_H__9BDE9F04_C59C_48F0_97F5_D2CEA538B6E7__INCLUDED_)
#define AFX_MUSICPLAYERDLG_H__9BDE9F04_C59C_48F0_97F5_D2CEA538B6E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMusicPlayerDlg dialog

class CMusicPlayerDlg : public CDialog
{
// Construction
public:
	void OnTimer(UINT_PTR nIDEvent);
	HSTREAM m_py;
	void refresh();
	CMusicPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMusicPlayerDlg)
	enum { IDD = IDD_MUSICPLAYER_DIALOG };
	CStatic	m_span;
	CEdit	m_edit;
	CButton	m_next;
	CButton	m_add;
	CButton	m_del;
	CButton	m_down;
	CButton	m_up;
	CButton	m_play;
	CButton	m_pause;
	CButton	m_getfile;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMusicPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMusicPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddmusic();
	afx_msg void OnGetfile();
	afx_msg void OnDelmusic();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnNextmusic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUSICPLAYERDLG_H__9BDE9F04_C59C_48F0_97F5_D2CEA538B6E7__INCLUDED_)
