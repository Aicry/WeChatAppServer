#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include"Share.h"
using namespace std;

string Share::ChangePwd(string param){
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
ChangePwdMsg Share::StringToChangePwdMsg(string param){
  Sharefunction sharefunction;
  sharefunction.StringToBuf(param);
	ChangePwdMsg msg;
	load_from_buff(msg,sharefunction.Buf);
	cout <<"StringToChangePwdMsg:" <<msg.Id << " " << msg.pwd <<" "<<msg.Type<< std::endl;
  return msg;
}
string Share::userType(string Type){
  if(Type=="学生")return "Student";
  if(Type=="管理员")return "Admin";
  if(Type=="超级管理员")return "SuperAdmin";
  cout<<"userTypeError:"<<endl;
  return "";
}



