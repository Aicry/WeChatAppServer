#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include"Student.h"
using namespace std;




string Student::StudentLogin(string param){
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

StudentMsg Student::StringToStudentMsg(string param){
  Sharefunction sharefunction;
  sharefunction.StringToBuf(param);
	StudentMsg msg;
	load_from_buff(msg,sharefunction.Buf);
  return msg;
}


string Student::StudentMsgToString(StudentMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"StudentMsgToString:"<<ss.str()<<endl;
       return ss.str();
}

string Student::Register(string param){
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


string Student::StudentSubmit(string param){
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
DailySubmitMsg Student::StringToDailySubmitMsg(string param){
  Sharefunction sharefunction;
  sharefunction.StringToBuf(param);
	DailySubmitMsg msg;
	load_from_buff(msg,sharefunction.Buf);
	cout <<"StringToDailySubmitMsg:" << std::endl;
  return msg;
}
string Student::GetSubmitLog(string Id){
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


DailySubmitMsg Student::ListToDailySubmitMsg(vector<string> Submit){

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
string Student::SubmitLogsMsgToString(SubmitLogsMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"DailySubmitMsgToString:"<<ss.str()<<endl;
       return ss.str();
}


