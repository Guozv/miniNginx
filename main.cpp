#include<cstdio>
#include<unistd.h>
#include <arpa/inet.h>
#include <http.h>
int main()
{
    http::httprecv answer_("127.0.0.1",8082);
    answer_.Reverse_proxy("127.0.0.1",7000)
    return 0;
}