#include <iostream>
#include "UserProcess.h"
#include <openssl/bio.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

int main()
{
//    std::string filePath = "/Library/Application Support/SkyGuard/SkyGuard Endpoint/EndpointAgent/bin/EndpointClientGUI.app";
//    std::string signStr = "99U9VSN546";
//    if (VerifyCodeSign(filePath, signStr) == true)
//    {
//        std::cout << "签名验证成功!" << std::endl;
//    } else
//    {
//        std::cout << "签名验证失败!" << std::endl;
//    }

    pid_t pid = getpid();
    if (pid == -1)
    {
        std::cout << "获取进程ID失败" << std::endl;
        return -1;
    }

    std::string filePath = GetProcessPathByPid(pid);

    std::cout << filePath << std::endl;

//    system("osascript /Users/hkxiaoyu118/src/CodeYuyincun/UserBaseLinux/a.scpt");

//    if (IsSkyGuardRunning())
//    {
//        std::cout << "天空卫士正常运行" << std::endl;
//    } else
//    {
//        std::cout << "天空卫士已经停止" << std::endl;
//    }
    return 0;
}
