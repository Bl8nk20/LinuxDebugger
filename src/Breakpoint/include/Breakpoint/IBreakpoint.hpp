# ifndef IBREAKPOINT
# define IBREAKPOINT

# pragma once

#include <cstdint>
#include <sys/ptrace.h>
#include <sys/wait.h>

namespace LinuxDebugger{

class Breakpoint{
    pid_t m_pid;
    std::intptr_t m_addr;
    bool m_enabled;
    uint8_t m_saved_data;

    public:
    Breakpoint() = default;
    Breakpoint(pid_t pid, std::intptr_t addr);

    void enable();
    void disable();

    auto is_enabled() const -> bool;
    auto get_address() const -> std::intptr_t;
};
}

#endif