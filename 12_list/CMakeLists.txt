cmake_minimum_required(VERSION 4.3)
project(12_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(12_list main.cpp
        Node.h
        List.h
        ArrayList.h
        LinkedList.h
        Data.h)