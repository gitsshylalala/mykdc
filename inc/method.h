#ifndef _METHOD_H_
#define _METHOD_H_
#include <iostream>
#include "msg_corr.h"

bool regisize(int& id, std::string& user_name);

bool login(int& id, std::string& user_name, 
                  std::string& id_key, std::string& own_key);

void cli_exit(reqmsg& req_send, const int& id, 
                     std::string& id_key, const std::string& own_key);

void cli_applyfor(reqmsg& req_send, const int& id, 
                  std::string& id_key, const std::string& own_key);
void cli_extract(reqmsg& req_send, const int& id, 
                 std::string& id_key, const std::string& own_key);
void cli_cancel(reqmsg& req_send, const int& id,
                       std::string& id_key, const std::string& own_key);
#endif //_METHOD_H_
