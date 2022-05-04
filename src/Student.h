#ifndef _Student_H
#define _Student_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
#include"Sharefunction.h"
using namespace std;


class Student
{

public:

 
 string StudentLogin(string param);

 StudentMsg StringToStudentMsg(string param);

 string StudentMsgToString(StudentMsg msg);

 string Register(string param);

 string StudentSubmit(string param);

 DailySubmitMsg StringToDailySubmitMsg(string param);

 string GetSubmitLog(string Id);




 DailySubmitMsg ListToDailySubmitMsg(vector<string> Submit);
 string SubmitLogsMsgToString(SubmitLogsMsg msg);




private:
 
};









#endif