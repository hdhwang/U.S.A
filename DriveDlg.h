#pragma once
#include "afxwin.h"


// CDriveDlg ��ȭ �����Դϴ�.

class CDriveDlg : public CDialog
{
	DECLARE_DYNAMIC(CDriveDlg)

public:
	CDriveDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDriveDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox c_SelectDrive;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClicked1();
};
