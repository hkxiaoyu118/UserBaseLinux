#include <iostream>
#include "UserProcess.h"
#include <openssl/bio.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

int main()
{
    std::string filePath = "/Library/Application Support/SkyGuard/SkyGuard Endpoint/EndpointAgent/bin/EndpointClientGUI.app";
    std::string signStr = "99U9VSN546";
    if (VerifyCodeSign(filePath, signStr) == true)
    {
        std::cout << "签名验证成功!" << std::endl;
    } else
    {
        std::cout << "签名验证失败!" << std::endl;
    }
    return 0;
}
