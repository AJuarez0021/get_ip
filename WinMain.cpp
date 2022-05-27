//GetIP version 1.0
//Programa compilado con Visual C++ 6.0
//http://programacioncpp.irandohosting.0lx.net

#include "CIPAddress.h"

#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"comctl32.lib")


LRESULT CALLBACK DlgProc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK AboutProc(HWND,UINT,WPARAM,LPARAM);


int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
 DialogBox(hInst,MAKEINTRESOURCE(IDD_MAIN),NULL,(DLGPROC)DlgProc);
 return 0;
}


LRESULT CALLBACK AboutProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
 switch(uMsg){
   case WM_INITDIALOG:
	    return 0;
    case WM_CLOSE:
	    EndDialog(hDlg,0);		
		return 0;      
	case WM_COMMAND:
	    switch(LOWORD(wParam)){	 
		  case IDOK:
			   EndDialog(hDlg,0);
			   break;
		}
		return 0;
   default:
	    return 0;

 }
 return DefWindowProc(hDlg,uMsg,wParam,lParam);
}

LRESULT CALLBACK DlgProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
  static CIPAddress *ip=new CIPAddress(hDlg);
 
  switch(uMsg){
   case WM_INITDIALOG:
	    ip->SetHWND(hDlg);	 
		ip->SetIconDlg(IDI_ICON1);
		ip->CreateImageButton(IDEXPORT);
		ip->CreateImageButton(IDCOPY);
		ip->CreateImageButton(IDABOUT);
		ip->SetIconButton(IDEXPORT, IDI_ICON2);
        ip->SetIconButton(IDCOPY,IDI_ICON3);
		ip->SetIconButton(IDABOUT,IDI_ICON4);		
		ip->Center();
		ip->WriteIP(GetDlgItem(hDlg,IDC_IPADDRESS));		
	    return 0;
   case WM_CLOSE:
	    EndDialog(hDlg,0);		
		return 0;
   case WM_DESTROY:
	    delete ip;
	    PostQuitMessage(0);
	    return 0;
	case WM_COMMAND:
	    switch(LOWORD(wParam)){	               
			   case IDEXPORT:
				    if(ip->Save(TEXT("Archivos HTML *.html\0*.html\0"),TEXT("Save")))
					{						
					 if(ip->Export(ip->GetFileName()))
					  ip->ShowMsg(TEXT("Archivo exportado"));
					 else
					  ip->ShowError(TEXT("Error no se pudo exportar el archivo"));
					}
				    break;
			   case IDCOPY:				   				  								   
				    ip->CopyText();
				    break;
			   case IDABOUT:
				    DialogBox(ip->GetInstance(),MAKEINTRESOURCE(IDD_ABOUT),hDlg,(DLGPROC)AboutProc);
				    break;
		}
		return 0;
	default:
		return 0;	
 }
 return DefWindowProc(hDlg,uMsg,wParam,lParam);
}