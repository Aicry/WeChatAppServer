#ifndef _DAO_H
#define _DAO_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
using namespace std;


class Dao
{

public:

 void StringToBuf(string param);
 
 string StudentLogin(string param);
 string AdminLogin(string param);
 string SuperAdminLogin(string param);

 StudentMsg StringToStudentMsg(string param);
 AdminMsg StringToAdminMsg(string param);
 SuperAdminMsg StringToSuperAdminMsg(string param);

 string StudentMsgToString(StudentMsg msg);
 string AdminMsgToString(AdminMsg msg);
 string SuperAdminMsgToString(SuperAdminMsg msg);


 string StudentSubmit(string param);
 string GetSubmitLog(string Id);
 DailySubmitMsg StringToDailySubmitMsg(string param);
 DailySubmitMsg ListToDailySubmitMsg(vector<string> Submit);
 string SubmitLogsMsgToString(SubmitLogsMsg msg);

 string TodaySubmit(string param);
 TodaySubmitMsg StringToTodaySubmitMsg(string param);
 TodaySubmitMsg ListToTodaySubmitMsg(vector<string> Submit);
 string TodaySubmitLogsMsgToString(TodaySubmitLogsMsg msg);
 TodaySubmitQueryMsg StringToTodaySubmitQueryMsg(string param);

 ChangePwdMsg StringToChangePwdMsg(string param);
 string ChangePwd(string param);
 string userType(string Type);

 string Register(string param);

private:
 char Buf[5000];
};









#endif