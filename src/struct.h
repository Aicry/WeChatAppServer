#ifndef _struct_H
#define _struct_H


#include<string>
#include "ajson/ajson.hpp"
using namespace std;
using namespace ajson;


struct StudentMsg
{
 string Id;
 string pwd; 
 string name;
 string college;
 string major;
 string stuClass;
 string submitdays;
};
struct ChangePwdMsg{
 string Id;
 string pwd;
 string Type;

};
struct DailySubmitMsg
{
  string Id;
  string address;
  string inSchool;
  string inCity ;
  string temperature;
  string healthy;
  string personType;
  string relative;
  string note;
  string date;
};
struct TodaySubmitQueryMsg{
  string college;
  string date;
};
struct TodaySubmitMsg{
  DailySubmitMsg dailySubmitMsg;
  StudentMsg studentMsg;
};
struct TodaySubmitLogsMsg{
  vector<TodaySubmitMsg>  todaySubmitLogs;
};
struct AdminMsg
{
  string Id;
  string pwd;
  string name;
  string college;
};

struct SuperAdminMsg
{
  string Id;
  string pwd;
  string name;
};

struct SubmitLogsMsg{
  
  vector<DailySubmitMsg> submitLogs;
};

AJSON(StudentMsg,Id,pwd,name,college,major,stuClass,submitdays);
AJSON(DailySubmitMsg,Id ,address ,inSchool ,inCity ,temperature ,healthy ,personType ,relative, note ,date);
AJSON(ChangePwdMsg,Id,pwd,Type);
AJSON(SubmitLogsMsg,submitLogs);
AJSON(AdminMsg,Id,pwd,name,college);
AJSON(SuperAdminMsg,Id,pwd,name);
AJSON(TodaySubmitMsg,dailySubmitMsg,studentMsg);
AJSON(TodaySubmitLogsMsg,todaySubmitLogs);
AJSON(TodaySubmitQueryMsg,college,date);
#endif