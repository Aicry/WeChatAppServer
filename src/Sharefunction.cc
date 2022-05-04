#ifndef _Sharefunction_H
#define _Sharefunction_H
#include<iostream>
#include<string>
#include<map>
#include"struct.h"
#include "ajson/ajson.hpp"
using namespace std;
template <typename T>
class Sharefunction
{
  public:
    Sharefunction(){};
    T StringToMsg(string param);
    string MsgToString(T msg);
    

};
template <typename T>
T Sharefunction<T>::StringToMsg(string param){
  T msg;
  cout<<"check param"<<endl;
  cout<<param<<endl;
  int length=param.length();
  cout<<length<<endl;
  char Buf[5000];
  param.copy(Buf,length,0);
  *(Buf+length)='\0';  
  cout<<Buf<<endl;
  load_from_buff(msg,Buf);
  return msg;
}
template <typename T>
string Sharefunction<T>::MsgToString(T msg){
       string_stream ss;
       save_to(ss,msg);
       return ss.str();
}
#endif