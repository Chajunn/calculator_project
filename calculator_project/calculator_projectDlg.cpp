
// calculator_projectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "calculator_project.h"
#include "calculator_projectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorprojectDlg 대화 상자



CcalculatorprojectDlg::CcalculatorprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_PROJECT_DIALOG, pParent)
	, m_Finish(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Finish);
}

BEGIN_MESSAGE_MAP(CcalculatorprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculatorprojectDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorprojectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorprojectDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalculatorprojectDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MIN, &CcalculatorprojectDlg::OnBnClickedButtonMin)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CcalculatorprojectDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CcalculatorprojectDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_END, &CcalculatorprojectDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CcalculatorprojectDlg::OnBnClickedButtonReset)
	ON_EN_CHANGE(IDC_EDIT1, &CcalculatorprojectDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CcalculatorprojectDlg 메시지 처리기

BOOL CcalculatorprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CcalculatorprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CcalculatorprojectDlg::OnPaint()
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
HCURSOR CcalculatorprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

enum Math {
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE
};


void CcalculatorprojectDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '0';
	UpdateData(0);
}

void CcalculatorprojectDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '1';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '2';
	UpdateData(0);
}




void CcalculatorprojectDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '3';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '4';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '5';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '6';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '7';
	UpdateData(0);
}

void CcalculatorprojectDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '8';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Finish = m_Finish + '9';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButtonPlus()//+를 눌렀을때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_select = PLUS;
	m_First = _ttoi(m_Finish);//ttoi는 정수로 변환
	m_Finish = ' ';
	UpdateData(FALSE);
}


void CcalculatorprojectDlg::OnBnClickedButtonMin()//-
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_select = MINUS;
	m_First = _ttoi(m_Finish);//ttoi는 정수로 변환
	m_Finish = ' ';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButtonMul()//*
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_select = MULTIPLY;
	m_First = _ttoi(m_Finish);//ttoi는 정수로 변환
	m_Finish = ' ';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButtonDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_select = DIVIDE;
	m_First = _ttoi(m_Finish);//ttoi는 정수로 변환
	m_Finish = ' ';
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButtonEnd()//=
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_Second = _ttoi(m_Finish);

	switch (m_select) {
	case PLUS:
		m_Result = m_First + m_Second;
		break;

	case MINUS:
		m_Result = m_First - m_Second;
		break;

	case MULTIPLY:
		m_Result = m_First * m_Second;
		break;

	case DIVIDE:
		m_Result = m_First / m_Second;
		break;

	}
	m_Finish.Format(_T("%d"), m_Result);
	UpdateData(0);
}


void CcalculatorprojectDlg::OnBnClickedButtonReset()//c클릭
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_First = 0;
	m_Second = PLUS;
	m_Result = 0;
	m_Finish = ' ';
	UpdateData(0);
}

