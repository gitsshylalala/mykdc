/*************************************************************************
	> File Name: msg_corr.h
	> Author: shihongyu
	> Mail: shihongyu@baidu.com
	> Created Time: Wed 27 Mar 2019 02:58:48 PM CST
 ************************************************************************/

#ifndef _MSG_CORR_H_
#define _MSG_CORR_H_

#include <string>

//请求格式：
//{
//    "cmptype"   :int,  0->退出 1->申请 2->提取 3->注册 4->登录
//    "id"        :int,
//    "otherid"   :int,
//    "username"  :std::string,
//    "userpasswd":std::string,
//    "body"      :std::string
//}
//

struct reqmsg {
    int           cmdtype;
    int           id;
    int           otherid;
    std::string   username;
    std::string   userpasswd;
    std::string   body;
public:
    reqmsg()
        :cmdtype(0),
        id(-1),
        otherid(-1),
        username(std::string()),
        userpasswd(std::string()),
        body(std::string())
    {}
};

std::string Reqmsg_encode(const reqmsg& sendbuf);
reqmsg Reqmsg_decode(const std::string& str);

//响应格式：
//{
//    "retbool" :bool,
//    "body"   :std::string
//}

struct resmsg {
    bool        retbool;
    std::string body;
    resmsg()
        :retbool(false),
        body(std::string())
    {}
};

std::string Resmsg_encode(const resmsg& sendbuf);
resmsg Resmsg_decode(const std::string& str);

void message_encrypt(std::string& message, const std::string& key);
bool message_decrypt(std::string& message, const std::string& key);
std::string get_ownkeyFromStr(std::string str_src);

#endif //_MSG_CORR_H_
