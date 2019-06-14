#ifndef _CLI_SOCKET_H_
#define _CLI_SOCKET_H_
#include <string>

class clisocket{
public:
    clisocket(std::string ip, int port);
    ~clisocket();
    clisocket(const clisocket& csock) = delete;
    clisocket& operator=(const clisocket& csock) = delete;
    int get_fd();
private:
    int cli_sockfd;//套接字
};

#endif //_CLI_SOCKET_H_
