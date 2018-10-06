
// U.S.ADlg.cpp : 구현 파일
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

// CUSADlg 대화 상자




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


// CUSADlg 메시지 처리기

BOOL CUSADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	image1.LoadBitmaps( IDB_BITMAP1, IDB_BITMAP10, NULL, NULL ); //IDB_BITMAP2은 리소스에 추가한 비트맵파일입니다.
	image1.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.

	image2.LoadBitmaps( IDB_BITMAP6, IDB_BITMAP11, NULL, NULL ); //IDB_BITMAP3은 리소스에 추가한 비트맵파일입니다.
	image2.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.

	image3.LoadBitmaps( IDB_BITMAP7, IDB_BITMAP12, NULL, NULL ); //IDB_BITMAP4은 리소스에 추가한 비트맵파일입니다.
	image3.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.

	image4.LoadBitmaps( IDB_BITMAP8, IDB_BITMAP13, NULL, NULL ); //IDB_BITMAP5은 리소스에 추가한 비트맵파일입니다.
	image4.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.

	UsbWritable.LoadBitmaps( IDB_BITMAP9, IDB_BITMAP14, NULL, NULL ); //IDB_BITMAP2은 리소스에 추가한 비트맵파일입니다.
	UsbWritable.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CUSADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CUSADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUSADlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int res=dlg2.DoModal();
}


void CUSADlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	
	
	MessageBox((_T("이동식디스크를 읽기전용으로 변경하였습니다.\n※ 현재 삽입된 이동식디스크는 재 연결 후에 적용됩니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CUSADlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int res=dlg4.DoModal();
}


void CUSADlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int res=dlg.DoModal();

}


void CUSADlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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

	MessageBox((_T("이동식디스크를 쓰기가능으로 변경하였습니다.\n※ 현재 삽입된 이동식디스크는 재 연결 후에 적용됩니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}
