# ifndef IDEBUGGER
# define IDEBUGGER

# pragma once

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <iomanip>

#include "linenoise.h"
#include "Breakpoint/IBreakpoint.hpp"
#include "Registers/IRegisters.hpp"

namespace LinuxDebugger{

class Debugger{
    std::string m_prog_name;
    pid_t m_pid;
    std::unordered_map<std::intptr_t, Breakpoint> m_breakpoints;

    public:
    Debugger(std::string prog_name, pid_t pid);

    void run();

    private:
    void handle_command(const std::string& line);
    std::vector<std::string> split(const std::string &s, char delimiter);
    bool is_prefix(const std::string& s, const std::string& of);
    void continue_execution();
    void set_breakpoint_at_address(std::intptr_t addr);
    void dump_registers();

    uint64_t read_memory(uint64_t address);
    void write_memory(uint64_t address, uint64_t value);
    uint64_t get_pc();
    void set_pc(uint64_t pc);

    void step_over_breakpoint();
    void wait_for_signal();
    
};
}

#endif