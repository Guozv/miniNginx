#include<bits/stdc++.h>
#include<unistd.h>
#include<arpa/inet.h>
//测试程序
char cmd[]=R"(Request URL: http://localhost/api/v1/healthyRequest
Method: GET

Request Header:
Host: localhost
User-Agent: Mozilla/5.0 (Windows NT 10.0; Wisn64; x64)AppleWebKit/537.36(KHTML,like Gecko)Chrome/77.0.3865.90 Safari/537.36
Accept: */*
)";
int main()
{

    int sock=socket(AF_INET,SOCK_STREAM,0);   
    if(sock<0){return -1;}
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;//IPv4
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8082);  //端口
    int n=connect(sock,(sockaddr*)&serv_addr,sizeof(serv_addr));
    std::cerr<<n<<'\n';
    int x=send(sock,cmd,sizeof(cmd),0);
    puts("成功发送");
    read(sock,cmd,sizeof(cmd));
    puts("成功接受服务端数据:");
    printf("%s",cmd);
    close(sock);
    return 0;
}