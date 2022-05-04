#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include"Admin.h"
using namespace std;


string Admin::AdminLogin(string param){
  AdminMsg msg=StringToAdminMsg(param);
  string Id=msg.Id;
  string pwd=msg.pwd;
  cout<<"AdminLogin"<<Id<<" "<<pwd<<" "<<endl;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  string sql="select * from Admin where Id = '" +Id+ "' and pwd = '" +pwd+ "'";
  cout<<"login_sql:"<<sql<<endl;
  vector<string> res;
  res = db.loginSQL(sql);
  if(res.size()>1){
  msg.name =res[3];
  msg.college=res[4];
  return AdminMsgToString(msg);
  }
  
  return "fail";
}


AdminMsg Admin::StringToAdminMsg(string param){
  Sharefunction sharefunction;
  sharefunction.StringToBuf(param);
	AdminMsg msg;
	load_from_buff(msg,sharefunction.Buf);
  return msg;
}


string Admin::AdminMsgToString(AdminMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"AdminMsgToString:"<<ss.str()<<endl;
       return ss.str();
}

string Admin::TodaySubmit(string param){
  TodaySubmitQueryMsg msg = StringToTodaySubmitQueryMsg(param);
  string date = msg.date;
  string college = msg.college;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"TodaySubmit"<<endl;
  string sql="select * from DailySubmit ,Student where date = '"+date+"' and college = '"+college+"'  and DailySubmit.Id = Student.Id";
  cout<<"GetSubmitLogSQL:"<<sql<<endl;
  vector<vector<string> > result;
  result = db.GetSubmitLogSQL(sql);
  string Logs="";
  TodaySubmitLogsMsg TodaySubmitLogs;
  for(int i=0;i<result.size();i++){
    TodaySubmitMsg msg = ListToTodaySubmitMsg(result[i]);
    TodaySubmitLogs.todaySubmitLogs.push_back(msg);
  }
  Logs=TodaySubmitLogsMsgToString(TodaySubmitLogs);
  
  return Logs;
   
}

TodaySubmitMsg Admin::StringToTodaySubmitMsg(string param){
  Sharefunction sharefunction;
  sharefunction.StringToBuf(param);
	TodaySubmitMsg msg;
	load_from_buff(msg,sharefunction.Buf);
	cout <<"StringToTodaySubmitMsg:" << std::endl;
  return msg;
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


TodaySubmitQueryMsg Admin::StringToTodaySubmitQueryMsg(string param){
  Sharefunction sharefunction;
  sharefunction.StringToBuf(param);
	TodaySubmitQueryMsg msg;
	load_from_buff(msg,sharefunction.Buf);
	cout <<"TodaySubmitQueryMsg:" << std::endl;
  return msg;
}

string Admin::TodaySubmitLogsMsgToString(TodaySubmitLogsMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"TodaySubmitLogsMsgToString:"<<ss.str()<<endl;
       return ss.str();
}


