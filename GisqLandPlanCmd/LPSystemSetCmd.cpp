// LPSystemSetCmd.cpp : CLPSystemSetCmd 的实现

#include "stdafx.h"
#include "LPSystemSetCmd.h"


// CLPSystemSetCmd

STDMETHODIMP CLPSystemSetCmd::OnClick()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CWnd *pParent;
	pParent = CWnd::FromHandle((HWND)m_ipFramework->GetParentHWnd());

	HWND hwndImpDlg = NULL;
	hwndImpDlg = FindWindow(NULL,_T("系统设置"));
	//如果窗口没有被创建，创建窗口
	if (hwndImpDlg == NULL)
	{
		m_pSystemSetDlg = new CLPSystemSetDlg(pParent);
		m_pSystemSetDlg->Create(MAKEINTRESOURCE(IDD_SYSTEMSETDLG),pParent);
		m_pSystemSetDlg->ShowWindow(SW_SHOW);
	}else 
	{
		CWnd *CXDlg;
		CXDlg = CWnd::FromHandle(hwndImpDlg);
		// 		CXDlg->SendMessage(WM_DESTROY);
		// 		m_AttrSearchDlg = new CLPAttrSearchDlg(m_ipFramework,hMainWnd);
		// 		m_AttrSearchDlg->Create(MAKEINTRESOURCE(IDD_LPATTRSEARCHDLG),hMainWnd);
		// 		m_AttrSearchDlg->ShowWindow(SW_SHOW);
		//如果窗口已经被创建过，且被打开，设为活动窗口，否则打开窗口
		if (CXDlg->IsWindowVisible())
		{
			CXDlg->SetActiveWindow();
		}else
		{
			CXDlg->ShowWindow(SW_SHOW);
		}
	}
	return S_OK;
}