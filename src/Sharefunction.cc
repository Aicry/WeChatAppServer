#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include "Sharefunction.h"
using namespace std;
void Sharefunction::StringToBuf(string param){
    cout<<"check param"<<endl;
    cout<<param<<endl;
    int length=param.length();
    cout<<length<<endl;
    param.copy(Buf,length,0);
    *(Buf+length)='\0';  
    cout<<Buf<<endl;
}