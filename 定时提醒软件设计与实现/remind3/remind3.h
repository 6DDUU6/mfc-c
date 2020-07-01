// remind3.h : main header file for the REMIND3 application
//

#if !defined(AFX_REMIND3_H__5B98EF75_3338_4C56_B75E_C2727C517B97__INCLUDED_)
#define AFX_REMIND3_H__5B98EF75_3338_4C56_B75E_C2727C517B97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRemind3App:
// See remind3.cpp for the implementation of this class
//

class CRemind3App : public CWinApp
{
public:
	CRemind3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemind3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRemind3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMIND3_H__5B98EF75_3338_4C56_B75E_C2727C517B97__INCLUDED_)
