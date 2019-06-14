/*************************************************************************
	> File Name: send_and_recv.h
	> Author: shihongyu
	> Mail: shihongyu@baidu.com
	> Created Time: Sat 18 May 2019 01:38:35 PM CST
 ************************************************************************/

#ifndef _SENDANDRECV_H_
#define _SENDANDRECV_H_

#include <string>

int send_msg(int sendfd, std::string& str_all, int str_len);
int recv_msg(int recvfd, std::string& str_all);

#endif //_SENDANDRECV_H_

