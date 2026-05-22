
#include <sys/personality.h>
#include "Debugger/IDebugger.hpp"

using namespace LinuxDebugger;

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "Program name not specified.";
        return -1;
    }

    auto prog = argv[1];
    auto pid = fork();
    if (pid == 0) {
        //execute debugee
        personality(ADDR_NO_RANDOMIZE);
        ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
        execl(prog, prog, nullptr);
    }
    else if(pid >= 1){
        // parent process
        std::cout << "Started debugging Process. " << pid << std::endl;
        Debugger dbg{prog, pid};
        dbg.run();
    }
}