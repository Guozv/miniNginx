#include<unistd.h>
#include<arpa/inet.h>
#include<bits/stdc++.h>
namespace http
{
    using namespace std;
    //制造和解码http报文
    class httpmaker
    {
        private:
        string _url,_method,host,user_agent,ac;
        public:
        httpmaker(){}
        httpmaker(string _url_,string _method_,string _host,string _user_agent,string _ac):
            _url(_url_),_method(_method_),host(_host),user_agent(_user_agent),ac(_ac){}
        string gethttp(){
            string s;
            s="Request URL: ";
            s+=_url;
            s+='\r\n';
            s+="Request Method: ";
            s+=_method;
            s+='\r\n',s+='\r\n';
            s+="Request Header:\r\n";
            s+="Host: ";
            s+=host;s+='\r\n';
            s+="User-Agent: ";
            s+=user_agent,s+='\r\n';
            s+="Accept: ";
            s+=ac,s+='\r\n',s+='\r\n';
            return s;
        }
        void decode(string s)
        {
            stringstream buf;
            buf<<s;
            string a;
            getline(buf,a);
            _url=a.substr(a.find(':')+2);
            getline(buf,a);
            _method=a.substr(a.find(':')+2);
            getline(buf,a);//吃掉空格
            getline(buf,a);//吃掉空行
            getline(buf,a);
            host=a.substr(a.find(':')+2);
            getline(buf,a);
            user_agent=a.substr(a.find(':')+2);
            getline(buf,a);
            ac=a.substr(a.find(':')+2);
        }
    };
    const int bufsize=1000;
    //向服务器请求
    class httpsrequest
    {
        private:
        int sock;
        sockaddr_in serv_addr;
        static char s[bufsize],rec[bufsize];
        public:
        ~httpsrequest(){close(sock);}
        httpsrequest(string ip,int _hton)
        {//创建套接字
            int sock=socket(AF_INET,SOCK_STREAM,0);   
            if(sock<0){cerr<<"wrong on get socket";exit(-1);}
            sockaddr_in serv_addr;
            memset(&serv_addr,0,sizeof(serv_addr));
            serv_addr.sin_family=AF_INET;//IPv4
            serv_addr.sin_addr.s_addr=inet_addr(ip.c_str());
            serv_addr.sin_port = htons(_hton);  //端口
        }
        string _request(const string& cmd)//向服务器发送请求，返回服务器的发送信息
        {
            int n=connect(sock,(sockaddr*)&serv_addr,sizeof(serv_addr));
            int x=send(sock,cmd.c_str(),cmd.size()+1,0);//发送信息给服务器
            recv(sock,rec,sizeof(rec),0);//接受服务器信息
            return rec;
        }
    };
    //反向代理（服务器端）
    class httprecv
    {
        private:
        int sock;
        sockaddr_in serv_addr;
        char s[bufsize];
        public:
        httprecv(string ip,int _hton){
            sock=socket(AF_INET,SOCK_STREAM,0);
            serv_addr.sin_family=AF_INET;//IPv4
            serv_addr.sin_addr.s_addr=inet_addr(ip.c_str());
            serv_addr.sin_port = htons(_hton);  //端口
            //将套接字和IP、端口绑定
            bind(sock,(sockaddr*)&serv_addr, sizeof(serv_addr));
            //将套接字与IP地址和端口联系起来
        }
        ~httprecv(){close(sock);}
        void Reverse_proxy(string url)//反向代理，发送服务器代理
        {
            listen(sock,128);
            //监听客户端数据
            int len=sizeof(serv_addr);
            int acsock=accept(sock,(sockaddr*)&serv_addr,(socklen_t*)&len);
            int n=recv(acsock,s,sizeof(s)-1,0);
            //接受从客户端传来的指令
            //发送信息至代理服务器(待完成)
            httpmaker httpmessage;
            httpsrequest sender(ip,_hton);
            httpmessage.host;
            string ans=sender._request(httpmessage.gethttp());
            send(acsock,ans.c_str(),ans.size()+1,0);//回复客户端
            close(acsock);
            
        }
        
    };
}