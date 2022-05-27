#include "CFileName.h"

BOOL CFileName::Save(TCHAR* lpszFiltro,TCHAR* lpszTitulo)
{	
    static OPENFILENAME  ofn; 
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = m_hDlg;
	ofn.nFileExtension=1;
	ofn.lpstrFilter = (lpszFiltro);
	ofn.lpstrFile = m_strFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = (lpszTitulo);
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY;
	ofn.lpstrDefExt = TEXT("html");	
	return GetSaveFileName (&ofn);
}