#ifndef _Admin_H
#define _Admin_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
#include"Sharefunction.h"
using namespace std;

class Admin
{

public:



 string AdminLogin(string param);

 AdminMsg StringToAdminMsg(string param);
 
 string AdminMsgToString(AdminMsg msg);


 string TodaySubmit(string param);
 TodaySubmitMsg StringToTodaySubmitMsg(string param);
 TodaySubmitMsg ListToTodaySubmitMsg(vector<string> Submit);
 
 TodaySubmitQueryMsg StringToTodaySubmitQueryMsg(string param);

 string TodaySubmitLogsMsgToString(TodaySubmitLogsMsg msg);


private:
};









#endif