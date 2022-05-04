#ifndef _Share_H
#define _Share_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
#include"Sharefunction.h"
using namespace std;

class Share
{

public:

 ChangePwdMsg StringToChangePwdMsg(string param);
 string ChangePwd(string param);
 string userType(string Type);

private:
 
};









#endif