
// U.S.A.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CUSAApp:
// �� Ŭ������ ������ ���ؼ��� U.S.A.cpp�� �����Ͻʽÿ�.
//

class CUSAApp : public CWinApp
{
public:
	CUSAApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CUSAApp theApp;