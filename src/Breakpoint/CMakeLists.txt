cmake_minimum_required(VERSION 3.14)

project(Breakpoint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(Headers
    include/${PROJECT_NAME}/IBreakpoint.hpp
)

set(Sources
    Breakpoint.cpp
)

add_library(${PROJECT_NAME}
        STATIC
        ${Sources}
        ${Headers}
)

target_include_directories(${PROJECT_NAME} 
        PUBLIC 
        include
)