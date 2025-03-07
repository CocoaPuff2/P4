cmake_minimum_required(VERSION 3.10)
project(my_executable)

set(CMAKE_CXX_STANDARD 17)

# Set C++ compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Specify source files explicitly
set(SOURCES driver.cpp
        movie.cpp
        transaction.h)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} movie.h)
