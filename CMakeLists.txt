cmake_minimum_required(VERSION 3.10)
project(my_executable)

set(CMAKE_CXX_STANDARD 17)

# Set C++ compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Specify source files explicitly
set(SOURCES driver.cpp
        movie.cpp
        transaction.h
        customer.h
        customer.cpp
        transaction.cpp
        comedy.h
        drama.h
        classics.h
        classics.cpp
        drama.cpp
        comedy.cpp
        store.h
        store.cpp
        borrowmedia.h
        returnmedia.h
        bst.cpp
        hashtable.cpp
        borrowmedia.cpp
        returnmedia.cpp
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} movie.h)
