// Public.h: interface for the Public class.
//
//////////////////////////////////////////////////////////////////////
#include "sqlite3.h"
#include "REMINDBOX.h"
#if !defined(AFX_PUBLIC_H__F615A0E2_12EF_4B36_A2E5_0BBC55873A9C__INCLUDED_)
#define AFX_PUBLIC_H__F615A0E2_12EF_4B36_A2E5_0BBC55873A9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Public  
{
public:
	sqlite3 *conn;
	REMINDBOX *p;
	Public();
	virtual ~Public();
};

#endif // !defined(AFX_PUBLIC_H__F615A0E2_12EF_4B36_A2E5_0BBC55873A9C__INCLUDED_)
