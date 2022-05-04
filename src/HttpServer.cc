#include <muduo/net/http/HttpServer.h>
#include <muduo/net/http/HttpRequest.h>
#include <muduo/net/http/HttpResponse.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <iostream>
#include <map>
#include <string.h>
#include"Student.h"
#include"Admin.h"
#include"Share.h"
using namespace muduo;
using namespace muduo::net;

bool benchmark = false;
                               

void onRequest(const HttpRequest& req, HttpResponse* resp)
{
  std::cout << "Headers " << req.methodString() << " " << req.path() << std::endl;
  if (!benchmark)
  {
    const std::map<string, string>& headers = req.headers();
    for (const auto& header : headers)
    {
      std::cout << header.first << ": " << header.second << std::endl;
    }
  }

  std::cout<<req.query()<<std::endl;
  if (req.path() == "/")
  {
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/html");
    resp->addHeader("Server", "Muduo");
    string now = Timestamp::now().toFormattedString();         
    resp->setBody("<html><head><title>swl</title></head>"
        "<body><h1>Hello swl</h1>Now is " + now +
        "</body></html>");
  }
  else if (req.path() == "/StudentLogin")
  {  
    Student student;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(student.Login(req.body()));
    resp->setCloseConnection(true);
  }
    else if (req.path() == "/AdminLogin")
  {  
    Admin admin;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(admin.Login(req.body()));
    resp->setCloseConnection(true);
  }
  else if (req.path() == "/Submit")
  {  
    Student student;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(student.Submit(req.body()));
    resp->setCloseConnection(true);
  }
   else if (req.path() == "/TodaySubmit")
  {  
    Admin admin;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(admin.TodaySubmit(req.body()));
    resp->setCloseConnection(true);
  }
  else if (req.path() == "/ChangePwd")
  { 
    Share share;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(share.ChangePwd(req.body()));
    resp->setCloseConnection(true);
  }
  else if (req.path() == "/GetSubmitLog")
  { 
    Student student;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(student.GetSubmitLog(req.body()));
    resp->setCloseConnection(true);
  }
  else if (req.path() == "/register")
  { 
    Student student;
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");  
    resp->setBody(student.Register(req.body()));
    resp->setCloseConnection(true);
  }
  else
  {
    resp->setStatusCode(HttpResponse::k404NotFound);
    resp->setStatusMessage("Not Found");
    resp->setCloseConnection(true);
  
  }
}

int main(int argc, char* argv[])
{
    //mdb.initDB("localhost","root","521011","WeChatApp");

  int numThreads = 0;
  if (argc > 1)
  {
    benchmark = true;
    Logger::setLogLevel(Logger::WARN);
    numThreads = atoi(argv[1]);
  }
  

  EventLoop loop;
  HttpServer server(&loop, InetAddress(8000), "dummy");
  server.setHttpCallback(onRequest);
  server.setThreadNum(numThreads);
  server.start();
  loop.loop();
}

