#include "Registers/IRegisters.hpp"

using namespace LinuxDebugger;

Registers::Registers(){}

uint64_t Registers::get_register_value(pid_t pid, LinuxDebugger::reg r) {
    user_regs_struct regs;
    ptrace(PTRACE_GETREGS, pid, nullptr, &regs);
    auto it = std::find_if(std::begin(g_register_descriptors), std::end(g_register_descriptors),
                            [r](auto&& rd) { return rd.r == r; });

    return *(reinterpret_cast<uint64_t*>(&regs) + (it - std::begin(g_register_descriptors)));
}

void Registers::set_register_value(pid_t pid, LinuxDebugger::reg r, uint64_t value) {
    user_regs_struct regs;
    ptrace(PTRACE_GETREGS, pid, nullptr, &regs);
    auto it = std::find_if(std::begin(g_register_descriptors), std::end(g_register_descriptors),
                            [r](auto&& rd) { return rd.r == r; });

    *(reinterpret_cast<uint64_t*>(&regs) + (it - std::begin(g_register_descriptors))) = value;
    ptrace(PTRACE_SETREGS, pid, nullptr, &regs);
}

uint64_t Registers::get_register_value_from_dwarf_register (pid_t pid, unsigned regnum) {
    auto it = std::find_if(std::begin(g_register_descriptors), std::end(g_register_descriptors),
                            [regnum](auto&& rd) { return rd.dwarf_r == regnum; });
    if (it == std::end(g_register_descriptors)) {
        throw std::out_of_range{"Unknown dwarf register"};
    }

    return get_register_value(pid, it->r);
}

std::string Registers::get_register_name(LinuxDebugger::reg r) {
    auto it = std::find_if(std::begin(g_register_descriptors), std::end(g_register_descriptors),
                            [r](auto&& rd) { return rd.r == r; });
    return it->name;
}

LinuxDebugger::reg Registers::get_register_from_name(const std::string& name) {
    auto it = std::find_if(std::begin(g_register_descriptors), std::end(g_register_descriptors),
                            [name](auto&& rd) { return rd.name == name; });
    return it->r;
}