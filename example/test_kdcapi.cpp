#include <iostream>
#include <unistd.h>
#include "kdc_api.h"

int main()
{
    KDCAPI kdc_api(5);
    //登录
    kdc_api.Key_Login("shihongyu", "s123698745");
    std::string excode;
    std::string commkey;
    //申请
    if(!kdc_api.Key_Apply(8, excode)) {
        std::cout << "申请密钥出错:" << kdc_api.get_errorstr() << std::endl;
        return 0;
    }
    std::cout << "申请密钥成功,申请码:" << excode << std::endl;
    //提取
    if(!kdc_api.Key_Get(8, excode, commkey)) {
        std::cout << "获取密钥出错:" << kdc_api.get_errorstr() << std::endl;
        return 0;
    }

    std::cout << "与8号的共享密钥为" << commkey << std::endl;

    std::string str_in = "\n \
        When I do count the clock that tells the time,\n \
        And see the brave day sunk in hideous night;\n \
        When I behold the violet past prime,\n \
        And sable curls all silver'd o'er with white:\n \
        When lofty trees I see barren of leaves,\n \
        Which erst from heat did canopy the herd,\n \
        And summer's green, all girded up in sheaves,\n \
        Born on the bier with white and bristly beard;\n \
        Then of thy beauty do I question make,\n \
        That thou among the wastes of time must go,\n \
        Since sweets and beauties do themselves forsake,\n \
        And die as fast as they see others grow;\n \
        And nothing 'gainst Time's scythe can make defence\n \
        Save breed, to brave him when he takes thee hence. "; 
    std::cout << "明文是: " << str_in << std::endl;
    std::string str_out;

    if(!kdc_api.Des_encrypt(str_out, str_in, commkey)) {
        std::cout << "DES加密出错:" << kdc_api.get_errorstr() << std::endl;
        return 0;
    }

    std::cout << "加密后的密文是: " << str_out << std::endl;
    std::string str_out_2;

    if(!kdc_api.Des_decrypt(str_out_2, str_out, commkey)) {
        std::cout << "DES解密出错:" << kdc_api.get_errorstr() << std::endl;
        return 0;
    }

    std::cout << "解密后的明文是: " << str_out_2 << std::endl;

    if(!kdc_api.Key_Cancel(8, excode)) {
        std::cout << "注销密钥出错:" << kdc_api.get_errorstr() << std::endl;
        return 0;
    }

    std::cout << "已注销与8号的共享密钥\n";

    return 0;
}

