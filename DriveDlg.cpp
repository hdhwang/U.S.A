// DriveDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "U.S.A.h"
#include "DriveDlg.h"
#include "afxdialogex.h"
CString seldrive=_T("empty");

// CDriveDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDriveDlg, CDialog)

CDriveDlg::CDriveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriveDlg::IDD, pParent)
{

}

CDriveDlg::~CDriveDlg()
{
}

void CDriveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, c_SelectDrive);
 
	CString strDrive;    // ���� ����̺�� �ӽ� ����
	TCHAR pTmp[256];
	memset(pTmp, '\0', 256);
	GetLogicalDriveStrings(256, pTmp);
	
	for(int i=0 ; i<256 ; i++) {
		if(pTmp[i] == '\0' && pTmp[i+1] == '\0')
		break;
		
		strDrive.Empty();
		
		while(pTmp[i] != '\0')
			strDrive += pTmp[i++];
		
		if(GetDriveType(strDrive) == DRIVE_REMOVABLE || GetDriveType(strDrive) == DRIVE_FIXED) {
			c_SelectDrive.AddString(strDrive);
			if(strcmp((LPSTR)(LPCTSTR)seldrive,"empty")==0){
				seldrive = strDrive;
			}
		}
	}
	c_SelectDrive.SetCurSel(0);


}


BEGIN_MESSAGE_MAP(CDriveDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDriveDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(1, &CDriveDlg::OnBnClicked1)
END_MESSAGE_MAP()


// CDriveDlg �޽��� ó�����Դϴ�.


void CDriveDlg::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int curSel=c_SelectDrive.GetCurSel();
	//�޺� �ڽ��� �ش� �ε��� ��ġ�� �׸� ���� ���´�.
	c_SelectDrive.GetLBText(curSel, seldrive);
	


}


void CDriveDlg::OnBnClicked1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char* pszBuffer = "Anti Autorun Virus Success!!         - Created by U.S.A";
	CFile File(seldrive+_T("autorun.inf"),
	CFile::modeCreate |  CFile::modeReadWrite);
	File.Write(pszBuffer, strlen(pszBuffer));
	File.Close();

	CFileStatus status;
	CFile::GetStatus(seldrive+_T("autorun.inf"), status);    // ���� ������ ���°��� �����ɴϴ�.
	status.m_attribute =CFile::readOnly | CFile::hidden | CFile::system;// �Ӽ��� �����մϴ�.
	CFile::SetStatus(seldrive+_T("autorun.inf"), status);    // ���Ͽ� ���°��� �����մϴ�.

	//icacls�� �̿��Ͽ� ��� ����ڿ��� autorun.inf ���� ���� ������ �б�� ���� (NTFS ���Ͻý��ۿ����� ����)
	CString icaclsParm = seldrive + _T("autorun.inf /deny Everyone:RX");
	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei, sizeof(SHELLEXECUTEINFO));
	sei.cbSize = sizeof(SHELLEXECUTEINFO);
	sei.lpFile = __TEXT("icacls");
	sei.lpParameters = icaclsParm;
	sei.nShow = SW_HIDE;
	sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	sei.lpVerb = _T("Open");
	ShellExecuteEx(&sei);
	WaitForSingleObject(sei.hProcess, INFINITE);



	MessageBox(seldrive+(_T("�� Autorun Virus�κ��� �����մϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
	CDialog::OnOK();
	
}
