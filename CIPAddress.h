#include "CIP.h"
#include "CButton.h"
class CIPAddress : public CIP, public CButton
{
private:
 string m_strIP;
public:
 CIPAddress(HWND hDlg)
	 : CButton(hDlg)
 {
  m_strIP=GetIP().c_str();
 }
 void WriteIP(int nIDDlg){
  SendMessage(GetDlgItem(GetHWND(),nIDDlg),IPM_SETADDRESS,(WPARAM)0,(LPARAM)MAKEIPADDRESS(GetFirstIP(),GetSecondIP(),GetThirdIP(),GetFourthIP()));
 }
 void WriteIP(HWND hDlg){
  SendMessage(hDlg,IPM_SETADDRESS,(WPARAM)0,(LPARAM)MAKEIPADDRESS(GetFirstIP(),GetSecondIP(),GetThirdIP(),GetFourthIP()));
 }
 void ClearIP(int nIDDlg){
  SendMessage(GetDlgItem(GetHWND(),nIDDlg),IPM_CLEARADDRESS,0,0);
 }
 void ClearIP(HWND hDlg){
  SendMessage(hDlg,IPM_CLEARADDRESS,0,0);
 }
 void CopyText();
};