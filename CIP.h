#include "CFileName.h"


class CIP : public CFileName{
public:
 CIP(){  }
 string GetIP();
 BOOL Export(tstring strFileName);

 int GetFirstIP(){
   return atoi(vIP[0].c_str());
 }
 int GetSecondIP(){
  return atoi(vIP[1].c_str());
 }
 int GetThirdIP(){
  return atoi(vIP[2].c_str());
 }
 int GetFourthIP(){
  return atoi(vIP[3].c_str());
 }
private:
 vector<string> vIP;
 vector<string> Split(string strText,string strToken);
};