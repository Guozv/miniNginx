#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<arpa/inet.h>
//测试程序
int main()
{
    int sock=socket(AF_INET,SOCK_STREAM,0);   
    if(sock<0){return -1;}
    struct sockaddr_in serv_addr;
    serv_addr.sin_family=AF_INET;//IPv4
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8081);  //端口
    int n=connect(sock,(sockaddr*)&serv_addr,sizeof(serv_addr));
    char cmd[]="132213";
    send(sock,cmd,sizeof(cmd),0);
    puts("成功发送");
    read(sock,cmd,sizeof(cmd));
    puts("成功接受服务端数据:");
  //  printf("%s",s);
    close(sock);
    return 0;
}