cmake_minimum_required(VERSION 3.23)
project(PersonnelTrackingSystem)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(PersonnelTrackingSystem main.cpp Personnel.h Personnel.cpp Date.h Date.cpp CircularLinkedList.h CircularLinkedList.cpp CircularDoublyLinkedList.h CircularDoublyLinkedList.cpp)
