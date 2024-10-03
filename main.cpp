#include<cstdio>
#include<unistd.h>
#include <arpa/inet.h>
#include <http.h>
int main()
{
   http::httprecv a("127.0.0.1",8082);
   a.Reverse_proxy("127.0.0.1",7000,"test.com");
    return 0;
}