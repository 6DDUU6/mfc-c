#if !defined(AFX_REMINDBOX_H__A7DFE212_DC38_43EE_9419_F113EA0688EC__INCLUDED_)
#define AFX_REMINDBOX_H__A7DFE212_DC38_43EE_9419_F113EA0688EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// REMINDBOX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// REMINDBOX dialog

class REMINDBOX : public CDialog
{
// Construction
public:
	REMINDBOX(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(REMINDBOX)
	enum { IDD = IDD_REMINDBOX_DIALOG };
	CEdit	m_reminded;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(REMINDBOX)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(REMINDBOX)
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMINDBOX_H__A7DFE212_DC38_43EE_9419_F113EA0688EC__INCLUDED_)
