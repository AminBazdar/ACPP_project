cmake_minimum_required(VERSION 3.0)
project(AP)
set(CMAKE_CXX_STANDARD 11)
add_executable(exe 
    sources/main.cpp 
    sources/hospital.cpp 
    sources/patient.cpp
    sources/doctor.cpp)
include_directories(include)