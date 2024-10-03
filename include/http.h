#include<unistd.h>
#include<arpa/inet.h>
#include<bits/stdc++.h>
#include<regex>
namespace http
{
    #define DEBUG 
    using namespace std;
    //制造和解码http报文
    class httpmaker
    {
        public:
        string _url,_method,host,user_agent,ac; 
        httpmaker(string _url_,string _method_,string _host,string _user_agent,string _ac):
            _url(_url_),_method(_method_),host(_host),user_agent(_user_agent),ac(_ac){}
        httpmaker(string s){decode(s);}
        string gethttp(){
            string s;
            s="Request URL: ";
            s+=_url;
            s+="\r\n";
            s+="Request Method: ";
            s+=_method;
            s+="\r\n",s+="\r\n";
            s+="Request Header:\r\n";
            s+="Host: ";
            s+=host;s+="\r\n";
            s+="User-Agent: ";
            s+=user_agent,s+="\r\n";
            s+="Accept: ";
            s+=ac,s+="\r\n",s+="\r\n";
            return s;
        }
        void decode(string s)//正则表达式还没学会，理论上应该用 regex_search
        {
            regex match_(R"(Request URL:\s*(http:\/\/(([^:\/\?#]+)(:\d+)?)\/([^\s]+))\r?\nMethod:\s([A-Z]+)\s*Request Header:\r?\nHost:\s(.+)\r?\nUser-Agent:\s*(.+)\r?\nAccept:\s*(.+)\r?\n)");
            smatch res;
            if(!regex_search(s,res,match_)){
                cerr<<"wrong regex format\n";
                exit(-1);
            }
            _url=res[1];
            _method=res[6];
            host=res[7],user_agent=res[8],ac=res[9]; 
            #ifdef DEBUG
            cerr<<gethttp()<<'\n';
            #endif
            
            /*stringstream buf;
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
            ac=a.substr(a.find(':')+2);*/
        }
    };
    const int bufsize=1000;
    //向服务器请求
    class httpsrequest
    {
        private:
        int sock;
        sockaddr_in serv_addr;
        
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
        string _request(string cmd)//向服务器发送请求，返回服务器的发送信息
        {
            int n=connect(sock,(sockaddr*)&serv_addr,sizeof(serv_addr));
            if(n<0){cerr<<"wrong on connect";exit(-1);}
            
            int x=send(sock,cmd.c_str(),cmd.size()+1,0);//发送信息给服务器
            char rec[bufsize];
            recv(sock,rec,sizeof(rec),0);//接受服务器信息
            #ifdef DEBUG
            cerr<<cmd<<'\n';
            cerr<<rec<<'\n';
            #endif
            return rec;
        }
    };
    //反向代理（服务器端）
    class httprecv
    {
        private:
        int sock;
        sockaddr_in serv_addr;
        public:
        httprecv(string ip,int _hton){
            sock=socket(AF_INET,SOCK_STREAM,0);
            if(sock<0){cerr<<"wrong on get socket";exit(-1);}
            serv_addr.sin_family=AF_INET;//IPv4
            serv_addr.sin_addr.s_addr=inet_addr(ip.c_str());
            serv_addr.sin_port = htons(_hton);  //端口
            //将套接字和IP、端口绑定
            bind(sock,(sockaddr*)&serv_addr, sizeof(serv_addr));
            //将套接字与IP地址和端口联系起来
        }
        ~httprecv(){close(sock);}
        void revc()//先接受客户端信息，再根据配置文件分配任务
        {


        }
        void Reverse_proxy(string ip,int _hton,string _host)//反向代理，发送服务器代理
        {
            listen(sock,3);
            //监听客户端数据
            int len=sizeof(serv_addr);
            int acsock=accept(sock,(sockaddr*)&serv_addr,(socklen_t*)&len);
            char s[bufsize];
            int n=recv(acsock,s,sizeof(s)-1,0);
            //接受从客户端传来的指令
            //发送信息至代理服务器(待完成)
            #ifdef DEBUG
           // cerr<<s<<'\n';
            #endif
            httpmaker httpmessage(s);
            httpsrequest sender(ip,_hton);
            regex pt(R"((http?:\/\/)(?:[^:\/\?#]+)(?::\d+)?(\/[^\s]+))");
            smatch res;
            regex_search(httpmessage._url,res,pt);
            httpmessage._url=res[1].str()+ip+":"+to_string(_hton)+res[2].str();
            httpmessage.host=to_string(_hton);
            string ans;
            #ifdef DEBUG
         //   cerr<<httpmessage.gethttp()<<'\n';
            #endif
            ans=sender._request(httpmessage.gethttp());
            # ifdef DEBUG
               // cerr<<httpmessage.gethttp()<<'\n';
                cerr<<ans<<'\n';
            #endif
            send(acsock,ans.c_str(),ans.size()+1,0);//回复客户端
            close(acsock); 
        }
        
    };
}