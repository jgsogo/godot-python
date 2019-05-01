
cmake_minimum_required(VERSION 3.0)
project(godot-python CXX)

add_executable(executable main.cpp)
target_link_libraries(executable PRIVATE pybind11::pybind11 cpython::cpython mancala)

install(TARGETS executable 
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
