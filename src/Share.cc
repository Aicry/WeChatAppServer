#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include"Share.h"
using namespace std;

string Share::ChangePwd(string param){
  Sharefunction<ChangePwdMsg> sharefunction;
  ChangePwdMsg msg =sharefunction.StringToMsg(param);
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

string Share::userType(string Type){
  if(Type=="学生")return "Student";
  if(Type=="管理员")return "Admin";
  if(Type=="超级管理员")return "SuperAdmin";
  cout<<"userTypeError:"<<endl;
  return "";
}



