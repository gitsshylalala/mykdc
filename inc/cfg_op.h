// cfg_op.h
#ifndef _CFG_OP_H_
#define _CFG_OP_H_ #endif
#include <string>

//��ȡ������
int GetCfgItem(const std::string& FileName, const std::string& Key, 
               std::string& Value);

//д������ 
int WriteCfgItem(const std::string& FileName, const std::string& Key,
                 const std::string& Value);

#endif

