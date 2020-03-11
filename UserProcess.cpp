#include "UserProcess.h"

pid_t GetProcessPidByName(const char *procName)
{
    FILE *fp;
    char buf[100] = {0};
    char cmd[200] = {0};
    pid_t pid = -1;
    pid_t selfPid = getpid();
    sprintf(cmd, "ps -ef | grep %s | grep -v grep | awk '{print $2}'", procName);
    if ((fp = popen(cmd, "r")) != nullptr)
    {
        while (fgets(buf, 255, fp) != nullptr)
        {
            pid = atoi(buf);
            if (pid != selfPid)
                break;
        }
        pclose(fp);
    }
    return pid;
}

std::vector<pid_t> GetAllProcessPidByName(const char *procName)
{
    FILE *fp;
    char buf[100] = {0};
    char cmd[200] = {0};
    std::vector<pid_t> vtPids;
    pid_t selfPid = getpid();
    sprintf(cmd, "ps -ef | grep %s | grep -v grep | awk '{print $2}'", procName);
    if ((fp = popen(cmd, "r")) != nullptr)
    {
        while (fgets(buf, 255, fp) != nullptr)
        {
            pid_t pid = atoi(buf);
            if (pid != selfPid)
            {
                vtPids.push_back(pid);
            }
        }
        pclose(fp);
    }
    return vtPids;
}