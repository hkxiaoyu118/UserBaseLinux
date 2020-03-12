#ifndef USERBASELINUX_USERPROCESS_H
#define USERBASELINUX_USERPROCESS_H

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/proc_info.h>
#include <libproc.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>

pid_t GetProcessPidByName(const char *procName); //根据进程名称获取对应进程的ID
std::vector<pid_t> GetAllProcessPidByName(const char *procName); //根据进程名称所有进程ID
std::map<pid_t, std::string> GetAllProcessPidsAndPaths();//获取所有的进程ID和进程全路径
std::string GetProcessNameByPid(pid_t pid);//根据进程ID获取进程名称
bool VerifyCodeSign(const std::string& filePath, const std::string& signString);//根据进程路径和进程的签名关键字验证文件签名合法性
std::map<pid_t, std::string> GetAllProcessInfoByName(const std::string& procName);//获取对应进程名称的所有进程信息
std::string GetProcessPathByPid(pid_t pid);//根据进程ID获取进程的全路径
bool IsSkyGuardRunning();//判断天空卫士是否正常运行
#endif //USERBASELINUX_USERPROCESS_H
