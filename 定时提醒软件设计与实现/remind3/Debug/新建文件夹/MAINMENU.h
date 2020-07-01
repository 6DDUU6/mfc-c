#if !defined(AFX_MAINMENU_H__E363F996_F771_4174_B941_1FEBE2CAA43B__INCLUDED_)
#define AFX_MAINMENU_H__E363F996_F771_4174_B941_1FEBE2CAA43B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MAINMENU.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMAINMENU frame

class CMAINMENU : public CFrameWnd
{
	DECLARE_DYNCREATE(CMAINMENU)
protected:
	CMAINMENU();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMAINMENU)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMAINMENU();

	// Generated message map functions
	//{{AFX_MSG(CMAINMENU)
	afx_msg void OnShowbox();
	afx_msg void OnOpinion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINMENU_H__E363F996_F771_4174_B941_1FEBE2CAA43B__INCLUDED_)
