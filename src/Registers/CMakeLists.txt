cmake_minimum_required(VERSION 3.14)

project(Registers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(Headers
    include/${PROJECT_NAME}/IRegisters.hpp
)

set(Sources
    Registers.cpp
)

add_library(${PROJECT_NAME}
        STATIC
        ${Sources}
        ${Headers}
)

#target_link_libraries(${PROJECT_NAME}
#        PUBLIC
#        Breakpoint
#)  

target_include_directories(${PROJECT_NAME} 
        PUBLIC 
        include 
#        ${CMAKE_BINARY_DIR}/_deps/linenoise-src)
)