#ifndef _Share_H
#define _Share_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
#include"struct.h"
#include"Sharefunction.cc"
using namespace std;

class Share
{

public:
 Share(){db.initDB("localhost","root","521011","WeChatApp");};
 string ChangePwd(string param);
 string userType(string Type);

private:
 MyDB db;
};









#endif