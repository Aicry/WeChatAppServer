#ifndef _Admin_H
#define _Admin_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
#include"Sharefunction.cc"
using namespace std;

class Admin
{

public:

 Admin(){db.initDB("localhost","root","521011","WeChatApp");};

 string Login(string param);

 string TodaySubmit(string param);

 TodaySubmitMsg ListToTodaySubmitMsg(vector<string> Submit);
 

private:
  MyDB db;
};









#endif