# ifndef IDEBUGGER
# define IDEBUGGER

# pragma once

#include <sys/ptrace.h>
#include <sys/wait.h>
#include<vector>
#include <sstream>
#include <iostream>

#include "linenoise.h"

namespace LinuxDebugger{

class Debugger{
    std::string m_prog_name;
    pid_t m_pid;

    public:
    Debugger(std::string prog_name, pid_t pid);

    void run();

    private:
    void handle_command(const std::string& line);
    std::vector<std::string> split(const std::string &s, char delimiter);
    bool is_prefix(const std::string& s, const std::string& of);
    void continue_execution();
    };
}

#endif