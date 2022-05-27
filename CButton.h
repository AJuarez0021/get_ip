#include <windows.h>
#include "ImageButton.h"

class CButton 
{
private:
 HWND m_hDlg;
public:
 CButton(HWND hDlg){
  ImageButton_EnableXPThemes();
  m_hDlg=hDlg;
 }

 CButton(){
  ImageButton_EnableXPThemes();
  m_hDlg=NULL;
 }
 ~CButton(){
  m_hDlg=NULL;
 }
 void CreateImageButton(int nID){
  ImageButton_Create(m_hDlg,nID);
 }	 
 void SetIconButton(int nID,int nIDIcon){
  ImageButton_SetIcon(GetDlgItem(m_hDlg, nID), nIDIcon,0,0,16,16);
 }
 void Enable(int nID,BOOL bEnable){
  EnableWindow(GetDlgItem(m_hDlg,nID),bEnable); 
 } 
};