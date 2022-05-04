#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include"Admin.h"
using namespace std;

string Admin::Login(string param){
  Sharefunction<AdminMsg> sharefunction;
  AdminMsg msg=sharefunction.StringToMsg(param);
  string Id=msg.Id;
  string pwd=msg.pwd;
  cout<<"AdminLogin"<<Id<<" "<<pwd<<" "<<endl;
  string sql="select * from Admin where Id = '" +Id+ "' and pwd = '" +pwd+ "'";
  cout<<"login_sql:"<<sql<<endl;
  vector<string> res;
  res = db.loginSQL(sql);
  if(res.size()>1){
  msg.name =res[3];
  msg.college=res[4];
  Sharefunction<AdminMsg> sharefunction;
  return sharefunction.MsgToString(msg);
  }
  
  return "fail";
}

string Admin::TodaySubmit(string param){
  Sharefunction<TodaySubmitQueryMsg> sharefunction;
  TodaySubmitQueryMsg msg =sharefunction.StringToMsg(param);
  string date = msg.date;
  string college = msg.college;
  cout<<"TodaySubmit"<<endl;
  string sql="select * from DailySubmit ,Student where date = '"+date+"' and college = '"+college+"'  and DailySubmit.Id = Student.Id";
  cout<<"GetSubmitLogSQL:"<<sql<<endl;
  vector<vector<string> > result;
  result = db.GetSubmitLogSQL(sql);
  TodaySubmitLogsMsg TodaySubmitLogs;
  for(int i=0;i<result.size();i++){
    TodaySubmitMsg msg = ListToTodaySubmitMsg(result[i]);
    TodaySubmitLogs.todaySubmitLogs.push_back(msg);
  }
  Sharefunction<TodaySubmitLogsMsg> sharefunction1;
  string Logs=sharefunction1.MsgToString(TodaySubmitLogs);
  
  return Logs;
   
}

TodaySubmitMsg Admin::ListToTodaySubmitMsg(vector<string> Submit){
  TodaySubmitMsg msg; 
  if(Submit.size()>0){
    msg.dailySubmitMsg.Id=Submit[0];
    msg.dailySubmitMsg.address=Submit[1];
    msg.dailySubmitMsg.inSchool=Submit[2];
    msg.dailySubmitMsg.inCity=Submit[3];
    msg.dailySubmitMsg.temperature=Submit[4];
    msg.dailySubmitMsg.healthy=Submit[5];
    msg.dailySubmitMsg.personType=Submit[6];
    msg.dailySubmitMsg.relative=Submit[7];
    msg.dailySubmitMsg.note=Submit[8];
    msg.dailySubmitMsg.date=Submit[9];
    msg.studentMsg.Id=Submit[10];
    msg.studentMsg.pwd=Submit[11];
    msg.studentMsg.name=Submit[12];
    msg.studentMsg.college=Submit[13];
    msg.studentMsg.major=Submit[14];
    msg.studentMsg.stuClass=Submit[15];
    msg.studentMsg.submitdays=Submit[16];
 
  }
  return msg;
}





