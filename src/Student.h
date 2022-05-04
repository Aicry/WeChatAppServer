#ifndef _Student_H
#define _Student_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
#include"Sharefunction.cc"
using namespace std;


class Student
{

public:

 Student(){db.initDB("localhost","root","521011","WeChatApp");};

 string Login(string param);

 string Register(string param);

 string Submit(string param);

 string GetSubmitLog(string Id);

 DailySubmitMsg ListToDailySubmitMsg(vector<string> Submit);

private:
 MyDB db;
};









#endif