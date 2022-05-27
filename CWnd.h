#pragma warning(disable:4786)
#include <windows.h>
#include <commctrl.h>
#include <string>
#include <vector>
#include <fstream>
#include "resource.h"



typedef std::basic_string<TCHAR> tstring;

using namespace std;

class CWnd{
public:
  CWnd(){  
   INITCOMMONCONTROLSEX c;
   c.dwSize=sizeof(INITCOMMONCONTROLSEX);
   c.dwICC=ICC_INTERNET_CLASSES;
   InitCommonControlsEx(&c);
   m_hDlg=NULL;
   
  }
  void SetHWND(HWND hDlg){
   m_hDlg=hDlg;
  }
  HWND GetHWND() const{
   return m_hDlg;
  }
  HINSTANCE GetInstance(){
   return GetModuleHandle(NULL);
  }
  void Center(){   
    RECT r;
	GetClientRect(m_hDlg,&r);
	int m_Width		= r.right;
	int m_Height	= r.bottom;

	RECT ScreenRect;
	GetWindowRect (GetDesktopWindow(), &ScreenRect);
	SetWindowPos (m_hDlg, HWND_TOP, (((ScreenRect.right + ScreenRect.left) / 2) - (m_Width / 2)),
				 (((ScreenRect.bottom + ScreenRect.top) / 2) - (m_Height / 2)),
				  0, 0, SWP_NOCOPYBITS | SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW);

  }
  void SetIconDlg(int nIDIcon){   
    HICON hIcon;    
    hIcon=LoadIcon(GetInstance(),MAKEINTRESOURCE(nIDIcon));
    SendMessage(m_hDlg,WM_SETICON,ICON_BIG, (LPARAM) hIcon);
    SendMessage(m_hDlg,WM_SETICON,ICON_SMALL,(LPARAM)hIcon);  
  }
  void ShowMsg(tstring strText){
	  MessageBox(m_hDlg,strText.c_str(),TEXT("GetIP"),MB_ICONINFORMATION|MB_OK);
  }
  void ShowError(tstring strText){
	  MessageBox(m_hDlg,strText.c_str(),TEXT("GetIP"),MB_ICONERROR);
  }
  /*void SetImageButton(){    
   ImageButton_EnableXPThemes();
   ImageButton_Create(GetHWND(), IDEXPORT);
   ImageButton_Create(GetHWND(), IDCOPY);   
   ImageButton_Create(GetHWND(), IDABOUT);  
   ImageButton_SetIcon(GetDlgItem(GetHWND(), IDEXPORT), IDI_ICON2,0,0,16,16);
   ImageButton_SetIcon(GetDlgItem(GetHWND(), IDCOPY), IDI_ICON3,0,0,16,16);
   ImageButton_SetIcon(GetDlgItem(GetHWND(), IDABOUT), IDI_ICON4,0,0,16,16);
  }*/

protected:
   HWND m_hDlg;
};

