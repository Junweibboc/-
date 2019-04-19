
// MFCApplication3Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication3Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication3Dlg::OnBnClickedButton14)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication3Dlg::BottomClick(int ID)
{
	CWnd *pt = GetDlgItem(ID);
	CRect rect;
	CPoint topleft;

	int height;
	int width;

	pt->GetWindowRect(&rect);
	ScreenToClient(&rect);
	topleft = rect.TopLeft();
	height = rect.Height();
	width = rect.Width();

	if (topleft.y > 540)
		pt->MoveWindow(topleft.x, topleft.y - 10, width, height);
	else
		pt->MoveWindow(topleft.x, topleft.y + 10, width, height);


	/*
	CString str;
	str.Format(_T("%d %d"), topleft.x, topleft.y);
	GetDlgItem(ID)->SetWindowTextW(str);
	*/
}





void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON1);

}


void CMFCApplication3Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON2);
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON3);
}


void CMFCApplication3Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON4);
}


void CMFCApplication3Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON5);
}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON6);
}


void CMFCApplication3Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON7);
}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON8);
}


void CMFCApplication3Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON9);
}


void CMFCApplication3Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON10);
}


void CMFCApplication3Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON11);
}


void CMFCApplication3Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON12);
}


void CMFCApplication3Dlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON13);
}


void CMFCApplication3Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	BottomClick(IDC_BUTTON14);
}
