#include <iostream>
#include "UserProcess.h"

int main()
{
    std::vector<pid_t> pids = GetAllProcessPidByName("iTerm2");
    if (pids.size() != 0)
    {
        printf("pid:%d\n", pids[0]);
    } else
    {
        printf("获取进程ID失败\n");
    }
    return 0;
}
