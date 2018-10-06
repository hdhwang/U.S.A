
// U.S.ADlg.cpp : ���� ����
//

#include "stdafx.h"
#include "U.S.A.h"
#include "U.S.ADlg.h"
#include "afxdialogex.h"
#include "DevinfoDlg.h"
#include "DriveDlg.h"
#include "PidSidDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDevinfoDlg dlg;
CDriveDlg dlg2;
PidSidDlg dlg4;

// CUSADlg ��ȭ ����




CUSADlg::CUSADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUSADlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUSADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, image1);
	DDX_Control(pDX, IDC_BUTTON2, image2);
	DDX_Control(pDX, IDC_BUTTON3, image3);
	DDX_Control(pDX, IDC_BUTTON4, image4);
	DDX_Control(pDX, IDC_BUTTON5, UsbWritable);
}

BEGIN_MESSAGE_MAP(CUSADlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CUSADlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUSADlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CUSADlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUSADlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CUSADlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CUSADlg �޽��� ó����

BOOL CUSADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	image1.LoadBitmaps( IDB_BITMAP1, IDB_BITMAP10, NULL, NULL ); //IDB_BITMAP2�� ���ҽ��� �߰��� ��Ʈ�������Դϴ�.
	image1.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.

	image2.LoadBitmaps( IDB_BITMAP6, IDB_BITMAP11, NULL, NULL ); //IDB_BITMAP3�� ���ҽ��� �߰��� ��Ʈ�������Դϴ�.
	image2.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.

	image3.LoadBitmaps( IDB_BITMAP7, IDB_BITMAP12, NULL, NULL ); //IDB_BITMAP4�� ���ҽ��� �߰��� ��Ʈ�������Դϴ�.
	image3.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.

	image4.LoadBitmaps( IDB_BITMAP8, IDB_BITMAP13, NULL, NULL ); //IDB_BITMAP5�� ���ҽ��� �߰��� ��Ʈ�������Դϴ�.
	image4.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.

	UsbWritable.LoadBitmaps( IDB_BITMAP9, IDB_BITMAP14, NULL, NULL ); //IDB_BITMAP2�� ���ҽ��� �߰��� ��Ʈ�������Դϴ�.
	UsbWritable.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CUSADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CUSADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUSADlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int res=dlg2.DoModal();
}


void CUSADlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//int res=dlg3.DoModal();
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isWriteProtected;
    DWORD ReadOnly=1;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("System\\CurrentControlSet\\Control\\StorageDevicePolicies"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("WriteProtect"), NULL , &dwType , (LPBYTE)&isWriteProtected , &dwSize);
    }
    RegKey.Create(HKEY_LOCAL_MACHINE, _T("System\\CurrentControlSet\\Control\\StorageDevicePolicies"));
	RegKey.SetValue(ReadOnly, _T("WriteProtect"));
    RegKey.Close();
	
	
	MessageBox((_T("�̵��ĵ�ũ�� �б��������� �����Ͽ����ϴ�.\n�� ���� ���Ե� �̵��ĵ�ũ�� �� ���� �Ŀ� ����˴ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CUSADlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int res=dlg4.DoModal();
}


void CUSADlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int res=dlg.DoModal();

}


void CUSADlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isWriteProtected;
    DWORD Writable=0;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("System\\CurrentControlSet\\Control\\StorageDevicePolicies"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("WriteProtect"), NULL , &dwType , (LPBYTE)&isWriteProtected , &dwSize);
    }
    RegKey.Create(HKEY_LOCAL_MACHINE, _T("System\\CurrentControlSet\\Control\\StorageDevicePolicies"));
	RegKey.SetValue(Writable, _T("WriteProtect"));
    RegKey.Close();

	MessageBox((_T("�̵��ĵ�ũ�� ���Ⱑ������ �����Ͽ����ϴ�.\n�� ���� ���Ե� �̵��ĵ�ũ�� �� ���� �Ŀ� ����˴ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}
