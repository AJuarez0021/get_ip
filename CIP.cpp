#include "CIP.h"

string CIP::GetIP()
{
      WORD wVersionRequested;
      WSADATA wsaData;
      char Host[255];	     
	  string ip;
      PHOSTENT hostinfo;
      wVersionRequested = MAKEWORD( 2, 0 );      
      if (WSAStartup( wVersionRequested, &wsaData ) == 0 ){
        if(gethostname (Host, sizeof(Host)) == 0){
           if((hostinfo = gethostbyname(Host)) != NULL){
               ip=inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
			   string s=ip.c_str();
			   vIP=Split(s,".");
           }
        }
        WSACleanup( );
      }	  
	  return ip;
}

vector<string> CIP::Split(string strCad,string strSeps)
{
 vector<string> v;
 char* token=NULL;
 string strTokens;
 token = strtok((char*)strCad.c_str(), strSeps.c_str());
 v.clear();
 while(token != NULL ){         
  strTokens=token;
  v.push_back(strTokens);
  token = strtok( NULL, strSeps.c_str());
 }    
 return v;
}


BOOL CIP::Export(tstring strFileName)
{
 
 typedef std::basic_ofstream<TCHAR> tofstream;
 tofstream f;
 TCHAR strHour[40];
 TCHAR strIP[18];
 
 SYSTEMTIME lpSystemTime;  
 GetLocalTime(&lpSystemTime);
 f.open(strFileName.c_str());
 if(f.fail()) 
  return FALSE;  
 
 wsprintf(strIP,TEXT("%d.%d.%d.%d"),GetFirstIP(),GetSecondIP(),GetThirdIP(),GetFourthIP());
 f << TEXT("<HTML>") << endl;
 f << TEXT("<HEAD>") << endl;
 f << TEXT("<TITLE> GetIP </TITLE>") << endl;
 f << TEXT("<CENTER>") << endl;
 f << TEXT("<FONT COLOR=WHITE><BR>") << endl;
 f << TEXT("<H2>Tu IP es:</H2>") << endl;
 f << TEXT("</FONT>")<< endl;
 f << TEXT("</CENTER>") << endl;
 f << TEXT("</HEAD>")<<endl;
 f << TEXT("<CENTER>") << endl;
 f << TEXT("<BODY BGCOLOR=BLACK>") << endl;
 f << TEXT("<FONT COLOR=WHITE><BR>") << endl;
 f << TEXT("<BR>IP = ") << strIP << endl;
 f << TEXT("<BR><BR>Fecha: ") << lpSystemTime.wDay << TEXT("/") << lpSystemTime.wMonth << TEXT("/") <<lpSystemTime.wYear << TEXT("<br>") << endl; 
 wsprintf(strHour,TEXT("Hora: %02d:%02d:%02d"),lpSystemTime.wHour,lpSystemTime.wMinute,lpSystemTime.wSecond);
 f << strHour << endl;
 f << TEXT("</FONT>") << endl;
 f << TEXT("</CENTER>")<<endl;
 f << TEXT("</BODY>") << endl;
 f << TEXT("</HTML>") << endl;
 f.close();
 return TRUE;
}


