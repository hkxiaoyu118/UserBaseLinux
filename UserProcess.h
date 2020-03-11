#ifndef USERBASELINUX_USERPROCESS_H
#define USERBASELINUX_USERPROCESS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

pid_t GetProcessPidByName(const char *procName);   //根据进程名称获取对应进程的ID
std::vector<pid_t> GetAllProcessPidByName(const char *procName);//根据进程名称所有进程ID

#endif //USERBASELINUX_USERPROCESS_H
