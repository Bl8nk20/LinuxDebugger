#include "Breakpoint/IBreakpoint.hpp"

using namespace LinuxDebugger;

Breakpoint::Breakpoint(pid_t pid, std::intptr_t addr)
    : m_pid(pid), m_addr(addr), m_enabled(false), m_saved_data(){

}

void Breakpoint::enable(){
    auto data = ptrace(PTRACE_PEEKDATA, m_pid, m_addr, nullptr);
    // saving the bottom byte
    m_saved_data = static_cast<uint8_t>(data & 0xff);

    uint64_t int3 = 0xcc;
    uint64_t data_with_int3 = ((data & ~0xff) | int3);
    ptrace(PTRACE_POKEDATA, m_pid, m_addr, data_with_int3);

    m_enabled = true;
}

void Breakpoint::disable(){
    auto data = ptrace(PTRACE_PEEKDATA, m_pid, m_addr, nullptr);
    auto restored_data = ((data & ~0xff) | m_saved_data);
    ptrace(PTRACE_POKEDATA, m_pid, m_addr, restored_data);

    m_enabled = false;
}

auto Breakpoint::is_enabled() const -> bool{
    return m_enabled;
}
auto Breakpoint::get_address() const -> std::intptr_t{
    return m_addr;
}