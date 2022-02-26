
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)

	ON_BN_CLICKED(IDC_RADIO7, &CMFCprojectDlg::OnBnClickedRadio7)
	ON_WM_NCRBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCprojectDlg::OnBnClickedButton7)

	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCprojectDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_RADIO10, &CMFCprojectDlg::OnBnClickedRadio10)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); 
		for (int i = 0; i < figs.GetSize(); i++)
		{
			
			figs[i]->Drawcolor(&dc);
		}
		CDialogEx::OnPaint();
	}
}


HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	//for (int i = figs.GetSize() - 1; i >= 0; --i)
	//{
	//	if (figs[i]->isInside(point))
	//	{
	//		isinsideflag = true;
	//		indexSelected = i;
	//		pressedpoint = point;
	//		break;
	//	}
	//}
	
	if(!isinsideflag)
	{ 
		switch (futureFigureKind)
		{
		case 1:
			figs.Add(new RectangleF(start, start));
			break;
		case 2:
			figs.Add(new EllipseF(start, start));
			break;
		case 3:
			figs.Add(new TriangleF(start, start));
			break;
		case 4:
			figs.Add(new TrapezeF(start, start));
			break;
		case 5:
			figs.Add(new StarF(start, start));
			break;
		case 6:
			figs.Add(new LineF(start, start));
			break;
		case 7:
			figs.Add(new MagenDavidF(start, start));
			break;
		}
		figs[figs.GetSize() - 1]->SetFG(color);
		figs[figs.GetSize() - 1]->SetBG(RefillColor);
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	/*if (isinsideflag)
	{
		isinsideflag = false;
		Invalidate();
	}*/
	  if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	/*if (isinsideflag)
	{
		figs[indexSelected]->Shift(point.x - pressedpoint.x, point.y - pressedpoint.y);
		pressedpoint = point;
		Invalidate();
	}*/
	if (isPressed)
	{
	
			/*	end = point;
				figs[figs.GetSize()-1]->Redefine(start,end);
				Invalidate(); *///simulates the WM_PAINT message to redraw window

				//without invalidate...
			CClientDC dc(this);
			dc.SetROP2(R2_NOTXORPEN);
			figs[figs.GetSize() - 1]->Draw(&dc);
			end = point;
			figs[figs.GetSize() - 1]->Redefine(start, end);
			figs[figs.GetSize() - 1]->Draw(&dc);

	}
	
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCprojectDlg::OnBnClickedRadio1()//rectangle
{
	// TODO: Add your control notification handler code here
	//!! 18 b
	futureFigureKind = 1;
	//!! 18 e
}


void CMFCprojectDlg::OnBnClickedRadio2()//ellipse
{
	// TODO: Add your control notification handler code here
	//!! 19 b
	futureFigureKind = 2;
	//!! 19 e
}


void CMFCprojectDlg::OnBnClickedButton1()//save
{
	// TODO: Add your control notification handler code here
	//!! 23 b
	             // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
	//!! 23 e
}


void CMFCprojectDlg::OnBnClickedButton2()//load
{
	// TODO: Add your control notification handler code here
	//!! 24 b
			     // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	//!! 24 e
}


void CMFCprojectDlg::OnBnClickedRadio3()//triangle
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 3;
}


void CMFCprojectDlg::OnBnClickedRadio4()//trapeze
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 4;
}


void CMFCprojectDlg::OnBnClickedRadio5()//star
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 5;
}





void CMFCprojectDlg::OnBnClickedRadio7()//line
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 6;
}


void CMFCprojectDlg::OnBnClickedButton3()//frame color
{
	// TODO: Add your control notification handler code here
	CColorDialog CPdlg;
	if (CPdlg.DoModal() == IDOK) {
		color = CPdlg.GetColor();
	}
}


void CMFCprojectDlg::OnBnClickedButton4()//undo
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() > 0)
	{
		UndoFlag = true;
		UndoFigs.Add(figs[figs.GetSize()- 1]);
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedButton5()//redo
{
	// TODO: Add your control notification handler code here
	if (UndoFlag&&UndoFigs.GetSize()>0)
	{
		figs.Add(UndoFigs[UndoFigs.GetSize() -1]);
		UndoFigs.RemoveAt(UndoFigs.GetSize() - 1);
		Invalidate();
	}
}



void CMFCprojectDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	CColorDialog CBdlg;
	if (CBdlg.DoModal() == IDOK) {
		RefillColor = CBdlg.GetColor();
	}
}



void CMFCprojectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	for (int i = figs.GetSize() - 1; i >= 0; --i)
	{
		if (figs[i]->isInside(point))
		{
			figs.RemoveAt(i);
			Invalidate();
			break;
		}
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}



void CMFCprojectDlg::OnBnClickedButton6()//all frame color
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() > 0)
	{
		COLORREF newColor = figs[0]->GetFG(); //fix this ?
		CColorDialog FGdlg;
		if (FGdlg.DoModal() == IDOK)
		{
			newColor = FGdlg.GetColor();
		}
		for (int i = 0; i < figs.GetSize(); ++i)
		{
			figs[i]->SetFG(newColor);
		}
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedButton8()//CHANGE ALL BACKGROUND COLOR
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() > 0)
	{
		COLORREF newColor = figs[0]->GetBG();
		CColorDialog FGdlg;
		if (FGdlg.DoModal() == IDOK)
		{
			newColor = FGdlg.GetColor();
		}
		for (int i = 0; i < figs.GetSize(); ++i)
		{
			figs[i]->SetBG(newColor);
		}
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedButton9()//new
{
	// TODO: Add your control notification handler code here
	figs.RemoveAll();
	Invalidate();
}


void CMFCprojectDlg::OnBnClickedRadio10()//magen david
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 7;
}
