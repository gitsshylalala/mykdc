#ifndef _KDC_API_H_
#define _KDC_API_H_
#include <string>
#include "des.h"

class KDCAPI: private Des
{
public:
    KDCAPI() = delete;
    ~KDCAPI();
    KDCAPI(const KDCAPI& csock) = delete;
    KDCAPI& operator=(const KDCAPI& csock) = delete;
public:
    explicit KDCAPI(int id);
    bool Key_Login(const std::string userName, const std::string userPasswd);
    bool Key_Apply(int peerId, std::string& excode);
    bool Key_Get(int peerId, const std::string excode, std::string& commKey);
    bool Key_Cancel(int peerId, const std::string excode);
    bool Des_encrypt(std::string& str_out, std::string str_in, 
                     const std::string& commKey);
    bool Des_decrypt(std::string& str_out, std::string str_in,
                     const std::string& commKey);
    std::string get_errorstr();
private:
    size_t Min_data(size_t num);

private:
    int         _id;
    int         _status;
    std::string _idKey;
    std::string _ownKey;
    std::string _errorstr;
};


#endif //_KDC_API_H_
