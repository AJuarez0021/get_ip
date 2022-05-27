#include "CWnd.h"

class CFileName : public CWnd{
public: 
 CFileName(){
  ZeroMemory(&m_strFileName,sizeof(m_strFileName));
 }
 BOOL Save(TCHAR* strFilter,TCHAR* strTitle);
 TCHAR* GetFileName(){
   return m_strFileName;
 }
private:
 TCHAR m_strFileName[MAX_PATH];
};