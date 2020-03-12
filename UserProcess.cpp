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
    char buf[255] = {0};
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

std::map<pid_t, std::string> GetAllProcessPidsAndPaths()
{
    std::map<pid_t, std::string> result;
    int numberOfProcesses = proc_listpids(PROC_ALL_PIDS, 0, nullptr, 0);
    pid_t pids[numberOfProcesses];
    bzero(pids, sizeof(pids));
    proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (pids[i] == 0)
        {
            continue;
        }

        char pathBuffer[PROC_PIDPATHINFO_MAXSIZE] = {0};
        proc_pidpath(pids[i], pathBuffer, sizeof(pathBuffer));
        if (strlen(pathBuffer) > 0)
        {
            result[pids[i]] = pathBuffer;
        }
    }
    return result;
}

std::string GetProcessNameByPid(pid_t pid)
{
    char processName[NAME_MAX] = {0};
    proc_name(pid, processName, sizeof(processName));
    return processName;
}

bool VerifyCodeSign(const std::string &filePath, const std::string &signString)
{
    bool result = false;
    FILE *fp;
    char buf[2048] = {0};
    char cmd[200] = {0};
    sprintf(cmd, "codesign --display --verbose=4 -r- '%s'", filePath.c_str());
    if ((fp = popen(cmd, "r")) != nullptr)
    {
        while (fgets(buf, 2048, fp) != nullptr)
        {
            std::string cmdResult = buf;
            if (cmdResult.find(signString) != cmdResult.npos)
            {
                result = true;
                break;
            }
        }
        pclose(fp);
    }
    return result;
}

std::map<pid_t, std::string> GetAllProcessInfoByName(const std::string &procName)
{
    std::map<pid_t, std::string> result;
    int numberOfProcesses = proc_listpids(PROC_ALL_PIDS, 0, nullptr, 0);
    pid_t pids[numberOfProcesses];
    bzero(pids, sizeof(pids));
    proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (pids[i] == 0)
        {
            continue;
        }

        std::string processName = GetProcessNameByPid(pids[i]);
        if (processName == procName)
        {
            char pathBuffer[PROC_PIDPATHINFO_MAXSIZE] = {0};
            proc_pidpath(pids[i], pathBuffer, sizeof(pathBuffer));
            if (strlen(pathBuffer) > 0)
            {
                result[pids[i]] = pathBuffer;
            }
        }
    }
    return result;
}

bool IsSkyGuardRunning()
{
    bool result = false;
    std::string procName = "EndpointClientGUI";
    std::string signString = "99U9VSN546";
    auto processes = GetAllProcessInfoByName(procName);
    for (auto &processe : processes)
    {
        if (VerifyCodeSign(processe.second, signString))
        {
            result = true;
            break;
        }
    }
    return result;
}

std::string GetProcessPathByPid(pid_t pid)
{
    std::string result;
    if (pid != -1)
    {
        char pathBuffer[PROC_PIDPATHINFO_MAXSIZE] = {0};
        proc_pidpath(pid, pathBuffer, sizeof(pathBuffer));
        if (strlen(pathBuffer) > 0)
        {
            result = pathBuffer;
        }
    }
    return result;
}