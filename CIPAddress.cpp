#include "CIPAddress.h"

void CIPAddress::CopyText()
{
   HGLOBAL hGMemText=NULL;  																   					
   char *pstrIP=NULL;
				    
   hGMemText = GlobalAlloc(GHND, m_strIP.length()+1);                     
   pstrIP=(char*)GlobalLock(hGMemText);					
   strcpy(pstrIP,m_strIP.c_str());										 
   GlobalUnlock(hGMemText);

   if(!OpenClipboard(GetHWND())){
	 ShowError(TEXT("Error al abrir el portapapeles"));
	 return;
   }

   if(!EmptyClipboard()){
	 ShowError(TEXT("Error al vaciar el portapapeles"));
	 return;
   }

   if(hGMemText==NULL){
     ShowError(TEXT("Error al asignar memoria"));
	 CloseClipboard();
	 return;
   }

   if(SetClipboardData(CF_TEXT,hGMemText)==NULL){
	 ShowError(TEXT("Error al copiar en el portatpapeles"));
	 return;
   }

   CloseClipboard();
					
   ShowMsg(TEXT("Se ha copiado el texto al portapapeles"));
}