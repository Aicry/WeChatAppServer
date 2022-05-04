#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include "Dao.h"
#include"MyDB.h"
#include "ajson/ajson.hpp"
using namespace std;
using namespace ajson;

AJSON(StudentMsg,Id,pwd,name,college,major,stuClass,submitdays);
AJSON(DailySubmitMsg,Id ,address ,inSchool ,inCity ,temperature ,healthy ,personType ,relative, note ,date);
AJSON(ChangePwdMsg,Id,pwd,Type);
AJSON(SubmitLogsMsg,submitLogs);
AJSON(AdminMsg,Id,pwd,name,college);
AJSON(SuperAdminMsg,Id,pwd,name);
AJSON(TodaySubmitMsg,dailySubmitMsg,studentMsg);
AJSON(TodaySubmitLogsMsg,todaySubmitLogs);
AJSON(TodaySubmitQueryMsg,college,date);
void Dao::StringToBuf(string param){
    cout<<"check param"<<endl;
    cout<<param<<endl;
    int length=param.length();
    param.copy(Buf,length,0);
    *(Buf+length)='\0';  
}


string Dao::StudentLogin(string param){
  StudentMsg msg=StringToStudentMsg(param);
  string Id=msg.Id;
  string pwd=msg.pwd;
  cout<<"StudentLogin:"<<Id<<" "<<pwd<<" "<<endl;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  string sql="select * from Student where Id = '" +Id+ "' and pwd = '" +pwd+ "'";
  cout<<"login_sql:"<<sql<<endl;
  vector<string> res;
  res = db.loginSQL(sql);
  if(res.size()>1){
  msg.name =res[3];
  msg.college=res[4];
  msg.major=res[5];
  msg.stuClass=res[6];
  msg.submitdays=res[7];
  return StudentMsgToString(msg);
  }
  
  return "fail";
}
string Dao::AdminLogin(string param){
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
string Dao::SuperAdminLogin(string param){
  SuperAdminMsg msg=StringToSuperAdminMsg(param);
  string Id=msg.Id;
  string pwd=msg.pwd;
  cout<<"SuperAdminLogin"<<Id<<" "<<pwd<<" "<<endl;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  string sql="select * from SuperAdmin where Id = '" +Id+ "' and pwd = '" +pwd+ "'";
  cout<<"login_sql:"<<sql<<endl;
  vector<string> res;
  res = db.loginSQL(sql);
  if(res.size()>1){
  msg.name =res[3];
  return SuperAdminMsgToString(msg);
  }
  
  return "fail";
}


StudentMsg Dao::StringToStudentMsg(string param){
  StringToBuf(param);
	StudentMsg msg;
	load_from_buff(msg,Buf);
  return msg;
}
AdminMsg Dao::StringToAdminMsg(string param){
  StringToBuf(param);
	AdminMsg msg;
	load_from_buff(msg,Buf);

  return msg;
}
SuperAdminMsg Dao::StringToSuperAdminMsg(string param){
  StringToBuf(param);
	SuperAdminMsg msg;
	load_from_buff(msg,Buf);
  return msg;
}


string Dao::StudentMsgToString(StudentMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"StudentMsgToString:"<<ss.str()<<endl;
       return ss.str();
}
string Dao::AdminMsgToString(AdminMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"AdminMsgToString:"<<ss.str()<<endl;
       return ss.str();
}
string Dao::SuperAdminMsgToString(SuperAdminMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"StudentMsgToString:"<<ss.str()<<endl;
       return ss.str();
}



string Dao::Register(string param){
  StudentMsg msg=StringToStudentMsg(param);
  string Id=msg.Id;
  string pwd=msg.pwd;
  string name=msg.name;
  string college=msg.college;
  string major= msg.major;
  string stuClass=msg.stuClass;
  string submitdays=msg.submitdays;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  /*(`Id`, `pwd`, `name`)*/
  string sql="INSERT INTO Student VALUES ('" +Id+  "', '"  +pwd+  "', '"+name+"', '"+college+"','"+major+"', '"+stuClass+"', '"+submitdays+"')";
  return db.RegisterSQL(sql);
}



string Dao::ChangePwd(string param){
  ChangePwdMsg msg=StringToChangePwdMsg(param);
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"ChangePwd"<<endl;
  string Id=msg.Id;
  string pwd=msg.pwd;
  string Type=userType(msg.Type);
  
  string sql="UPDATE "+Type+" SET pwd = '"+pwd+"' WHERE Id = '"+Id+"'";
  cout<<"changPwdSQL:"<<sql<<endl;
  string result;
  result = db.ChageMsgSQL(sql);
  return result;
}
ChangePwdMsg Dao::StringToChangePwdMsg(string param){
  StringToBuf(param);
	ChangePwdMsg msg;
	load_from_buff(msg,Buf);
	cout <<"StringToChangePwdMsg:" <<msg.Id << " " << msg.pwd <<" "<<msg.Type<< std::endl;
  return msg;
}
string Dao::userType(string Type){
  if(Type=="学生")return "Student";
  if(Type=="管理员")return "Admin";
  if(Type=="超级管理员")return "SuperAdmin";
  cout<<"userTypeError:"<<endl;
  return "";
}



string Dao::StudentSubmit(string param){
  DailySubmitMsg msg=StringToDailySubmitMsg(param);
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"StudentSubmit"<<endl;
  string Id=msg.Id;
  string address=msg.address;
  string inSchool=msg.inSchool;
  string inCity=msg.inCity;
  string temperature=msg.temperature;
  string healthy=msg.healthy;
  string personType=msg.personType;
  string relative=msg.relative;
  string note=msg.note;
  string date=msg.date;
  string sql="INSERT INTO DailySubmit VALUES ('"+Id+"', '"+address+"', '"+inSchool+"','"+inCity+"','"  +temperature+  "','"+healthy+"','"+personType+"','"+relative+"','"+note+"','"+date+"')";
  cout<<"submitSQL:"<<sql<<endl;
  string result= db.submitSQL(sql);

  if(result=="success"){
  string res;
  string sql="UPDATE Student SET submitdays = submitdays + 1 WHERE Id = '"+Id+"'"; 
  cout<<sql<<endl;
  res=db.ChageMsgSQL(sql);
  if(res=="fail")cout<<"submitdays ChangeError"<<endl;
  }

  return result;
}
DailySubmitMsg Dao::StringToDailySubmitMsg(string param){
  StringToBuf(param);
	DailySubmitMsg msg;
	load_from_buff(msg,Buf);
	cout <<"StringToDailySubmitMsg:" << std::endl;
  return msg;
}
string Dao::GetSubmitLog(string Id){
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"GetSubmitLog"<<endl;
  string sql="select * from DailySubmit where Id = "+Id+"";
  cout<<"GetSubmitLogSQL:"<<sql<<endl;
  vector<vector<string> > result;
  result = db.GetSubmitLogSQL(sql);
  string Logs="";
  SubmitLogsMsg submitLogsMsg;
  for(int i=0;i<result.size();i++){
    DailySubmitMsg msg = ListToDailySubmitMsg(result[i]);
    submitLogsMsg.submitLogs.push_back(msg);
  }
  Logs=SubmitLogsMsgToString(submitLogsMsg);
  
  return Logs;
}

TodaySubmitMsg Dao::StringToTodaySubmitMsg(string param){
  StringToBuf(param);
	TodaySubmitMsg msg;
	load_from_buff(msg,Buf);
	cout <<"StringToTodaySubmitMsg:" << std::endl;
  return msg;
}
TodaySubmitQueryMsg Dao::StringToTodaySubmitQueryMsg(string param){
  StringToBuf(param);
	TodaySubmitQueryMsg msg;
	load_from_buff(msg,Buf);
	cout <<"TodaySubmitQueryMsg:" << std::endl;
  return msg;
}
string Dao::TodaySubmit(string param){
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
TodaySubmitMsg Dao::ListToTodaySubmitMsg(vector<string> Submit){
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

DailySubmitMsg Dao::ListToDailySubmitMsg(vector<string> Submit){

  DailySubmitMsg msg;
  if(Submit.size()>0){
   
   msg.Id=Submit[0];
   msg.address=Submit[1];
   msg.inSchool=Submit[2];
   msg.inCity=Submit[3];
   msg.temperature=Submit[4];
   msg.healthy=Submit[5];
   msg.personType=Submit[6];
   msg.relative=Submit[7];
   msg.note=Submit[8];
   msg.date=Submit[9];
  }
  return msg;
}
string Dao::SubmitLogsMsgToString(SubmitLogsMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"DailySubmitMsgToString:"<<ss.str()<<endl;
       return ss.str();
}
string Dao::TodaySubmitLogsMsgToString(TodaySubmitLogsMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"TodaySubmitLogsMsgToString:"<<ss.str()<<endl;
       return ss.str();
}


